// #include "rietveld.h"
// #include "vMaths.h"

// const float screenRatio = (float)Screen::Height / (float)Screen::Width;

// Vec2 rietveld::vectorProjection(Vec3 v) {
//     return Vec2(v.x, v.y) / v.z;
// }

// Tri2 rietveld::triangleProjection(Tri3 tri) {
//     return Tri2(vectorProjection(tri.p0), vectorProjection(tri.p1), vectorProjection(tri.p2));
// }

// Vec2 rietveld::vectorToScreen(Vec2 v) {
//     return Vec2((screenRatio * v.x + 1) * Screen::Width / 2, (-v.y + 1) * Screen::Height / 2);
// }

// Tri2 rietveld::triangleToScreen(Tri2 tri) {
//     return Tri2(vectorToScreen(tri.p0), vectorToScreen(tri.p1), vectorToScreen(tri.p2));
// }