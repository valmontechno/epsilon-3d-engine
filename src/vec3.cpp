#include "vMaths.h"
#include "maths.h"
// #include <algorithm>

Vec3::Vec3() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec3 Vec3::operator+(const Vec3& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vec3 Vec3::operator-() const {
    return {-x, -y, -z};
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vec3 Vec3::operator*(const float& n) const {
    return {x * n, y * n, z * n};
}

Vec3 Vec3::operator/(const float& n) const {
    return {x / n, y / n, z / n};
}

Vec3& Vec3::operator+=(const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3& Vec3::operator*=(const float& n) {
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

Vec3& Vec3::operator/=(const float& n) {
    x /= n;
    y /= n;
    z /= n;
    return *this;
}

Vec3 Vec3::rotateX(float pitch) {
    return Vec3(
        x,
        cos(pitch) * y - sin(pitch) * z,
        sin(pitch) * y + cos(pitch) * z
    );
}

Vec3 Vec3::rotateY(float yaw) {
    return Vec3(
        cos(yaw) * x + sin(yaw) * z,
        y,
        -sin(yaw) * x + cos(yaw) * z
    );
}

float Vec3::dot(Vec3 a, Vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3 Vec3::cross(Vec3 a, Vec3 b) {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

Vec3 Vec3::linePlaneIntersection(Vec3 planeNormal, Vec3 planePoint, Vec3 v1, Vec3 v2) {
    Vec3 u = v2 - v1;
    double dotp = dot(planeNormal, u);
    if (abs(dotp) < 1e-5f) {
        return Vec3();
    }
    Vec3 w = v1 - planePoint;
    double si = -dot(planeNormal, w) / dotp;
    u = u * si;
    return v1 + u;
}