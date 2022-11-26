#include <iostream>
#include <cassert>
#include "../header/vec3.h"
#include "../header/ray.h"

int main() {
    Vec3 o(1, 2, 3);
    Vec3 d(1, 0, 0);
    Ray  r(o, d);

    Vec3 tmp = r(5);
    assert(tmp.x == 6 && tmp.y == 2 && tmp.z == 3);
    std::cout << "【テスト完了】レイ計算式" << std::endl;
}