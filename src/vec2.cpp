#include "vMaths.h"

Vec2::Vec2() {
    x = 0.0f;
    y = 0.0f;
}

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator+(const Vec2& other) const {
    return {x + other.x, y + other.y};
}

Vec2 Vec2::operator-() const {
    return {-x, -y};
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return {x - other.x, y - other.y};
}

Vec2 Vec2::operator*(const float& other) const {
    return {x * other, y * other};
}