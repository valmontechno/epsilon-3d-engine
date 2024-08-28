#include "vMaths.h"

Tri3::Tri3() {
    p0 = Vec3();
    p1 = Vec3();
    p2 = Vec3();
}

Tri3::Tri3(Vec3 p0, Vec3 p1, Vec3 p2) {
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
}

Tri3 Tri3::translate(Vec3 v) {
    return Tri3(p0 + v, p1 + v, p2 + v);
}

Tri3 Tri3::rotateX(float pitch) {
    return Tri3(p0.rotateX(pitch), p1.rotateX(pitch), p2.rotateX(pitch));
}

Tri3 Tri3::rotateY(float yaw) {
    return Tri3(p0.rotateY(yaw), p1.rotateY(yaw), p2.rotateY(yaw));
}