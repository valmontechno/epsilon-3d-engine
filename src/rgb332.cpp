#include "rgb332.h"
#include "eadkpp.h"

using namespace EADK;

Color rgb332ToColor(uint8_t rgb332) {
    uint8_t r = (rgb332 >> 5) & 0x07;
    uint8_t g = (rgb332 >> 2) & 0x07;
    uint8_t b = rgb332 & 0x03;

    r = (r << 5) | (r << 2) | (r >> 1);
    g = (g << 5) | (g << 2) | (g >> 1);
    b = (b << 6) | (b << 4) | (b << 2) | b;

    return Color((r << 16) | (g << 8) | b);
}