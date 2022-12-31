#include <iostream>
#include <cassert>
#include "../header/vec3.h"

int main() {
    // コンストラクタのテスト
    Vec3 v0;
    assert(v0.x == 0.0 && v0.y == 0.0 && v0.z == 0.0);
    std::cout << "【テスト完了】引数無し初期化" << std::endl;
    Vec3 v1(5);
    assert(v1.x == 5.0 && v1.y == 5.0 && v1.z == 5.0);
    std::cout << "【テスト完了】１引数初期化" << std::endl;
    Vec3 v2(1, 2, 3);
    assert(v2.x == 1.0 && v2.y == 2.0 && v2.z == 3.0);
    std::cout << "【テスト完了】３引数初期化" << std::endl;

    // 正規化関連のテスト
    Vec3 v3;
    v3 = Vec3(0.1, 0, 0);
    assert(v3.norm() == 0.1);
    assert(v3.normalize().x == 1.0 && v3.normalize().y == 0.0 && v3.normalize().z == 0.0);
    v3 = Vec3(3, 4, 0);
    assert(v3.norm() == 5);
    assert(v3.normalize().x == 0.6 && v3.normalize().y == 0.8 && v3.normalize().z == 0.0);
    std::cout << "【テスト完了】ノルム値計算 + 正規化" << std::endl;

    // イコールのテスト
    Vec3 tmp;
    tmp = v2;
    assert((v2 == Vec3(1, 2, 3)) == true);
    assert((v2 == Vec3(2, 2, 3)) == false);
    assert((v2 == Vec3(1, 1, 3)) == false);
    assert((v2 == Vec3(1, 2, 4)) == false);
    assert((v2 == Vec3(3, 1, 2)) == false);
    std::cout << "【テスト完了】イコール演算子" << std::endl;

    // マイナスのテスト
    tmp = -v2;
    assert(tmp.x == -1 && tmp.y == -2 && tmp.z == -3);
    std::cout << "【テスト完了】マイナス演算子" << std::endl;

    // ベクトル同士の演算
    tmp = v1 + v2;
    assert(tmp.x == 6 && tmp.y == 7 && tmp.z == 8);
    tmp += v2;
    assert(tmp.x == 7 && tmp.y == 9 && tmp.z == 11);
    std::cout << "【テスト完了】ベクトル同士の加算" << std::endl;
    tmp = v1 - v2;
    assert(tmp.x == 4 && tmp.y == 3 && tmp.z == 2);
    tmp -= v2;
    assert(tmp.x == 3 && tmp.y == 1 && tmp.z == -1);
    std::cout << "【テスト完了】ベクトル同士の減算" << std::endl;
    tmp = v1 * v2;
    assert(tmp.x == 5 && tmp.y == 10 && tmp.z == 15);
    tmp *= v2;
    assert(tmp.x == 5 && tmp.y == 20 && tmp.z == 45);
    std::cout << "【テスト完了】ベクトル同士の乗算" << std::endl;
    tmp = v1 / v2;
    assert(tmp.x == 5 && tmp.y == 2.5 && tmp.z == 5.0 / 3);
    tmp /= v2;
    assert(tmp.x == 5 && tmp.y == 1.25 && tmp.z == 5.0 / 9);
    std::cout << "【テスト完了】ベクトル同士の除算" << std::endl;

    // ベクトルとスカラーの演算
    tmp = v2 + 1;
    assert(tmp.x == 2 && tmp.y == 3 && tmp.z == 4);
    tmp = 1 + v2;
    assert(tmp.x == 2 && tmp.y == 3 && tmp.z == 4);
    tmp += 1;
    assert(tmp.x == 3 && tmp.y == 4 && tmp.z == 5);
    std::cout << "【テスト完了】ベクトルとスカラーの加算" << std::endl;
    tmp = v2 - 1;
    assert(tmp.x == 0 && tmp.y == 1 && tmp.z == 2);
    tmp = 1 - v2;
    assert(tmp.x == 0 && tmp.y == -1 && tmp.z == -2);
    tmp -= 1;
    assert(tmp.x == -1 && tmp.y == -2 && tmp.z == -3);
    std::cout << "【テスト完了】ベクトルとスカラーの減算" << std::endl;
    tmp = v2 * 5;
    assert(tmp.x == 5 && tmp.y == 10 && tmp.z == 15);
    tmp = 5 * v2;
    assert(tmp.x == 5 && tmp.y == 10 && tmp.z == 15);
    tmp *= 5;
    assert(tmp.x == 25 && tmp.y == 50 && tmp.z == 75);
    std::cout << "【テスト完了】ベクトルとスカラーの乗算" << std::endl;
    tmp = v2 / 5;
    assert(tmp.x == 0.2 && tmp.y == 0.4 && tmp.z == 0.6);
    tmp = 5 / v2;
    assert(tmp.x == 5 && tmp.y == 2.5 && tmp.z == 5.0 / 3);
    tmp /= 2;
    assert(tmp.x == 2.5 && tmp.y == 1.25 && tmp.z == 5.0 / 6);
    std::cout << "【テスト完了】ベクトルとスカラーの除算" << std::endl;

    // 内積の計算
    int dot_val = dot(v1, v2);
    assert(dot_val == 30);
    std::cout << "【テスト完了】内積計算" << std::endl;

    // 外積の計算
    tmp = cross(v1, v2);
    assert(tmp.x == 5 && tmp.y == -10 && tmp.z == 5);
    std::cout << "【テスト完了】外積計算" << std::endl;
}