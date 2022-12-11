#ifndef HIT_H
#define HIT_H
#include "vec3.h"

class Sphere;

class Hit {
    public:
        double MAX_DISTANCE = 10000.0;
        double distance;
        Vec3 hit_position;
        Vec3 hit_normal;
        const Sphere* hit_sphere;

        Hit() {}
};

#endif