# Runclim

Runclim runs ExoPlaSim, a GCM, on the cloud, and also has analysis tools through a simple GUI interface. This is intended for use with worldbuilders.

## Support Development

We are currently tranistioning our donation infrastructure directly to stripe.

* **Status:** Integration in progress
* **Payment Processing:** Direct Stripe integration will initialize as soon as account verification is finalized.

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

