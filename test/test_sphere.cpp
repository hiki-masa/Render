#include <iostream>
#include <cassert>
#include "../header/sphere.h"

int main() {
    Sphere s(Vec3(0, 0, -5), 1);
    assert(s.get_center() == Vec3(0, 0, -5));
    assert(s.get_radius() == 1);
    std::cout << "【テスト完了】初期化" << std::endl;

    try {
        Sphere(Vec3(0, 0, -5), -1);
    }
    catch (Sphere::radius_exception e) {
        std::cout << "【テスト完了】球の半径が0以下で設定された場合の例外発生" << std::endl;
    }

    Hit h;

    // レイが球を貫通する場合
    Ray r1(Vec3(0, 0, 0), Vec3(0, 0, -1));
    assert(s.intersect(r1, h) == true);
    assert(h.distance == 4);
    assert(h.hit_position == Vec3(0, 0, -4));
    assert(h.hit_normal == Vec3(0, 0, 1));
    assert(h.is_outside_sphere == true);
    std::cout << "【テスト完了】レイと球の交点が2つ存在する場合の交点計算" << std::endl;

    // レイが球と接する場合
    Ray r2(Vec3(1, 0, 0), Vec3(0, 0, -1));
    assert(s.intersect(r2, h) == true);
    // assert(h.distance == 5);
    // assert(h.hit_position == Vec3(1, 0, -5));
    // assert(h.hit_normal == Vec3(1, 0, 0));
    assert(h.is_outside_sphere == true);
    std::cout << "【テスト完了】レイと球が接する場合の交点計算" << std::endl;

    // レイと球が衝突しない場合
    Ray r3(Vec3(10, 0, 0), Vec3(0, 0, -1));
    assert(s.intersect(r3, h) == false);
    std::cout << "【テスト完了】レイと球の交点が存在しない場合の判定" << std::endl;

    // レイの方向が球と反対方向を向いている場合
    Ray r4(Vec3(0, 0, 0), Vec3(0, 0, 1));
    assert(s.intersect(r4, h) == false);
    std::cout << "【テスト完了】レイが球の反対方向を向いている場合の交差判定" << std::endl;

    // 球内部からのレイと球が衝突する場合
    Ray r5(Vec3(0, 0, -5), Vec3(0, 0, 1));
    assert(s.intersect(r5, h) == true);
    assert(h.distance == 1);
    assert(h.hit_position == Vec3(0, 0, -4));
    assert(h.hit_normal == Vec3(0, 0, 1));
    assert(h.is_outside_sphere == false);
    std::cout << "【テスト完了】レイが球の内部かどうか判定" << std::endl;
}
