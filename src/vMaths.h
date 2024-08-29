#ifndef VMATHS_H
#define VMATHS_H

struct Vec2 {
    float x, y;

    Vec2();
    Vec2(float x, float y);

    Vec2 operator+(const Vec2& v) const;
    Vec2 operator-() const;
    Vec2 operator-(const Vec2& v) const;
    Vec2 operator*(const float& n) const;
    Vec2 operator/(const float& n) const;
};

struct Tri2 {
    Vec2 p0, p1, p2;

    Tri2(Vec2 p0, Vec2 p1, Vec2 p2);
};

struct Vec3 {
    float x, y, z;

    Vec3();
    Vec3(float x, float y, float z);

    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-() const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(const float& x) const;
    Vec3 operator/(const float& x) const;
    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);
    Vec3& operator*=(const float& x);
    Vec3& operator/=(const float& x);

    Vec3 rotateX(float pitch);
    Vec3 rotateY(float yaw);

    static float dot(Vec3 a, Vec3 b);
    static double dotd(Vec3 a, Vec3 b);
    static Vec3 linePlaneIntersection(Vec3 planeNormal, Vec3 planePoint, Vec3 p0, Vec3 p1);
};

struct Tri3 {
    Vec3 p0, p1, p2;

    Tri3();
    Tri3(Vec3 p0, Vec3 p1, Vec3 p2);

    Tri3 translate(Vec3 v);
    Tri3 rotateX(float pitch);
    Tri3 rotateY(float yaw);
};

#endif