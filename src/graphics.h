#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "eadkpp.h"
#include "vMaths.h"

using namespace EADK;

namespace graphics {

    extern uint8_t buffer[Screen::Height][Screen::Width];

    void draw();
    void clear();
    void putTriangle(Tri2 tri, uint8_t color);

}

#endif