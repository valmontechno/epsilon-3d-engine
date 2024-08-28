#include "vMaths.h"
#include "maths.h"

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