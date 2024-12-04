#include "fbpad.h"

static int dwchars[][2] = {
        {0x1100,  0x115f},
        {0x11a3,  0x11a7},
        {0x11fa,  0x11ff},
        {0x2329,  0x232a},
        {0x2e80,  0x2e99},
        {0x2e9b,  0x2ef3},
        {0x2f00,  0x2fd5},
        {0x2ff0,  0x2ffb},
        {0x3000,  0x3029},
        {0x3030,  0x303e},
        {0x3041,  0x3096},
        {0x309b,  0x30ff},
        {0x3105,  0x312d},
        {0x3131,  0x318e},
        {0x3190,  0x31b7},
        {0x31c0,  0x31e3},
        {0x31f0,  0x321e},
        {0x3220,  0x3247},
        {0x3250,  0x32fe},
        {0x3300,  0x4dbf},
        {0x4e00,  0xa48c},
        {0xa490,  0xa4c6},
        {0xa960,  0xa97c},
        {0xac00,  0xd7a3},
        {0xd7b0,  0xd7c6},
        {0xd7cb,  0xd7fb},
        {0xf900,  0xfaff},
        {0xfe10,  0xfe19},
        {0xfe30,  0xfe52},
        {0xfe54,  0xfe66},
        {0xfe68,  0xfe6b},
        {0xff01,  0xff60},
        {0xffe0,  0xffe6},
        {0x1f200, 0x1f200},
        {0x1f210, 0x1f231},
        {0x1f240, 0x1f248},
        {0x20000, 0x2ffff},
};

static int zwchars[][2] = {
        {0x0300,  0x036f},
        {0x0483,  0x0489},
        {0x0591,  0x05bd},
        {0x05bf,  0x05bf},
        {0x05c1,  0x05c2},
        {0x05c4,  0x05c5},
        {0x05c7,  0x05c7},
        {0x0610,  0x061a},
        {0x064b,  0x065e},
        {0x0670,  0x0670},
        {0x06d6,  0x06dc},
        {0x06de,  0x06e4},
        {0x06e7,  0x06e8},
        {0x06ea,  0x06ed},
        {0x0711,  0x0711},
        {0x0730,  0x074a},
        {0x07a6,  0x07b0},
        {0x07eb,  0x07f3},
        {0x0816,  0x0819},
        {0x081b,  0x0823},
        {0x0825,  0x0827},
        {0x0829,  0x082d},
        {0x0900,  0x0903},
        {0x093c,  0x093c},
        {0x093e,  0x094e},
        {0x0951,  0x0955},
        {0x0962,  0x0963},
        {0x0981,  0x0983},
        {0x09bc,  0x09bc},
        {0x09be,  0x09c4},
        {0x09c7,  0x09c8},
        {0x09cb,  0x09cd},
        {0x09d7,  0x09d7},
        {0x09e2,  0x09e3},
        {0x0a01,  0x0a03},
        {0x0a3c,  0x0a3c},
        {0x0a3e,  0x0a42},
        {0x0a47,  0x0a48},
        {0x0a4b,  0x0a4d},
        {0x0a51,  0x0a51},
        {0x0a70,  0x0a71},
        {0x0a75,  0x0a75},
        {0x0a81,  0x0a83},
        {0x0abc,  0x0abc},
        {0x0abe,  0x0ac5},
        {0x0ac7,  0x0ac9},
        {0x0acb,  0x0acd},
        {0x0ae2,  0x0ae3},
        {0x0b01,  0x0b03},
        {0x0b3c,  0x0b3c},
        {0x0b3e,  0x0b44},
        {0x0b47,  0x0b48},
        {0x0b4b,  0x0b4d},
        {0x0b56,  0x0b57},
        {0x0b62,  0x0b63},
        {0x0b82,  0x0b82},
        {0x0bbe,  0x0bc2},
        {0x0bc6,  0x0bc8},
        {0x0bca,  0x0bcd},
        {0x0bd7,  0x0bd7},
        {0x0c01,  0x0c03},
        {0x0c3e,  0x0c44},
        {0x0c46,  0x0c48},
        {0x0c4a,  0x0c4d},
        {0x0c55,  0x0c56},
        {0x0c62,  0x0c63},
        {0x0c82,  0x0c83},
        {0x0cbc,  0x0cbc},
        {0x0cbe,  0x0cc4},
        {0x0cc6,  0x0cc8},
        {0x0cca,  0x0ccd},
        {0x0cd5,  0x0cd6},
        {0x0ce2,  0x0ce3},
        {0x0d02,  0x0d03},
        {0x0d3e,  0x0d44},
        {0x0d46,  0x0d48},
        {0x0d4a,  0x0d4d},
        {0x0d57,  0x0d57},
        {0x0d62,  0x0d63},
        {0x0d82,  0x0d83},
        {0x0dca,  0x0dca},
        {0x0dcf,  0x0dd4},
        {0x0dd6,  0x0dd6},
        {0x0dd8,  0x0ddf},
        {0x0df2,  0x0df3},
        {0x0e31,  0x0e31},
        {0x0e34,  0x0e3a},
        {0x0e47,  0x0e4e},
        {0x0eb1,  0x0eb1},
        {0x0eb4,  0x0eb9},
        {0x0ebb,  0x0ebc},
        {0x0ec8,  0x0ecd},
        {0x0f18,  0x0f19},
        {0x0f35,  0x0f35},
        {0x0f37,  0x0f37},
        {0x0f39,  0x0f39},
        {0x0f3e,  0x0f3f},
        {0x0f71,  0x0f84},
        {0x0f86,  0x0f87},
        {0x0f90,  0x0f97},
        {0x0f99,  0x0fbc},
        {0x0fc6,  0x0fc6},
        {0x102b,  0x103e},
        {0x1056,  0x1059},
        {0x105e,  0x1060},
        {0x1062,  0x1064},
        {0x1067,  0x106d},
        {0x1071,  0x1074},
        {0x1082,  0x108d},
        {0x108f,  0x108f},
        {0x109a,  0x109d},
        {0x135f,  0x135f},
        {0x1712,  0x1714},
        {0x1732,  0x1734},
        {0x1752,  0x1753},
        {0x1772,  0x1773},
        {0x17b6,  0x17d3},
        {0x17dd,  0x17dd},
        {0x180b,  0x180d},
        {0x18a9,  0x18a9},
        {0x1920,  0x192b},
        {0x1930,  0x193b},
        {0x19b0,  0x19c0},
        {0x19c8,  0x19c9},
        {0x1a17,  0x1a1b},
        {0x1a55,  0x1a5e},
        {0x1a60,  0x1a7c},
        {0x1a7f,  0x1a7f},
        {0x1b00,  0x1b04},
        {0x1b34,  0x1b44},
        {0x1b6b,  0x1b73},
        {0x1b80,  0x1b82},
        {0x1ba1,  0x1baa},
        {0x1c24,  0x1c37},
        {0x1cd0,  0x1cd2},
        {0x1cd4,  0x1ce8},
        {0x1ced,  0x1ced},
        {0x1cf2,  0x1cf2},
        {0x1dc0,  0x1de6},
        {0x1dfd,  0x1dff},
        {0x200b,  0x200f},
        {0x20d0,  0x20f0},
        {0x2cef,  0x2cf1},
        {0x2de0,  0x2dff},
        {0x302a,  0x302f},
        {0x3099,  0x309a},
        {0xa66f,  0xa672},
        {0xa67c,  0xa67d},
        {0xa6f0,  0xa6f1},
        {0xa802,  0xa802},
        {0xa806,  0xa806},
        {0xa80b,  0xa80b},
        {0xa823,  0xa827},
        {0xa880,  0xa881},
        {0xa8b4,  0xa8c4},
        {0xa8e0,  0xa8f1},
        {0xa926,  0xa92d},
        {0xa947,  0xa953},
        {0xa980,  0xa983},
        {0xa9b3,  0xa9c0},
        {0xaa29,  0xaa36},
        {0xaa43,  0xaa43},
        {0xaa4c,  0xaa4d},
        {0xaa7b,  0xaa7b},
        {0xaab0,  0xaab0},
        {0xaab2,  0xaab4},
        {0xaab7,  0xaab8},
        {0xaabe,  0xaabf},
        {0xaac1,  0xaac1},
        {0xabe3,  0xabea},
        {0xabec,  0xabed},
        {0xfb1e,  0xfb1e},
        {0xfe00,  0xfe0f},
        {0xfe20,  0xfe26},
        {0x101fd, 0x101fd},
        {0x10a01, 0x10a03},
        {0x10a05, 0x10a06},
        {0x10a0c, 0x10a0f},
        {0x10a38, 0x10a3a},
        {0x10a3f, 0x10a3f},
        {0x11080, 0x11082},
        {0x110b0, 0x110ba},
        {0x1d165, 0x1d169},
        {0x1d16d, 0x1d172},
        {0x1d17b, 0x1d182},
        {0x1d185, 0x1d18b},
        {0x1d1aa, 0x1d1ad},
        {0x1d242, 0x1d244},
        {0xe0100, 0xe01ef}
};

static int find(int c, int tab[][2], int n) {
    int l = 0;
    int h = n - 1;
    int m;
    if (c < tab[0][0])
        return 0;
    while (l <= h) {
        m = (h + l) / 2;
        if (c >= tab[m][0] && c <= tab[m][1])
            return 1;
        if (c < tab[m][0])
            h = m - 1;
        else
            l = m + 1;
    }
    return 0;
}

/* double-width characters */
int isdw(int c) {
    return c >= 0x1100 && find(c, dwchars, LEN(dwchars));
}

/* zero-width and combining characters */
int iszw(int c) {
    return c >= 0x0300 && find(c, zwchars, LEN(zwchars));
}
