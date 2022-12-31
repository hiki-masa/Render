#include <iostream>
#include <cassert>
#include "../header/aggregate.h"

int main() {
    Aggregate a;
    assert(a.get_spheres().size() == 0);
    std::cout << "【テスト完了】引数無し初期化" << std::endl;

    a.add(std::make_shared<Sphere>(Vec3(0, 0, -3), 1));
    a.add(std::make_shared<Sphere>(Vec3(0, 0, -5), 3));
    a.add(std::make_shared<Sphere>(Vec3(0, 0, -7), 10));

    assert(a.get_spheres().size() == 3);

    Sphere s1 = *(a.get_spheres()[0]);
    Sphere s2 = *(a.get_spheres()[1]);
    Sphere s3 = *(a.get_spheres()[2]);
    assert(s1.get_center() == Vec3(0, 0, -3) && s1.get_radius() == 1);
    assert(s2.get_center() == Vec3(0, 0, -5) && s2.get_radius() == 3);
    assert(s3.get_center() == Vec3(0, 0, -7) && s3.get_radius() == 10);
    std::cout << "【テスト完了】addメソッド" << std::endl;
}