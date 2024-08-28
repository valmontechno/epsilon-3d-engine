#include "vMaths.h"

Vec2::Vec2() {
    x = 0.0f;
    y = 0.0f;
}

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator+(const Vec2& v) const {
    return {x + v.x, y + v.y};
}

Vec2 Vec2::operator-() const {
    return {-x, -y};
}

Vec2 Vec2::operator-(const Vec2& v) const {
    return {x - v.x, y - v.y};
}

Vec2 Vec2::operator*(const float& n) const {
    return {x * n, y * n};
}

Vec2 Vec2::operator/(const float& n) const {
    return {x / n, y / n};
}