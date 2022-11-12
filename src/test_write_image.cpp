#include <iostream>
#include <climits>

#define STB_IMAGE_WRITE_STATIC
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../header/stb/stb_image_write.h"

int main() {
    const int image_width  = 256;
    const int image_height = 256;
    const int channels     = 3;
    unsigned char pixels[image_width * image_height * channels];

    for (int h = 0; h < image_height; h++) {
        for (int w = 0; w < image_width; w++) {
            auto r = double(w) / (image_width  - 1);
            auto g = 0.0;
            auto b = double(h) / (image_height - 1);

            unsigned char ir = static_cast<unsigned char>(UCHAR_MAX * r);
            unsigned char ig = static_cast<unsigned char>(UCHAR_MAX * g);
            unsigned char ib = static_cast<unsigned char>(UCHAR_MAX * b);

            pixels[h * (image_width * channels) + w * (channels) + 0] = ir;
            pixels[h * (image_width * channels) + w * (channels) + 1] = ig;
            pixels[h * (image_width * channels) + w * (channels) + 2] = ib;
        }
    }

    stbi_write_png("../image/test.png", image_width, image_height, 3, pixels, image_width * 3);
}