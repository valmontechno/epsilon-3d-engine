#ifndef RBG332_H
#define RBG332_H

#include "eadkpp.h"

using namespace EADK;

Color rgb332ToColor(uint8_t rgb332);
void unpackRgb332(uint8_t rgb332, uint8_t& r, uint8_t& g, uint8_t& b);
uint8_t packRgb332(uint8_t r, uint8_t g, uint8_t b);

#endif