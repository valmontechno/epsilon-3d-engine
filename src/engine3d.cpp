#include "engine3d.h"
#include "vMaths.h"

Vec2 engine3d::vectorProjection(Vec3 v) {
    return Vec2(v.x, v.y) / v.z;
}

Tri2 engine3d::triangleProjection(Tri3 tri) {
    return Tri2(vectorProjection(tri.p0), vectorProjection(tri.p1), vectorProjection(tri.p2));
}