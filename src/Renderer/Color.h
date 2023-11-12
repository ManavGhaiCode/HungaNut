#ifndef _COLOR_H_
#define _COLOR_H_

#include <cstdint>

struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
};

#define NUT_BLACK Color (0, 0, 0, 255)
#define NUT_GREEN Color (0, 255, 0, 255)
#define NUT_BLUE  Color (0, 0, 255, 255)
#define NUT_RED   Color (255, 0, 0, 255)
#define NUT_WHITE Color (255, 255, 255, 255)
#define NUT_CBULE Color (100, 149, 237, 255)

#endif