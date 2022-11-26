#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "vec3.h"

class Ray {
    private:
        // レイの始点座標
        Vec3 origin;
        // レイの方向
        Vec3 direction;

    public:
        // コンストラクタ
        // レイの方向ベクトルが正規化されていない場合は，正規化して格納
        Ray(const Vec3& _origin, const Vec3& _direction) :
            origin(_origin), direction(_direction) {}

        // r = o + t * d
        Vec3 operator()(double t) {
            return origin + t * direction;
        }

        // コンソール出力
        inline friend std::ostream& operator<<(std::ostream& stream, const Ray& r) {
            stream << "origin    : " << r.origin << "\ndirection : " << r.direction << ")";
            return stream;
        }
};

#endif