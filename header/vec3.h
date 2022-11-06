#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class Vec3 {
    public:
        // メンバ変数
        double x, y, z;

        // コンストラクタ
        Vec3()                                : x(.0), y(.0), z(.0) {};
        Vec3(double _i)                       : x(_i), y(_i), z(_i) {};
        Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};

        // デストラクタ
        ~Vec3() {};

        // ノルム値
        double norm() {
            return std::sqrt(x * x + y * y + z * z);
        };
        
        // 正規化
        Vec3 normalize() {
            return Vec3(
                this->x / norm(),
                this->y / norm(),
                this->z / norm()
            );
        };
};

// ベクトル同士の演算
Vec3 operator+ (const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator- (const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator* (const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vec3 operator/ (const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

// ベクトルとスカラーの演算
Vec3 operator+ (const Vec3& v, const double s) {
    return Vec3(v.x + s, v.y + s, v.z + s);
}

Vec3 operator+ (const double s, const Vec3& v) {
    return v + s;
}

Vec3 operator- (const Vec3& v, const double s) {
    return Vec3(v.x - s, v.y - s, v.z - s);
}

Vec3 operator- (const double s, const Vec3& v) {
    return Vec3(s - v.x, s - v.y, s - v.z);
}

Vec3 operator* (const Vec3& v, const double s) {
    return Vec3(v.x * s, v.y * s, v.z * s);
}

Vec3 operator* (const double s, const Vec3& v) {
    return v * s;
}

Vec3 operator/ (const Vec3& v, const double s) {
    return Vec3(v.x / s, v.y / s, v.z / s);
}

Vec3 operator/ (const double s, const Vec3& v) {
    return Vec3(s / v.x, s / v.y, s / v.z);
}

// 内積
double dot(const Vec3& v1, const Vec3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 外積
Vec3 cross(const Vec3& v1, const Vec3& v2) {
    return Vec3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

// コンソール出力
std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

#endif