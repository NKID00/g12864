/**
 * Licensed under MIT License.
 * SPDX-License-Identifier: MIT
 * Copyright © 2021 NKID00
 */

#ifndef __G_G12864_H__
#define __G_G12864_H__

#include <gpiod.h>
#include <stdbool.h>
#include <stdint.h>

#define G_SCREEN_WIDTH 128
#define G_SCREEN_HEIGHT 64

#define G_BL_ON 1
#define G_BL_OFF 0

/**
 * @brief Frame buffer
 */
struct g_fb;

/**
 * @brief Screen
 */
struct g_sc;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
 * @brief Create a frame buffer. (Warning: Disused frame buffers should be destroyed using g_fb_destroy.)
 */
    struct g_fb *
    g_fb_create();

    /**
 * @brief Destroy a frame buffer.
 */
    void g_fb_destroy(struct g_fb *fb);

    /**
 * @brief Get the pixel of the given position on the frame buffer.
 */
    bool g_fb_get_pixel(struct g_fb *fb, int x, int y);

    /**
 * @brief Set the pixel of the given position on the frame buffer.
 */
    void g_fb_set_pixel(struct g_fb *fb, int x, int y, bool value);

    /**
 * @brief Copy and create a new frame buffer. (Warning: Disused frame buffers should be destroyed using g_fb_destroy.)
 */
    struct g_fb *
    g_fb_copy(struct g_fb *fb_src);

    /**
 * @brief Fill the frame buffer with one value.
 */
    void g_fb_fill(struct g_fb *fb, bool value);

    /**
 * @brief Draw a rectangle on the frame buffer.
 */
    void g_fb_draw_rect(struct g_fb *fb, int x0, int y0, int x1, int y1, bool value);

    /**
 * @brief Draw a character on the frame buffer.
 */
    void g_fb_draw_char(struct g_fb *fb, int x, int y, wchar_t ch, bool value, uint8_t *font);

    /**
 * @brief Draw a string on the frame buffer.
 */
    void g_fb_draw_text(struct g_fb *fb, int x, int y, const wchar_t *text, bool value, uint8_t *font);

    /**
 * @brief Create a screen. (Warning: Disused screens should be destroyed using g_sc_destroy.)
 */
    struct g_sc *
    g_sc_create(struct gpiod_line *sid,
                struct gpiod_line *sclk,
                struct gpiod_line *bla);

    /**
 * @brief Destroy a screen.
 */
    void g_sc_destroy(struct g_sc *sc);

    /**
 * @brief Get the frame buffer of the screen.
 */
    struct g_fb *
    g_sc_get_fb(struct g_sc *sc);

    /**
 * @brief Configure the value of the backlight immediately.
 */
    void g_sc_set_bl(struct g_sc *sc, int value);

    /**
 * @brief Refresh the screen. (Only refresh the changed part of the screen)
 */
    void g_sc_refresh(struct g_sc *sc);

    /**
 * @brief Force refresh the screen. (refresh the whole screen)
 */
    void g_sc_refresh_force(struct g_sc *sc);

#ifdef __cplusplus
}
#endif

#endif /* __G_G12864_H__ */