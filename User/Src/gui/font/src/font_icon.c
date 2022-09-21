/*******************************************************************************
 * Size: 48 px
 * Bpp: 4
 * Opts: --font asserts/font/MaterialIconsOutlined-Regular.otf --symbols  --lcd --size 48 --bpp 4 --lv-include lvgl.h --format lvgl -o User/Src/gui/font/src/font_icon.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef FONT_ICON
#define FONT_ICON 1
#endif

#if FONT_ICON

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E002 "" */
    0x0, 0xff, 0xfb, 0xa3, 0xb9, 0x0, 0x3f, 0xff,
    0xe0, 0x1f, 0xfe, 0xd3, 0x89, 0x88, 0x4c, 0x18,
    0x7, 0xff, 0xfc, 0x3, 0xff, 0xd2, 0x4d, 0xee,
    0x40, 0x2, 0x7f, 0x62, 0x0, 0xff, 0xff, 0x80,
    0x7f, 0xf9, 0x45, 0x62, 0x6, 0x1, 0xe3, 0x88,
    0x28, 0x80, 0x7f, 0xff, 0xc0, 0x3f, 0xfc, 0x49,
    0x16, 0xa2, 0x1, 0xf8, 0x56, 0xe1, 0x0, 0x3f,
    0xff, 0xe0, 0x1f, 0xfd, 0xf2, 0x89, 0x61, 0x0,
    0xff, 0xe0, 0xb, 0x4b, 0x90, 0x7, 0xff, 0xfc,
    0x3, 0xff, 0xb6, 0x2d, 0xce, 0x40, 0x1f, 0xfc,
    0x42, 0x89, 0x61, 0x0, 0xff, 0xff, 0x80, 0x7f,
    0xf5, 0xc5, 0x6e, 0xc, 0x3, 0xff, 0x90, 0x91,
    0x6a, 0x20, 0x1f, 0xff, 0xf0, 0xf, 0xfe, 0xa1,
    0xc5, 0xa8, 0x80, 0x7f, 0xf2, 0x85, 0x6e, 0xc,
    0x3, 0xff, 0xfe, 0x1, 0xff, 0xd1, 0x27, 0xe6,
    0x10, 0xf, 0xfe, 0x70, 0xb7, 0xb9, 0x0, 0x7f,
    0xff, 0xc0, 0x3f, 0xf9, 0xa2, 0xd3, 0x4, 0x1,
    0xff, 0xd2, 0x38, 0x96, 0x10, 0xf, 0xff, 0xf8,
    0x7, 0xff, 0x24, 0x56, 0xe1, 0x0, 0x3f, 0xfa,
    0xc9, 0x16, 0xa2, 0x1, 0xff, 0xff, 0x0, 0xff,
    0xe3, 0x1c, 0x41, 0x44, 0x3, 0xff, 0xb0, 0x2b,
    0x12, 0x60, 0x1f, 0xff, 0xf0, 0xf, 0xfe, 0x19,
    0x3f, 0xb1, 0x0, 0x7f, 0xf7, 0x9, 0xfd, 0xc8,
    0x3, 0xff, 0xfe, 0x1, 0xff, 0xb, 0x4c, 0x18,
    0x7, 0xff, 0x80, 0xe2, 0x58, 0x40, 0x3f, 0xff,
    0xe0, 0x1f, 0x92, 0xe1, 0x0, 0x3f, 0xfc, 0x89,
    0x16, 0x80, 0x1f, 0xff, 0xf0, 0xe, 0x38, 0x95,
    0x10, 0xf, 0xfe, 0x32, 0x57, 0xff, 0xfa, 0x90,
    0x3, 0xff, 0x8c, 0x2b, 0x30, 0x60, 0x1f, 0xff,
    0xf0, 0x27, 0xf7, 0x20, 0xf, 0xff, 0x51, 0x3f,
    0xb9, 0x0, 0x7f, 0xff, 0x5, 0xa6, 0xc, 0x3,
    0xff, 0xdc, 0x71, 0x2c, 0x20, 0x1f, 0xff, 0x94,
    0xb8, 0x40, 0xf, 0xff, 0x92, 0x44, 0x10, 0x3,
    0xff, 0xec, 0x71, 0x2a, 0x20, 0x1f, 0xff, 0x41,
    0x69, 0x83, 0x0, 0xff, 0xf9, 0x13, 0xfb, 0x90,
    0x7, 0xff, 0xe0, 0x9f, 0xdc, 0x80, 0x3f, 0xfd,
    0xc2, 0xb3, 0x6, 0x1, 0xff, 0xfc, 0x38, 0x95,
    0x10, 0xf, 0xff, 0x5a, 0x45, 0xa0, 0x7, 0xff,
    0xfc, 0x12, 0xe1, 0x0, 0x3f, 0xfd, 0x7, 0x12,
    0xc2, 0x1, 0xff, 0xd4, 0x4a, 0xff, 0xff, 0x52,
    0x0, 0x7f, 0xf5, 0x5, 0xa6, 0xc, 0x3, 0xff,
    0xc8, 0x4f, 0xee, 0x40, 0x1f, 0xff, 0xf0, 0xf,
    0x89, 0xfd, 0xc8, 0x3, 0xff, 0xc0, 0x2b, 0x30,
    0x60, 0x1f, 0xff, 0xf0, 0xf, 0xf8, 0xe2, 0xa,
    0x20, 0x1f, 0xfd, 0xd4, 0x8b, 0x40, 0xf, 0xff,
    0xf8, 0x7, 0xff, 0xd, 0x6e, 0x10, 0x3, 0xff,
    0xb4, 0x71, 0x2c, 0x20, 0x1f, 0xfd, 0xb4, 0xaf,
    0xff, 0xf5, 0x20, 0x7, 0xff, 0x6c, 0x5a, 0x60,
    0xc0, 0x3f, 0xfa, 0xc4, 0xde, 0xe4, 0x1, 0xff,
    0xff, 0x0, 0xff, 0xe4, 0x93, 0xfb, 0x10, 0x7,
    0xff, 0x48, 0x56, 0x20, 0x60, 0x1f, 0xff, 0xf0,
    0xf, 0xfe, 0x69, 0xc4, 0x14, 0x40, 0x3f, 0xf9,
    0xe9, 0x16, 0xa2, 0x1, 0xff, 0xff, 0x0, 0xff,
    0xe7, 0x8a, 0xdc, 0x20, 0x7, 0xff, 0x30, 0xa2,
    0x58, 0x40, 0x3f, 0xfc, 0x49, 0x5f, 0xff, 0xea,
    0x40, 0xf, 0xff, 0x10, 0xb4, 0xc1, 0x0, 0x7f,
    0xf2, 0x9, 0xa5, 0xc8, 0x3, 0xff, 0xfe, 0x1,
    0xff, 0xd7, 0x27, 0x96, 0x10, 0xf, 0xfe, 0x20,
    0xac, 0x41, 0x0, 0x3f, 0xff, 0xe0, 0x1f, 0xfd,
    0xb4, 0x8b, 0x51, 0x0, 0xff, 0xe0, 0xa4, 0x5a,
    0x88, 0x7, 0xff, 0xfc, 0x3, 0xff, 0xba, 0x2b,
    0x10, 0x40, 0xf, 0xf1, 0x3c, 0xb0, 0x80, 0x7f,
    0xff, 0xc0, 0x3f, 0xfc, 0x24, 0xd2, 0xe4, 0x1,
    0xe1, 0x69, 0x82, 0x0, 0xff, 0xff, 0x80, 0x7f,
    0xf9, 0x4a, 0x25, 0x84, 0x0,

    /* U+E004 "" */
    0x0, 0xff, 0xf3, 0x12, 0xc5, 0xef, 0x7f, 0xbb,
    0x6e, 0x14, 0x80, 0x3f, 0xff, 0xe0, 0x1f, 0xfc,
    0xb3, 0x8f, 0xa7, 0x42, 0x10, 0x0, 0x92, 0x3d,
    0x7c, 0x18, 0x7, 0xff, 0xfc, 0x3, 0xff, 0x90,
    0x74, 0xc4, 0x1, 0xff, 0xc0, 0x26, 0xa3, 0x0,
    0xff, 0xff, 0x80, 0x7f, 0xf1, 0xd8, 0xc4, 0x3,
    0xff, 0x84, 0x26, 0xc0, 0x1f, 0xff, 0xf0, 0xf,
    0xff, 0xf8, 0x7, 0xff, 0xa4, 0x4d, 0x1a, 0x39,
    0xc0, 0x3f, 0xf8, 0x8f, 0xd0, 0xc8, 0x62, 0x1,
    0xff, 0xff, 0x0, 0x9, 0x2c, 0x56, 0xff, 0x65,
    0xcb, 0xa1, 0x0, 0x7f, 0xf1, 0x9, 0x1e, 0x6f,
    0x3b, 0xf6, 0xa1, 0x48, 0x40, 0x3f, 0xfe, 0xc4,
    0xb3, 0x9f, 0xb4, 0xea, 0x40, 0x1f, 0xfd, 0x42,
    0x57, 0xad, 0xfc, 0x94, 0x20, 0xf, 0xff, 0x70,
    0xa4, 0x66, 0xd3, 0x18, 0x80, 0x7f, 0xf7, 0x84,
    0xda, 0xf3, 0x10, 0x82, 0x1, 0xff, 0xe7, 0x14,
    0x8c, 0xb7, 0x30, 0xf, 0xfe, 0x8, 0x9a, 0xb4,
    0x55, 0xe6, 0xf7, 0x3f, 0xf7, 0x73, 0x72, 0xea,
    0x19, 0x4c, 0x40, 0x3f, 0xf8, 0x2, 0x6f, 0x79,
    0x6, 0x20, 0x1f, 0xfe, 0x22, 0x6a, 0xb7, 0x20,
    0xf, 0xf8, 0x96, 0x2f, 0x7b, 0x2a, 0x5d, 0x50,
    0xc8, 0x44, 0x1, 0x84, 0x44, 0x68, 0xaf, 0x35,
    0x9d, 0xb7, 0xa, 0x40, 0x1f, 0xf1, 0x3e, 0x53,
    0x10, 0x7, 0xff, 0x78, 0x9b, 0xa5, 0x0, 0x3f,
    0xc2, 0x91, 0x9b, 0x4e, 0x84, 0x1, 0xff, 0xce,
    0x24, 0x7a, 0xdc, 0x84, 0x10, 0xf, 0xf2, 0x4c,
    0x98, 0x80, 0x3f, 0xfb, 0x42, 0xb1, 0x26, 0x1,
    0xfe, 0x38, 0xcb, 0x73, 0x0, 0xff, 0xec, 0x1b,
    0xde, 0x41, 0x80, 0x7f, 0x92, 0x61, 0x44, 0x3,
    0xff, 0xae, 0x4d, 0x2a, 0x1, 0xfc, 0x2b, 0x5a,
    0xe4, 0x1, 0xff, 0xc2, 0x49, 0xff, 0xff, 0x4a,
    0x0, 0x7f, 0xf0, 0x89, 0xf6, 0x94, 0x40, 0x3f,
    0x96, 0x58, 0x80, 0x3f, 0xfa, 0xa7, 0x52, 0x60,
    0x1f, 0xc7, 0x10, 0x51, 0x0, 0xff, 0xe2, 0x98,
    0x7, 0xf8, 0xc0, 0x3f, 0xf8, 0xa2, 0xb1, 0x3,
    0x0, 0xfe, 0x3a, 0xa1, 0x80, 0x7f, 0xf4, 0xc9,
    0x10, 0x20, 0x1f, 0xcb, 0x2c, 0x40, 0x1f, 0xfe,
    0x62, 0x69, 0x50, 0xf, 0xe2, 0x44, 0x10, 0x7,
    0xff, 0x49, 0x30, 0xc0, 0x3f, 0x97, 0xd4, 0x3,
    0xff, 0xd4, 0xbe, 0xa0, 0x1f, 0xc7, 0x88, 0x1,
    0xff, 0xd1, 0x2e, 0x60, 0xf, 0xe3, 0xd4, 0x0,
    0xff, 0xf6, 0x3e, 0x98, 0x7, 0xf3, 0x71, 0x0,
    0x7f, 0xf4, 0x18, 0x4c, 0x3, 0xf9, 0xc8, 0x40,
    0x3f, 0xfd, 0x84, 0x47, 0x0, 0xfe, 0x31, 0x10,
    0x7, 0xff, 0x44, 0xc4, 0x3, 0xf8, 0x44, 0x1,
    0xff, 0xee, 0x11, 0x0, 0x7f, 0x9, 0xb8, 0x7,
    0xff, 0xfc, 0x3, 0xff, 0xfe, 0x1, 0xff, 0xd0,
    0x4a, 0xff, 0xff, 0x52, 0x0, 0x7f, 0xff, 0xc0,
    0x3f, 0xff, 0xe0, 0x1f, 0xff, 0xf0, 0xf, 0xff,
    0xf8, 0x7, 0xff, 0xfc, 0x3, 0xff, 0xee, 0x93,
    0xff, 0xfe, 0x94, 0x0, 0xff, 0xff, 0x80, 0x7f,
    0xf3, 0x8c, 0x3, 0xfc, 0x60, 0x1f, 0xff, 0xf0,
    0xf, 0xff, 0xf8, 0x7, 0xff, 0xd8, 0xc0, 0x3f,
    0xc6, 0x1, 0xff, 0xff, 0x0, 0xff, 0xe7, 0x24,
    0xff, 0xff, 0xa5, 0x0, 0x3f, 0xff, 0xe0, 0x1f,
    0xff, 0xf0, 0xf, 0xfe, 0x71, 0xbf, 0xa0, 0x7,
    0xff, 0xfc, 0x3, 0xe4, 0xf7, 0x30, 0xf, 0xfe,
    0x49, 0xbe, 0x6c, 0x20, 0x80, 0x7f, 0xff, 0xc0,
    0x3e, 0x14, 0x8d, 0xc7, 0x30, 0xf, 0xfe, 0x19,
    0xbe, 0x62, 0xc, 0x40, 0x3f, 0xf8, 0x2b, 0x7f,
    0xff, 0xfe, 0xeb, 0x50, 0xf, 0xfe, 0x8, 0x9c,
    0x66, 0x1c, 0xc0, 0x3f, 0x9, 0xc6, 0x62, 0xc,
    0x3, 0xff, 0xfe, 0x1, 0xff, 0xc9, 0x38, 0xcc,
    0x41, 0x88, 0x6, 0x49, 0x73, 0x0, 0xff, 0xff,
    0x80, 0x7f, 0xf3, 0xcd, 0xe5, 0x0, 0x3f, 0xff,
    0xe0, 0x1f, 0xfd, 0xf5, 0xaf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x4e, 0x94, 0x3, 0xff, 0xfe, 0x1,
    0xff, 0xff, 0x0, 0xff, 0x14, 0x6f, 0xff, 0xff,
    0x23, 0x60, 0x80, 0x3f, 0xff, 0xe0, 0x1f, 0xfc,
    0x12, 0xc4, 0x10, 0xf, 0xfe, 0x30, 0xa6, 0x10,
    0x7, 0xff, 0xfc, 0x3, 0xff, 0x84, 0x91, 0x6a,
    0x20, 0x1f, 0xfc, 0x21, 0x5b, 0x84, 0x0, 0xff,
    0xff, 0x80, 0x7f, 0xf1, 0x5, 0x6b, 0xed, 0xd4,
    0xc8, 0x40, 0x2, 0x46, 0xaf, 0x7f, 0x4a, 0x20,
    0x1f, 0xff, 0xf0, 0xf, 0xfe, 0x40, 0xa4, 0x56,
    0x6f, 0x7f, 0xbb, 0x72, 0xa1, 0x4, 0x3, 0xff,
    0xca,

    /* U+E54F "" */
    0x0, 0x2d, 0x7f, 0xff, 0xf7, 0xfb, 0x75, 0x98,
    0xb9, 0x86, 0x43, 0x10, 0xf, 0xff, 0xe0, 0x91,
    0xc, 0xc8, 0xcf, 0x37, 0x9d, 0xcc, 0x96, 0x31,
    0x0, 0xff, 0xff, 0x80, 0x42, 0x6d, 0x39, 0xd9,
    0x8, 0x20, 0x1f, 0xff, 0xf0, 0xe, 0x37, 0xbf,
    0xb6, 0x20, 0xf, 0xff, 0xf8, 0x7, 0xa, 0x4f,
    0xca, 0x8, 0x7, 0xff, 0xfc, 0x3, 0x89, 0xae,
    0x94, 0x40, 0x3f, 0xff, 0xe0, 0x1e, 0x4b, 0x84,
    0x0, 0xff, 0xff, 0x80, 0x78, 0x5b, 0xd8, 0x40,
    0x3f, 0xfa, 0x4b, 0x7f, 0xff, 0xfc, 0x8d, 0xcb,
    0x85, 0x20, 0xf, 0xfe, 0x5a, 0x6b, 0x88, 0x7,
    0xff, 0x9c, 0x8d, 0x1e, 0xb6, 0xd8, 0x80, 0x3f,
    0xf9, 0x29, 0x88, 0x1, 0xff, 0xed, 0x49, 0x92,
    0x88, 0x7, 0xff, 0x21, 0xc8, 0x80, 0x1f, 0xfe,
    0xe4, 0xc5, 0x0, 0xff, 0xe4, 0x1f, 0x8, 0x7,
    0xff, 0xfc, 0x3, 0xff, 0xee, 0x98, 0xa0, 0x1f,
    0xfc, 0x83, 0xe1, 0x0, 0xff, 0xf6, 0x24, 0xc9,
    0x44, 0x3, 0xff, 0x90, 0xe4, 0x40, 0xf, 0xff,
    0x30, 0x9a, 0x3d, 0x6d, 0xb1, 0x0, 0x7f, 0xf2,
    0x53, 0x10, 0x3, 0xff, 0xa2, 0xb7, 0xff, 0xff,
    0xc8, 0xec, 0xb8, 0x52, 0x0, 0xff, 0xe5, 0xa6,
    0xb8, 0x80, 0x7f, 0xff, 0xc0, 0x21, 0x6f, 0x61,
    0x0, 0xff, 0xff, 0x80, 0x49, 0x70, 0x80, 0x1f,
    0xff, 0xf0, 0x1, 0x35, 0xd2, 0x88, 0x7, 0xff,
    0xfc, 0x52, 0x7e, 0x50, 0x40, 0x3f, 0xff, 0xc6,
    0xf7, 0xf6, 0xc4, 0x1, 0xff, 0xfb, 0x13, 0x69,
    0xce, 0xc8, 0x41, 0x0, 0xff, 0xf9, 0x8, 0x88,
    0x86, 0x8a, 0xf3, 0x59, 0xdc, 0xc9, 0x63, 0x10,
    0xf, 0xff, 0xa, 0xdf, 0xff, 0xff, 0x1f, 0xb9,
    0xba, 0xcb, 0xa8, 0x65, 0x31, 0x0, 0xff, 0xff,
    0x80, 0x7f, 0xff, 0xc0, 0x3f, 0xff, 0xe0, 0x1f,
    0xff, 0xf0, 0xf, 0xff, 0xf8, 0x7, 0xff, 0xfc,
    0x3, 0xff, 0xfe, 0x1, 0xff, 0xff, 0x0, 0xff,
    0xff, 0x80, 0x7f, 0xff, 0xc0, 0x3f, 0xff, 0xe0,
    0x1f, 0xff, 0xf0, 0xf, 0xff, 0x28,

    /* U+E572 "" */
    0x0, 0xff, 0xee, 0xa, 0x3d, 0x66, 0xf7, 0xfb,
    0xb7, 0x29, 0xd0, 0x40, 0x3f, 0xff, 0xe0, 0x1f,
    0xfd, 0x41, 0x5b, 0xfb, 0x85, 0x32, 0x10, 0x0,
    0x91, 0xac, 0x5f, 0xd2, 0x88, 0x7, 0xff, 0xfc,
    0x3, 0xff, 0xa0, 0xb7, 0x48, 0x20, 0x1f, 0xfc,
    0x21, 0x5b, 0x84, 0x0, 0xff, 0xff, 0x80, 0x7f,
    0xf3, 0x8f, 0x10, 0x3, 0xff, 0x8e, 0x29, 0x86,
    0x1, 0xff, 0xff, 0x0, 0xff, 0xff, 0x80, 0x7f,
    0xff, 0xc0, 0xf1, 0x0, 0x3f, 0xf8, 0xe2, 0x98,
    0x60, 0x1f, 0xff, 0xf0, 0xf, 0xfe, 0x72, 0xdd,
    0x20, 0x80, 0x7f, 0xf0, 0x85, 0x6e, 0x10, 0x3,
    0xff, 0xfe, 0x1, 0xff, 0xd0, 0x15, 0xbf, 0xb8,
    0x64, 0x32, 0x11, 0x11, 0xa3, 0x46, 0x7d, 0x28,
    0x80, 0x7f, 0xff, 0xc0, 0x3f, 0xfa, 0x82, 0x8f,
    0x37, 0x9b, 0xdc, 0xdc, 0xb9, 0x73, 0x10, 0xf,
    0xff, 0xf8, 0x7, 0xff, 0x34, 0x91, 0xa6, 0xb3,
    0x7b, 0xfb, 0x99, 0x75, 0x8, 0x20, 0x1f, 0xff,
    0xf0, 0xf, 0xfe, 0x70, 0x9a, 0xbc, 0xde, 0xfe,
    0xdc, 0xb2, 0x99, 0x8, 0x8, 0x8d, 0x15, 0xef,
    0xe9, 0x48, 0x3, 0xff, 0xfe, 0x1, 0xff, 0xc4,
    0x13, 0x58, 0xac, 0xee, 0x65, 0x43, 0x21, 0x0,
    0x7f, 0xf1, 0x45, 0x6b, 0x9c, 0x80, 0x3f, 0xff,
    0xe0, 0x1f, 0x12, 0x34, 0x5e, 0xf7, 0x32, 0x9d,
    0x4c, 0x40, 0x3f, 0xf9, 0xe7, 0x12, 0xa2, 0x1,
    0xff, 0xfe, 0x25, 0x9b, 0xdf, 0xdb, 0x97, 0x42,
    0x10, 0xf, 0xfe, 0xc2, 0x5c, 0x20, 0x7, 0xff,
    0xf5, 0xbd, 0x90, 0x80, 0x3f, 0xfc, 0x22, 0xd5,
    0x44, 0x10, 0xf, 0xff, 0xf8, 0x7, 0xf8, 0x4d,
    0x5e, 0x73, 0xa9, 0x84, 0x3, 0xff, 0x9e, 0x2b,
    0x74, 0xc4, 0x1, 0xff, 0xff, 0x0, 0xe4, 0x9e,
    0xe6, 0x54, 0x31, 0x98, 0x94, 0x40, 0x3f, 0xfa,
    0x49, 0x39, 0x6e, 0x62, 0x1, 0xff, 0xff, 0x1,
    0x21, 0x0, 0xf3, 0xe9, 0x80, 0x7f, 0xf5, 0x45,
    0x23, 0x3e, 0xdd, 0x8, 0x3, 0xff, 0xfe, 0x1,
    0xc7, 0xae, 0x1, 0xff, 0xca, 0x59, 0xb7, 0x30,
    0xf, 0xf8, 0x52, 0x2f, 0x7b, 0x6e, 0x19, 0x50,
    0xc8, 0x82, 0x1, 0xff, 0xf8, 0x15, 0x32, 0x0,
    0xff, 0xe4, 0x9e, 0xba, 0x46, 0xe3, 0x98, 0x7,
    0xff, 0x4, 0x49, 0x1e, 0x6a, 0xf3, 0x75, 0xdf,
    0x4a, 0x1, 0xff, 0xf5, 0x5f, 0x50, 0xf, 0xfe,
    0x48, 0xaa, 0x8, 0x0, 0x4e, 0x33, 0x69, 0xd0,
    0x40, 0x3f, 0xff, 0xe0, 0x1f, 0xf0, 0x9a, 0x88,
    0x7, 0xff, 0x25, 0x70, 0xc0, 0x3e, 0x25, 0x8b,
    0xed, 0xa7, 0x43, 0x10, 0xf, 0xff, 0x99, 0x80,
    0x7f, 0x8c, 0x3, 0x93, 0x4c, 0x3, 0xff, 0x92,
    0x58, 0xe0, 0x1f, 0xfc, 0x12, 0x58, 0xbc, 0xee,
    0x6d, 0xcb, 0xb2, 0xa2, 0xc, 0xc4, 0x22, 0x1,
    0x0, 0xff, 0xf1, 0x24, 0xff, 0xff, 0xa5, 0x0,
    0x22, 0xd7, 0x0, 0xff, 0xe5, 0x39, 0x10, 0x3,
    0xff, 0x8e, 0x24, 0x8d, 0x13, 0x57, 0x6c, 0xc6,
    0xf7, 0x29, 0x0, 0x3f, 0xfe, 0x68, 0x64, 0x1,
    0xff, 0xca, 0x58, 0x94, 0x10, 0xf, 0xfe, 0xd9,
    0x10, 0x40, 0x3f, 0xfd, 0x29, 0xea, 0x1, 0xff,
    0xcc, 0x26, 0xbc, 0x94, 0x10, 0xf, 0xfe, 0xa9,
    0x2d, 0x64, 0x20, 0x7, 0xff, 0xa0, 0x4d, 0x44,
    0x3, 0xff, 0x9e, 0x4d, 0x79, 0x28, 0x20, 0x1f,
    0xfc, 0xf1, 0x5a, 0xfa, 0x51, 0x0, 0xff, 0xf5,
    0x2e, 0x98, 0x7, 0xf8, 0x5a, 0x20, 0x82, 0x1,
    0xff, 0xc3, 0x26, 0xbc, 0x94, 0x10, 0xf, 0xfe,
    0x48, 0xad, 0x65, 0x29, 0x0, 0x7f, 0xfb, 0xb,
    0x1c, 0x3, 0xfe, 0x4c, 0x77, 0x5e, 0x4a, 0x88,
    0x7, 0xff, 0xc, 0x9b, 0xd0, 0x3, 0xff, 0x8c,
    0x29, 0x39, 0x4a, 0x40, 0x1e, 0x5a, 0xff, 0xff,
    0xe9, 0xca, 0x0, 0x7f, 0xf1, 0x9c, 0xc8, 0x3,
    0xfc, 0x7a, 0xe0, 0x11, 0x35, 0x7d, 0x29, 0x0,
    0x7f, 0xf5, 0x5, 0xaa, 0xd8, 0x80, 0x3f, 0xfb,
    0xc6, 0x1, 0xff, 0xc6, 0x3c, 0x50, 0xf, 0xf0,
    0xaa, 0x10, 0x7, 0x85, 0x6b, 0x2d, 0x8c, 0x3,
    0xff, 0xa2, 0x2d, 0x54, 0x52, 0x0, 0xff, 0xf8,
    0xa, 0x28, 0x80, 0x7f, 0x97, 0xc, 0x3, 0xfc,
    0x29, 0x32, 0x50, 0xf, 0xfe, 0x90, 0xad, 0x65,
    0xb1, 0x0, 0x79, 0x6b, 0xff, 0xff, 0xa7, 0x48,
    0x1, 0xff, 0xc4, 0x5d, 0x30, 0xf, 0xf1, 0xe3,
    0x80, 0x7f, 0xf9, 0x45, 0x27, 0x2d, 0x88, 0x3,
    0xff, 0xd2, 0x46, 0xe0, 0x1f, 0xe1, 0x53, 0x20,
    0xf, 0xff, 0x40, 0xa4, 0xe5, 0xb9, 0x80, 0x7f,
    0xf1, 0x92, 0x25, 0x4, 0x3, 0xff, 0x9e, 0xfa,
    0x40, 0x1f, 0xe5, 0xc4, 0x0, 0xff, 0xf6, 0xa,
    0x46, 0xda, 0x0, 0x7f, 0xf1, 0x4, 0x9a, 0xf2,
    0x54, 0x40, 0x3f, 0xf9, 0x67, 0xa8, 0x1, 0xfe,
    0x2c, 0x70, 0xf, 0xff, 0x80, 0x8c, 0x1, 0xff,
    0xc8, 0x26, 0xac, 0xa5, 0x10, 0xf, 0xfe, 0x38,
    0xaa, 0x8, 0x7, 0xf0, 0xa1, 0x90, 0x7, 0xff,
    0x88, 0xde, 0xef, 0xff, 0xa7, 0x8, 0x1, 0xc4,
    0xb5, 0x94, 0xa4, 0x1, 0xff, 0xc4, 0x5f, 0x30,
    0xf, 0xf2, 0xfa, 0x0, 0x7f, 0xf8, 0xdf, 0x51,
    0x3f, 0xfa, 0x64, 0x20, 0x1f, 0x89, 0x6b, 0x29,
    0x44, 0x3, 0xff, 0x80, 0x46, 0x80, 0x1f, 0xe2,
    0xc4, 0x0, 0xff, 0xff, 0x80, 0x7f, 0xf1, 0x89,
    0xb9, 0x4, 0x3, 0xff, 0x80, 0xfa, 0x40, 0x1f,
    0xc2, 0x86, 0x40, 0x1f, 0xfe, 0x45, 0x8c, 0xcf,
    0xfe, 0x9c, 0x18, 0x7, 0xc4, 0xd7, 0x90, 0x82,
    0x1, 0xff, 0xc0, 0x3d, 0x70, 0xf, 0xf2, 0xfa,
    0x0, 0x7f, 0xf9, 0x44, 0x8c, 0xff, 0xfa, 0x64,
    0xc0, 0x18, 0x9a, 0xf2, 0x50, 0x40, 0x3f, 0xf8,
    0x42, 0xa6, 0x40, 0x1f, 0xc4, 0x68, 0x1, 0xff,
    0xff, 0x0, 0xff, 0x89, 0xaf, 0x25, 0x4, 0x3,
    0xff, 0x8a, 0x42, 0x6, 0x7f, 0xe5, 0xb2, 0x0,
    0xff, 0xe4, 0x9, 0x19, 0xff, 0x88, 0x40, 0x3f,
    0xfc, 0xad, 0xf5, 0x92, 0x82, 0x1, 0xff, 0xc0,

    /* U+E86C "" */
    0x0, 0xff, 0xf1, 0x9, 0xab, 0x44, 0xca, 0xa9,
    0x76, 0xcd, 0xd7, 0x73, 0xfd, 0xdc, 0xdd, 0x65,
    0xda, 0xa9, 0x32, 0x86, 0x53, 0x10, 0xf, 0xff,
    0xf8, 0x7, 0xe1, 0x35, 0x79, 0xbc, 0xef, 0xec,
    0xa9, 0x76, 0x62, 0xa9, 0x10, 0x64, 0x41, 0x10,
    0x0, 0x44, 0x44, 0x34, 0x42, 0xa9, 0x98, 0xf3,
    0x59, 0xdf, 0xd9, 0x72, 0xea, 0x62, 0x1, 0xff,
    0xf9, 0x24, 0x7a, 0xde, 0xca, 0x86, 0x43, 0x10,
    0xf, 0xfe, 0xc0, 0x9a, 0x34, 0x56, 0x76, 0xd3,
    0xa1, 0x0, 0x7f, 0xfb, 0xc5, 0x23, 0x3b, 0x6e,
    0x14, 0x80, 0x3f, 0xfd, 0x4, 0xb1, 0x7b, 0xd9,
    0x8, 0x20, 0x1f, 0xfe, 0x61, 0x37, 0xbf, 0xb7,
    0x31, 0x0, 0xff, 0xe1, 0x89, 0xa3, 0x44, 0xd5,
    0xe6, 0x37, 0xb9, 0xff, 0xee, 0xe6, 0xe6, 0x2e,
    0xa6, 0x19, 0xc, 0x40, 0x3f, 0xf8, 0x62, 0x6f,
    0x7f, 0x6e, 0x62, 0x1, 0xff, 0xdf, 0x26, 0xac,
    0xc4, 0x20, 0x80, 0x7f, 0xf0, 0x4, 0xda, 0x73,
    0xbf, 0xb2, 0xe5, 0xd9, 0x50, 0xcc, 0x42, 0x20,
    0xf, 0x8, 0x88, 0xcc, 0x8a, 0xcf, 0x37, 0x9d,
    0xfd, 0x92, 0xc6, 0x20, 0x1f, 0xfc, 0x1, 0x48,
    0xcc, 0x53, 0x10, 0x7, 0xff, 0x64, 0x56, 0xb2,
    0x54, 0x80, 0x3f, 0xe2, 0x58, 0xbd, 0xec, 0x96,
    0x31, 0x0, 0xff, 0xeb, 0x9, 0xb4, 0xe7, 0x6d,
    0xc2, 0x90, 0x7, 0xfc, 0x4b, 0x39, 0x4a, 0x20,
    0x1f, 0xfd, 0x43, 0x7d, 0xa5, 0x10, 0xf, 0xf0,
    0xa4, 0x66, 0xd3, 0xa1, 0x0, 0x7f, 0xf8, 0x89,
    0x1e, 0xb3, 0x10, 0x82, 0x1, 0xfe, 0x15, 0xad,
    0x73, 0x0, 0xff, 0xe7, 0x8a, 0x56, 0xc1, 0x80,
    0x7f, 0x89, 0xaf, 0xed, 0xcc, 0x3, 0xff, 0xd6,
    0x26, 0xf7, 0xf6, 0xc4, 0x1, 0xfe, 0x38, 0xd9,
    0x41, 0x0, 0xff, 0xe5, 0xa4, 0x52, 0x88, 0x7,
    0xf0, 0xad, 0x64, 0xa0, 0x80, 0x7f, 0xfc, 0x85,
    0x27, 0x29, 0x44, 0x3, 0xf8, 0x5a, 0xa1, 0x0,
    0x3f, 0xf9, 0x4, 0xf0, 0xc2, 0x1, 0xfc, 0x6f,
    0xb4, 0xa2, 0x1, 0xff, 0xf8, 0x15, 0xad, 0x73,
    0x0, 0xfe, 0x16, 0x87, 0x20, 0xf, 0xfe, 0x20,
    0xac, 0xc1, 0x80, 0x7f, 0x1c, 0x74, 0x18, 0x7,
    0xff, 0xc8, 0xde, 0x5c, 0xc0, 0x3e, 0x38, 0xe8,
    0x30, 0xf, 0xe3, 0x88, 0x28, 0x80, 0x7f, 0xf0,
    0x49, 0xa1, 0x0, 0x3f, 0x85, 0xa1, 0xc8, 0x3,
    0xff, 0xe2, 0x6f, 0x9b, 0xd, 0x19, 0x87, 0x30,
    0xf, 0x13, 0xc3, 0x8, 0x7, 0xf2, 0xc3, 0x10,
    0x7, 0xfc, 0x4b, 0x64, 0x1, 0xfc, 0x91, 0x4,
    0x0, 0xff, 0xf8, 0x1b, 0xe6, 0xc1, 0x88, 0x6,
    0x38, 0xcc, 0x39, 0x80, 0x72, 0x44, 0x10, 0x3,
    0xf8, 0xad, 0x48, 0x3, 0xf8, 0x56, 0xcc, 0x3,
    0xf9, 0x79, 0x84, 0x3, 0xff, 0xdc, 0x6f, 0x98,
    0x83, 0x10, 0xf, 0xfe, 0x38, 0xb7, 0x28, 0x7,
    0xf1, 0xda, 0x8, 0x7, 0xc2, 0xf6, 0x60, 0x1f,
    0xc9, 0xea, 0x1, 0xff, 0xed, 0x37, 0xcc, 0x41,
    0x80, 0x7f, 0xc7, 0x19, 0x87, 0x30, 0xf, 0xcb,
    0xe8, 0x1, 0xfc, 0x7a, 0xe2, 0x1, 0xe5, 0xf3,
    0x0, 0xfe, 0x4d, 0x40, 0xf, 0xff, 0x59, 0xbe,
    0x62, 0xc, 0x3, 0xfe, 0x38, 0xcc, 0x39, 0x80,
    0x7f, 0xf0, 0x13, 0x50, 0x3, 0xf9, 0x3d, 0x40,
    0x3c, 0x44, 0x0, 0xfe, 0x13, 0x51, 0x0, 0xff,
    0xf4, 0x1b, 0xe6, 0x20, 0xc0, 0x3f, 0xe3, 0x8c,
    0xc3, 0x98, 0x7, 0xff, 0xc, 0x54, 0xc4, 0x3,
    0xf8, 0x88, 0x1, 0xc4, 0x2c, 0x1, 0xfc, 0x5e,
    0x40, 0x1f, 0xfe, 0x63, 0x8c, 0xc4, 0x18, 0x7,
    0xfc, 0x71, 0x98, 0x73, 0x0, 0xff, 0xe3, 0x97,
    0x90, 0x7, 0xf3, 0x9, 0x0, 0x61, 0xe3, 0x0,
    0xfe, 0x72, 0x10, 0xf, 0xfe, 0x18, 0x9b, 0xcb,
    0x98, 0x7, 0xff, 0x34, 0x4e, 0x33, 0xe, 0x60,
    0x1f, 0xf1, 0xc6, 0x61, 0xcc, 0x3, 0xff, 0x94,
    0x24, 0xe0, 0x1f, 0xc7, 0xc2, 0x1, 0xff, 0xd3,
    0x13, 0x8d, 0xc8, 0x68, 0xcc, 0x39, 0x80, 0x7f,
    0xf1, 0xc4, 0xe3, 0x71, 0xcc, 0x3, 0xfe, 0x38,
    0xcc, 0x39, 0x80, 0x7f, 0xf8, 0x7, 0x8c, 0x3,
    0xf9, 0xc8, 0x40, 0x3f, 0x84, 0xe3, 0x71, 0xcc,
    0x3, 0x8e, 0x33, 0xe, 0x60, 0x1f, 0xfc, 0x11,
    0x38, 0xdc, 0x73, 0x0, 0xff, 0x8e, 0x33, 0xe,
    0x60, 0x1f, 0xfd, 0x1, 0x27, 0x0, 0xfe, 0x3e,
    0x10, 0xc, 0x42, 0xc0, 0x1f, 0xc5, 0xe4, 0x1,
    0xfc, 0x21, 0xe0, 0x1f, 0xfc, 0x3, 0x8c, 0xc3,
    0x98, 0x7, 0xc2, 0x71, 0xb8, 0xe6, 0x1, 0xff,
    0x1c, 0x66, 0x1c, 0xc0, 0x3f, 0xfa, 0x65, 0xe4,
    0x1, 0xfc, 0xc2, 0x40, 0x1c, 0x44, 0x0, 0xfe,
    0x13, 0x51, 0x0, 0xfe, 0x37, 0xcc, 0x41, 0x80,
    0x7f, 0xc7, 0x19, 0x87, 0x30, 0x14, 0x8d, 0xc7,
    0x30, 0xf, 0xf8, 0xe3, 0x30, 0xe6, 0x1, 0xff,
    0xd5, 0x15, 0x31, 0x0, 0xfe, 0x22, 0x0, 0x79,
    0x7c, 0xc0, 0x3f, 0x93, 0x50, 0x3, 0xff, 0x80,
    0x6f, 0x98, 0x73, 0x0, 0xff, 0x8e, 0x33, 0xbe,
    0xdc, 0xc0, 0x3f, 0xe3, 0x8c, 0xc3, 0x98, 0x7,
    0xff, 0x61, 0x35, 0x0, 0x3f, 0x93, 0xd4, 0x3,
    0xc2, 0xf6, 0x60, 0x1f, 0xc9, 0xea, 0x1, 0xff,
    0xc2, 0x38, 0xcc, 0x39, 0x80, 0x7f, 0xc2, 0x20,
    0xf, 0xf8, 0xe3, 0x30, 0xe6, 0x1, 0xff, 0xda,
    0x5f, 0x40, 0xf, 0xe3, 0xd7, 0x10, 0xf, 0x85,
    0x6c, 0xc0, 0x3f, 0x97, 0x98, 0x40, 0x3f, 0xf8,
    0x67, 0x19, 0x87, 0x30, 0xf, 0xfe, 0x31, 0xc6,
    0x61, 0xcc, 0x3, 0xff, 0xb6, 0x2d, 0xca, 0x1,
    0xfc, 0x76, 0x82, 0x1, 0xfc, 0x4b, 0x64, 0x1,
    0xfc, 0x91, 0x4, 0x0, 0xff, 0xe2, 0x9c, 0x6e,
    0x39, 0x80, 0x7f, 0xf0, 0xe, 0x33, 0xe, 0x60,
    0x1f, 0xfd, 0xd4, 0x88, 0x20, 0x7, 0xf1, 0x5a,
    0x90, 0x7, 0xfc, 0x4d, 0x8, 0x1, 0xfc, 0x2d,
    0xe, 0x40, 0x1f, 0xfc, 0x51, 0x38, 0xdb, 0x73,
    0x0, 0xf1, 0xc6, 0x61, 0xcc, 0x3, 0xff, 0xbc,
    0x4f, 0xc, 0x20, 0x1f, 0xcb, 0xc, 0x40, 0x1f,
    0xfc, 0x11, 0x59, 0x83, 0x0, 0xfe, 0x38, 0xe7,
    0x30, 0xf, 0xfe, 0x30, 0xa4, 0x6d, 0xb9, 0xa4,
    0x66, 0x1c, 0xc0, 0x3f, 0xfb, 0xe7, 0x1d, 0x6,
    0x1, 0xfc, 0x71, 0x5, 0x10, 0xf, 0xfe, 0x21,
    0x3c, 0x30, 0x80, 0x7f, 0x1c, 0x6d, 0x28, 0x80,
    0x7f, 0xf1, 0x85, 0x23, 0x2d, 0xcc, 0x3, 0xff,
    0xbe, 0x2b, 0x5a, 0xe6, 0x1, 0xfc, 0x2d, 0xe,
    0x40, 0x1f, 0xfc, 0x84, 0x8a, 0x51, 0x0, 0xfe,
    0x15, 0xad, 0x94, 0x10, 0xf, 0xff, 0x90, 0xa4,
    0xe5, 0x28, 0x80, 0x7f, 0xa, 0xd4, 0x20, 0x7,
    0xff, 0x2c, 0x52, 0xb6, 0xc, 0x3, 0xfc, 0x6d,
    0x7f, 0x6c, 0x60, 0x1f, 0xfe, 0xc3, 0x7b, 0xfb,
    0x62, 0x0, 0xff, 0x1c, 0x6d, 0x20, 0x80, 0x7f,
    0xf3, 0xcd, 0xf6, 0x94, 0x40, 0x3f, 0xc2, 0x93,
    0x9b, 0x4e, 0x84, 0x1, 0xff, 0xe2, 0x24, 0x7a,
    0xdc, 0x84, 0x10, 0xf, 0xf0, 0xad, 0x6b, 0x98,
    0x7, 0xff, 0x50, 0x56, 0xb2, 0x54, 0x80, 0x3f,
    0xe2, 0x58, 0xbd, 0xeb, 0x86, 0x31, 0x0, 0xff,
    0xeb, 0x9, 0xb4, 0x67, 0x6d, 0xc2, 0x90, 0x7,
    0xfc, 0x4b, 0x39, 0x4a, 0x20, 0x1f, 0xfd, 0x92,
    0x6a, 0xcc, 0x42, 0x8, 0x7, 0xff, 0x0, 0x51,
    0xe7, 0x3b, 0xfb, 0x2e, 0x5d, 0x91, 0x6, 0x44,
    0x11, 0x0, 0x78, 0x44, 0x44, 0x34, 0x43, 0x3c,
    0xde, 0x77, 0xf6, 0x4b, 0x98, 0x80, 0x7f, 0xf0,
    0x5, 0x23, 0x31, 0x4c, 0x40, 0x1f, 0xfd, 0xf1,
    0x37, 0xbf, 0xb7, 0x31, 0x0, 0xff, 0xe1, 0x89,
    0xa3, 0x44, 0xdd, 0xb3, 0x75, 0xdc, 0xff, 0xf7,
    0x73, 0x75, 0x97, 0x69, 0x86, 0x43, 0x10, 0xf,
    0xfe, 0x18, 0x9b, 0xdf, 0xdb, 0x98, 0x80, 0x7f,
    0xf9, 0x85, 0x23, 0x3b, 0x6e, 0x14, 0x80, 0x3f,
    0xfd, 0x4, 0xb1, 0x7b, 0xd9, 0x8, 0x20, 0x1f,
    0xfe, 0xf2, 0x47, 0xad, 0xec, 0xa8, 0x64, 0x31,
    0x0, 0xff, 0xec, 0x9, 0xa3, 0x45, 0x67, 0x6d,
    0x3a, 0x10, 0x7, 0xff, 0xe4, 0x4d, 0x5e, 0x6f,
    0x3b, 0xfb, 0x2a, 0x5d, 0x98, 0xa8, 0x83, 0x31,
    0x10, 0x44, 0x0, 0x11, 0x11, 0xc, 0xc8, 0xaa,
    0x66, 0x3c, 0xd6, 0x77, 0xf6, 0x5c, 0xba, 0x98,
    0x80, 0x7f, 0xf6, 0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 768, .box_w = 138, .box_h = 38, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 517, .adv_w = 768, .box_w = 114, .box_h = 44, .ofs_x = 5, .ofs_y = 1},
    {.bitmap_index = 1126, .adv_w = 768, .box_w = 84, .box_h = 36, .ofs_x = 11, .ofs_y = 6},
    {.bitmap_index = 1404, .adv_w = 768, .box_w = 126, .box_h = 43, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 2204, .adv_w = 768, .box_w = 126, .box_h = 40, .ofs_x = 3, .ofs_y = 4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x2, 0x54d, 0x570, 0x86a
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 57346, .range_length = 2155, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 1,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t font_icon = {
#else
lv_font_t font_icon = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 44,          /*The maximum line height required by the font*/
    .base_line = -1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_HOR,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT_ICON*/

