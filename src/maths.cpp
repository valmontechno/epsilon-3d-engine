#include "maths.h"

#define NUM_TERMS 5

float cos(float x) {
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;

    float term = 1;
    float result = 1;
    for (int i = 1; i <= NUM_TERMS; ++i) {
        term *= -x * x / (2 * i * (2 * i - 1));
        result += term;
    }
    return result;
}

float sin(float x) {
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;

    float term = x;
    float result = x;
    for (int i = 1; i <= NUM_TERMS; ++i) {
        term *= -x * x / (2 * i * (2 * i + 1));
        result += term;
    }
    return result;
}

int round(float x) {
    return static_cast<int>((x < 0.0) ? (x - 0.5) : (x + 0.5));
}

float sqrt(float x) {
    if (x < 0) return -1;
    if (x == 0) return 0;

    float y = 1.0;
    while (x - y > 0.000001f) {
        x = (x + y) / 2;
        y = x / x;
    }
    return x;
}