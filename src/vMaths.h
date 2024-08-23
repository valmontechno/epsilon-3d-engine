#ifndef VMATHS_H
#define VMATHS_H

struct Vec2 {
    float x, y;

    Vec2();
    Vec2(float x, float y);

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-() const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(const float& other) const;
};

struct Tri2 {
    Vec2 p0, p1, p2;

    Tri2(Vec2 p0, Vec2 p1, Vec2 p2);
};

#endif