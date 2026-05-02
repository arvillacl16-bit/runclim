from PIL import Image
import numpy as np
from scipy.ndimage import gaussian_filter, zoom
import xarray as xr
from typing import Optional
import numpy.typing as npt
from math import ceil

def load_grayscale_image(path: str) -> npt.NDArray[np.float32]:
    Image.MAX_IMAGE_PIXELS = None
    img = Image.open(path).convert("L")
    new_img_width = int(ceil(img.width / 64) * 64)
    new_img_height = new_img_width // 2
    img = img.resize((new_img_width, new_img_height))

    arr = np.array(img)

    if arr.dtype == np.uint8:
        arr = arr.astype(np.float32) / 255.0
    elif arr.dtype == np.uint16:
        arr = arr.astype(np.float32) / 65535.0
    else:
        arr = arr.astype(np.float32)
        arr = (arr - arr.min()) / (arr.max() - arr.min())

    return arr

def image_to_dem(
        image_path: str,
        output_path: str,
        max_elevation: float,
        min_elevation: float = 0.,
        planet_radius: float = 6371.,
        target_width: Optional[int] = None,
        smooth_sigma: float = 1.
):
    """
    Converts a black-and-white image to a high-resolution DEM with optional smoothing,
    upsampling and slope computation.

    Parameters:
    - image_path: path to grayscale image (black=low, white=high)
    - output_path: path to save output .nc file
    - max_elevation: maximum elevation (meters)
    - min_elevation: minimum elevation (meters)
    - planet_radius: radius of planet
    - target_width: width for upsampling, or None to keep original
    - smooth_sigma: Gaussian smoothing sigma
    """
    height_normalized = load_grayscale_image(image_path)
    dem = min_elevation + height_normalized * (max_elevation - min_elevation)
    dem = np.flipud(dem)
    if smooth_sigma > 0:
        dem = gaussian_filter(dem, sigma=smooth_sigma)
    
    if target_width is not None:
        target_width = ceil(target_width / 64) * 64
        target_shape = (target_width, target_width // 2)

        zoom_factors = (target_shape[0]/dem.shape[0], target_shape[1]/dem.shape[1])
        dem = zoom(dem, zoom_factors, order=1)
    
    lat = np.linspace(-90.0, 90.0, dem.shape[0])
    lon = np.linspace(-180.0, 180.0, dem.shape[1])

    lat_rad = np.deg2rad(lat)
    dlat = np.deg2rad(lat[1] - lat[0])
    dlon = np.deg2rad(lon[1] - lon[0])

    dy = 1000 * planet_radius * dlat
    dx = 1000 * planet_radius * dlon * np.cos(lat_rad)

    slope_y = np.gradient(dem, dy, axis=0)
    slope_x = np.gradient(dem, axis=1) / dx[:, None]
    slope_x = np.clip(slope_x, -1.0, 1.0)

    ds = xr.Dataset({
        "elevation": (("lat", "lon"), dem),
        "slope_x": (("lat", "lon"), slope_x),
        "slope_y": (("lat", "lon"), slope_y)
    }, coords={
        "lat": lat,
        "lon": lon
    })

    ds.to_netcdf(output_path)
    print(f"DEM saved to {output_path} with shape {dem.shape}")

