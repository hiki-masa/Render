#include <iostream>
#include <cassert>
#include "../header/sphere.h"

int main() {
    Sphere s(Vec3(0, 0, -5), 1);
    Hit h;

    // レイが球を貫通する場合
    Ray r1(Vec3(0, 0, 0), Vec3(0, 0, -1));
    assert(s.intersect(r1, h) == true);
    assert(h.distance == 4);
    assert(h.hit_position == Vec3(0, 0, -4));
    assert(h.hit_normal == Vec3(0, 0, 1));

    // レイが球と接する場合
    Ray r2(Vec3(1, 0, 0), Vec3(0, 0, -1));
    assert(s.intersect(r2, h) == true);
    // assert(h.distance == 5);
    // assert(h.hit_position == Vec3(1, 0, -5));
    // assert(h.hit_normal == Vec3(1, 0, 0));

    // レイと球が衝突しない場合
    Ray r3(Vec3(10, 0, 0), Vec3(0, 0, -1));
    assert(s.intersect(r3, h) == false);

    // レイの方向が球と反対方向を向いている場合
    Ray r4(Vec3(0, 0, 0), Vec3(0, 0, 1));
    assert(s.intersect(r4, h) == false);
}
