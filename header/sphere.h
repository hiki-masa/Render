#ifndef SPHERE_H
#define SPHERE_H
#include <cmath>
#include "vec3.h"
#include "ray.h"
#include "hit.h"

class Sphere {
    public:
        Vec3 center;
        double radius;

        Sphere(const Vec3& _center, const double _radius) : center(_center), radius(_radius) {}

        bool intersect(const Ray& ray, Hit& res) const {
            double a = 1.0;
            double b = dot(ray.get_direction(), ray.get_origin() - center);
            double c = pow((ray.get_origin() - center).norm(), 2) - pow(radius, 2);

            double D = b * b - a * c;
            double distance;

            // D < 0 の場合，交差していない
            if (D < 0) return false;

            // D = 0 の場合，接する
            else if (D == 0) {
                distance = -b;
            }

            // D > 0 の場合，2点で交差する
            else {
                double d1 = -b - std::sqrt(D);
                double d2 = -b + std::sqrt(D);

                // レイの飛ばした逆方向で交差している場合
                if (d1 < 0 & d2 < 0) return false;

                // 交差地点が非常に遠い場合
                if (d1 > res.MAX_DISTANCE & d2 > res.MAX_DISTANCE) return false;

                if (0 < d1 & d1 < res.MAX_DISTANCE) {
                    distance = d1;
                }
                else if (0 < d2 & d2 < res.MAX_DISTANCE) {
                    distance = d2;
                }
            }

            res.distance     = distance;
            res.hit_position = ray(distance);
            res.hit_normal   = (res.hit_position - center).normalize();
            res.hit_sphere   = this;

            return true;
        }
};

#endif