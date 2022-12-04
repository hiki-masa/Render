#include <iostream>
#include <cassert>
#include "../header/image.h"

int main() {
    int image_width  = 640;
    int image_height = 480;
    Image i(image_width, image_height);

    for (int w = 0; w < image_width; w++) {
        for (int h = 0; h < image_height; h++) {
            auto r = double(w) / (image_width  - 1);
            auto g = 0.0;
            auto b = double(h) / (image_height - 1);

            Vec3 c(r, g, b);
            i.set_pixel(w, h, c);
        }
    }
    i.save_png("../image/test_color.png");

    for (int w = 0; w < image_width; w++) {
        for (int h = 0; h < image_height; h++) {
            auto g = double(h) / (image_height - 1);

            i.set_pixel(w, h, g);
        }
    }
    i.save_png("../image/test_gray.png");

    i.gamma_correction();
    i.save_png("../image/gamma_correction.png");
}