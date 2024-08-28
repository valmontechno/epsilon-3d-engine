#include "rietveld.h"
#include "vMaths.h"
#include "maths.h"
#include "mondrian.h"

using namespace mondrian;

Camera::Camera(Vec3 position, float pitch, float yaw, float focalLenth) {
    this->position = position;
    this->pitch = pitch;
    this->yaw = yaw;
    this->focalLenth = focalLenth;
}

Vec3 Camera::getForward() const {
    return Vec3(-sin(yaw), 0.0f, cos(yaw));
}

Vec3 Camera::getRight() const {
    return Vec3(cos(yaw), 0.0f, sin(yaw));
}

void Camera::pushTriangle(Tri3 tri, uint8_t color) const {
    putTriangle(triangleToScreen(triangleProjection(tri.translate(-position).rotateY(yaw).rotateX(pitch))), color);
}

void Camera::pushMesh(const Tri3 mesh[], size_t size, uint8_t color) const {
    for (size_t i = 0; i < size; i++) {
        pushTriangle(mesh[i], color);
    }
}


Vec2 Camera::vectorProjection(Vec3 v) const {
    return Vec2(v.x, v.y) / v.z * focalLenth;
}

Tri2 Camera::triangleProjection(Tri3 tri) const {
    return Tri2(vectorProjection(tri.p0), vectorProjection(tri.p1), vectorProjection(tri.p2));
}

const float screenRatio = (float)Screen::Height / (float)Screen::Width;

Vec2 Camera::vectorToScreen(Vec2 v) const {
    return Vec2((screenRatio * v.x + 1) * Screen::Width / 2, (-v.y + 1) * Screen::Height / 2);
}

Tri2 Camera::triangleToScreen(Tri2 tri) const {
    return Tri2(vectorToScreen(tri.p0), vectorToScreen(tri.p1), vectorToScreen(tri.p2));
}