#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"
#include "image.h"


class Camera {
    protected:
        double aspect_ratio;
        Image image;
        // ワールド座標系でのカメラの座標，向き（前後・左右・上下）を格納
        Vec3 camera_position;
        Vec3 camera_forward;
        Vec3 camera_right;
        Vec3 camera_up;

    public:
        // コンストラクタ
        Camera(const Vec3& _camera_position, const Vec3& _camera_forward, const int image_width, const int image_height) :
            camera_position(_camera_position), aspect_ratio(double(image_width) / image_height),
            camera_forward(_camera_forward.normalize()), camera_up(Vec3(0, 1, 0)) {
                image = Image(image_width, image_height);

                camera_right = cross(camera_forward,camera_up);
            }

        // ゲッター
        Vec3 get_camera_forward() {return camera_forward;}
        Vec3 get_camera_right() {return camera_right;}
        Vec3 get_camera_up() {return camera_up;} 
};


class PinholeCamera : private Camera {
    private:
        double pinhole_distance;

        Ray calc_ray(double u, double v) {
            // 縦横比のズレを修正するための補正
            u = u * aspect_ratio;

            Vec3 direction = camera_right * u + camera_up * v + camera_forward * pinhole_distance;
            return Ray(camera_position, direction);
        }

    public:
        // コンストラクタ
        PinholeCamera(const Vec3& _camera_position, const Vec3& _camera_forward, const int image_width, const int image_height, const double _pinhole_distance) :
            Camera(_camera_position, _camera_forward, image_width, image_height), pinhole_distance(_pinhole_distance) {}

        void take_photo() {
            for (int x = 0; x < image.get_width(); x++) {
                for (int y = 0; y < image.get_height(); y++) {
                    double u = double((2 * x - image.get_width())) / image.get_width();
                    double v = double((image.get_height() - 2 * y)) / image.get_height();
                    Ray r = calc_ray(u, v);

                    Vec3 color = (r.get_direction() + 1.0) / 2;
                    image.set_pixel(x, y, color);
                }
            }
        }

        void save_photo(const char* output_filepath) const {
            image.save_png(output_filepath);
        }
};

#endif