#ifndef HIT_H
#define HIT_H
#include "vec3.h"

class Sphere;

class Hit {
    public:
        static const int MAX_DISTANCE = 10000;

        double distance;
        Vec3 hit_position;
        Vec3 hit_normal;
        bool is_outside_sphere;
        const Sphere* hit_sphere;

        Hit() {}
};

#endif