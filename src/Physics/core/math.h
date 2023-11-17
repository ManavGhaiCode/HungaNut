#ifndef _PHYSICS_MATH_H_
#define _PHYSICS_MATH_H_

#include "Physics/core/vector.h"
#include <math.h>

namespace Physics {
    double Length(Vector2 vect) {
        return sqrt(vect.x * vect.x + vect.y * vect.y);
    }

    double Distance(Vector2 vect1, Vector2 vect2) {
        float dx = vect1.x - vect2.x;
        float dy = vect1.y - vect2.y;

        return sqrt(dx * dx + dy * dy);
    }

    double dot(Vector2 vect1, Vector2 vect2) {
        return vect1.x * vect2.x + vect1.y * vect2.y;
    }

    double cross(Vector2 vect1, Vector2 vect2) {
        return vect1.x * vect2.y - vect1.y * vect2.x;
    }

    Vector2 Normalize(Vector2 vect) {
        double length = Length(vect);
        return Vector2 (vect.x * length, vect.y * length);
    }
}

#endif