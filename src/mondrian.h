// Piet Mondrian

#ifndef MONDRIAN_H
#define MONDRIAN_H

#include "eadkpp.h"
#include "vMaths.h"

using namespace EADK;

namespace mondrian {

    extern uint8_t buffer[Screen::Height][Screen::Width];

    void draw();
    void clear();
    void putTriangle(Tri2 tri, uint8_t color);

}

#endif