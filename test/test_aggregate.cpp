#include <iostream>
#include <cassert>
#include "../header/aggregate.h"

int main() {
    Aggregate a;
    assert(a.get_spheres().size() == 0);

    a.add(std::make_shared<Sphere>(Vec3(0, 0, -3), 1));
    a.add(std::make_shared<Sphere>(Vec3(0, 0, -5), 3));
    a.add(std::make_shared<Sphere>(Vec3(0, 0, -7), 10));

    assert(a.get_spheres().size() == 3);

    Sphere s1 = *(a.get_spheres()[0]);
    Sphere s2 = *(a.get_spheres()[1]);
    Sphere s3 = *(a.get_spheres()[2]);
    assert(s1.center == Vec3(0, 0, -3) && s1.radius == 1);
    assert(s2.center == Vec3(0, 0, -5) && s2.radius == 3);
    assert(s3.center == Vec3(0, 0, -7) && s3.radius == 10);
}