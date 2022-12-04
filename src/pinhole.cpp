#include <iostream>
#include "../header/ray.h"
#include "../header/image.h"


Vec3 ray_color(const Ray& r) {
    Vec3 norm_d = r.get_direction();
    double t = 0.5 * (norm_d.y + 1);
    return (1.0 - t) * Vec3(1) + t * Vec3(0.5, 0.7, 1.0);
}


int main() {
    const int image_width  = 640;
    const int image_height = 480;
    Image img(image_width, image_height);

    double focal_length    = 1.0;

    Vec3 origin   = Vec3(0, 0, 0);
    Vec3 horizon  = Vec3(1, 0, 0);
    Vec3 vertical = Vec3(0, 1, 0);
    Vec3 depth    = Vec3(0, 0, 1);

    for (int x = 0; x < image_width; x++) {
        for (int y = 0; y < image_height; y++) {
            double u = double((2 * x) - image_width)  / image_width;
            double v = double((2 * y) - image_height) / image_height;
            Vec3 direction = horizon * u - vertical * v - depth * focal_length;
            Ray r(origin, direction);
            Vec3 color = (r.get_direction() + 1.0) / 2;
            // Vec3 color = ray_color(r);
            img.set_pixel(x, y, color);
        }
    }

    img.save_png("../image/ray.png");
}