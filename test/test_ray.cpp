#include <iostream>
#include <cassert>
#include "../header/vec3.h"
#include "../header/ray.h"

int main() {
    Vec3 o(1, 2, 3);
    Vec3 d(10, 0, 0);
    Ray  r(o, d);

    // コンストラクタのテスト
    Vec3 tmp;
    tmp = r.get_origin();
    assert(tmp.x == 1 && tmp.y == 2 && tmp.z == 3);
    tmp = r.get_direction();
    assert(tmp.x == 1 && tmp.y == 0 && tmp.z == 0);
    std::cout << "【テスト完了】初期化" << std::endl;
    
    // レイ計算式のテスト
    tmp = r(5);
    assert(tmp.x == 6 && tmp.y == 2 && tmp.z == 3);
    std::cout << "【テスト完了】レイ計算式" << std::endl;
}