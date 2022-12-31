#ifndef SPHERE_H
#define SPHERE_H
#include <cmath>
#include "vec3.h"
#include "ray.h"
#include "hit.h"

class Sphere {
    private:
        Vec3 center;
        double radius;

        bool is_outside(const Ray& r, const Vec3& normal) const {
            // レイと法線の内積が0以上の場合，レイは内側に存在する
            if (dot(r.get_direction(), normal) > 0) return false;
            // レイと法線の内積が0以下の場合，レイは外側に存在する
            else return true;
        }

    public:
        Sphere(const Vec3& _center, const double _radius) : center(_center), radius(_radius) {
            if (_radius <= 0) {
                std::cerr << radius_exception().what() << std::endl;
                throw radius_exception();
            }
        }

        // コンソール出力
        inline friend std::ostream& operator<<(std::ostream& stream, const Sphere& s) {
            stream << "center : " << s.center << "\nradius : " << s.radius;
            return stream;
        }

        // ゲッター
        Vec3 get_center() {
            return center;
        }

        double get_radius() {
            return radius;
        }

        // 与えられたレイとの衝突判定
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
                if (d1 < 0 && d2 < 0) return false;

                // 交差地点が非常に遠い場合
                if (d1 > Hit::MAX_DISTANCE & d2 > Hit::MAX_DISTANCE) return false;

                if (0 < d1 && d1 < Hit::MAX_DISTANCE) {
                    distance = d1;
                }
                else if (0 < d2 && d2 < Hit::MAX_DISTANCE) {
                    distance = d2;
                }
            }

            res.distance     = distance;
            res.hit_position = ray(distance);
            res.hit_normal   = (res.hit_position - center).normalize();
            res.is_outside_sphere = is_outside(ray, res.hit_normal);
            res.hit_sphere   = this;

            return true;
        }

        class radius_exception {
            private:
                const char* msg = "The radius of the sphere is set less than or equal to 0";
            public:
                radius_exception() {}
                const char* what() {return msg;}
        };
};

#endif