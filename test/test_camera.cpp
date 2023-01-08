#include <iostream>
#include <cassert>
#include "../header/camera.h"


int main() {
    Camera c1(Vec3(0, 0, 0), Vec3(0, 0, 1), 640, 480);
    assert(c1.get_camera_forward() == Vec3(0, 0, 1));
    assert(c1.get_camera_right() == Vec3(-1, 0, 0));
    assert(c1.get_camera_up() == Vec3(0, 1, 0));

    Camera c2(Vec3(0, 0, 0), Vec3(0, 0, -1), 640, 480);
    assert(c2.get_camera_forward() == Vec3(0, 0, -1));
    assert(c2.get_camera_right() == Vec3(1, 0, 0));
    assert(c2.get_camera_up() == Vec3(0, 1, 0));

    Camera c3(Vec3(0, 0, 0), Vec3(1, 0, 0), 640, 480);
    assert(c3.get_camera_forward() == Vec3(1, 0, 0));
    assert(c3.get_camera_right() == Vec3(0, 0, 1));
    assert(c3.get_camera_up() == Vec3(0, 1, 0));

    PinholeCamera pc(Vec3(0, 0, 0), Vec3(0, 0, -1), 640, 480, 1);
    pc.take_photo();
    pc.save_photo("../image/test_camera.png");
}
