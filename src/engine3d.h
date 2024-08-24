#ifndef ENGINE3D_H
#define ENGINE3D_H

#include "eadkpp.h"
#include "vMaths.h"

using namespace EADK;

namespace engine3d {

    Vec2 vectorProjection(Vec3 v);
    Tri2 triangleProjection(Tri3 tri);

}

#endif