# Runclim

Runclim runs ExoPlaSim, a GCM, on the cloud, and also has analysis tools. This is intended for use with worldbuilders.

## Dependencies

- Meson (for building)
- C++20 (no need for module support)
- wxWidgets
- Eigen
- libnetcdf

## Building

Clone the repository:

```sh
git clone https://github.com/arvillacl16-bit/runclim
cd runclim
```

Now run:

```sh
meson setup builddir --buildtype=release
meson compile -C builddir
```

The executable should be located at ./builddir/runclim.

