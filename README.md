# Runclim

Runclim runs ExoPlaSim, a GCM, on the cloud, and also has analysis tools through a simple GUI interface. This is intended for use with worldbuilders.

## Support Development

We are currently tranistioning our donation infrastructure directly to stripe.

* **Status:** Integration in progress
* **Payment Processing:** Direct Stripe integration will initialize as soon as account verification is finalized.

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

