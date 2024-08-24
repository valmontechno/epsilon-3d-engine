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

Vec3 Vec3::operator+(const Vec3& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vec3 Vec3::operator-() const {
    return {-x, -y, -z};
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vec3 Vec3::operator*(const float& other) const {
    return {x * other, y * other, z * other};
}

Vec3 Vec3::operator/(const float& other) const {
    return {x / other, y / other, z / other};
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
        cos((double)yaw) * x + sin((double)yaw) * z,
        y,
        -sin((double)yaw) * x + cos((double)yaw) * z
    );
}