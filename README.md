## g12864

> Computer graphics library for 128x64 LCDs (ST7920 controller).

```c
/* turn on the backlight immediately */
g_sc_set_bl(sc, G_BL_ON);

/* draw a 20x20 rectangle */
g_fb_draw_rect(g_sc_get_fb(sc), 10, 10, 29, 29, 1);

/* refresh the screen */
g_sc_refresh(sc);
```

Easy, fast and more.

## Easy

There's no need to care about the screen at all. Just draw things on the frame buffer and ask g12864 to refresh the screen for you. Building g12864 is the same easy since it only relies on [libgpiod](https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/).

## Fast

Thanks to libgpiod, g12864 runs so fast that refreshing the whole screen on a 1GHz single-core Raspberry Pi Zero takes less than 0.5 seconds. Moreover, g12864 won't refresh the whole screen at most of the time - it has the ability to refresh only the changed part of the screen.

## Copyright

Licensed under MIT License.

Copyright © 2021 NKID00
