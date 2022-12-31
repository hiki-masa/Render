#include <iostream>
#include <cassert>
#include "../header/util.h"

int main() {
    int tmp_i = 123;
    assert(clamp(tmp_i,   0, 150) == 123);
    assert(clamp(tmp_i,   0, 100) == 100);
    assert(clamp(tmp_i, 130, 150) == 130);

    assert(clamp(tmp_i,   0.0, 150.0) == 123);
    assert(clamp(tmp_i,   0.0, 100.0) == 100);
    assert(clamp(tmp_i, 130.0, 150.0) == 130);
    std::cout << "【テスト完了】int型でのclamp関数" << std::endl;


    double tmp_d = 12.3;
    assert(clamp(tmp_d,  0.0, 15.0) == 12.3);
    assert(clamp(tmp_d,  0.0, 10.0) == 10.0);
    assert(clamp(tmp_d, 13.0, 15.0) == 13.0);

    assert(clamp(tmp_d,  0, 15) == 12.3);
    assert(clamp(tmp_d,  0, 10) == 10.0);
    assert(clamp(tmp_d, 13, 15) == 13.0);
    std::cout << "【テスト完了】double型でのclamp関数" << std::endl;
}