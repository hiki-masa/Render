#include <iostream>
#include "../header/camera.h"
#include "../header/sphere.h"
#include "../header/aggregate.h"


int main() {
    PinholeCamera camera(Vec3(0, 0, 0), Vec3(0, 0, -1), 640, 480, 1.0);

    Aggregate aggregate;
    aggregate.add(std::make_shared<Sphere>(Vec3(0, 0, -3), 1));
    aggregate.add(std::make_shared<Sphere>(Vec3(0, -1001, -3), 1000));

    const int SAMPLE_NUM = 50;
    camera.take_photo(aggregate, SAMPLE_NUM);
    camera.save_photo("../image/rendering.png");
}