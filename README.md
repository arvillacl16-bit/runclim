# Runclim
[![Tip via Stripe](https://img.shields.shields.shields.shields.shields.io/badge/Donate-Stripe-purple?style=for-the-badge&logo=stripe)](https://buy.stripe.com/3cI00jaDb5yjgmd5WZgfu00)
Runclim runs ExoPlaSim, a GCM, on the cloud, and also has analysis tools through a simple GUI interface. This is intended for use with worldbuilders.

## Interface Preview (In Progress)

Below is the current layout of the simulation and analysis dashboard:

![Runclim dashboard layout](https://raw.githubusercontent.com/arvillacl16-bit/runclim/main/screenshot.png)

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

