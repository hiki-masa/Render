#ifndef AGGREGATE_H
#define AGGREGATE_H
#include <vector>
#include <memory>
#include "sphere.h"

class Aggregate {
    private:
        std::vector<std::shared_ptr<Sphere>> spheres;

    public:
        Aggregate() {}
        Aggregate(const std::vector<std::shared_ptr<Sphere>>& _spheres) : spheres(_spheres) {}

        std::vector<std::shared_ptr<Sphere>> get_spheres() {
            return spheres;
        }

        // 物体の追加
        void add(const std::shared_ptr<Sphere>& s) {
            spheres.push_back(s);
        }

        // 与えられたレイと全ての物体との間で衝突計算を行い，最も手前に存在する物体との衝突情報を返す
        bool intersect(const Ray& ray, Hit& res) const {
            bool hit = false;
            res.distance = Hit::MAX_DISTANCE;

            for (std::shared_ptr<Sphere> s : spheres) {
                Hit res_temp;
                if (s->intersect(ray, res_temp)) {
                    if (res_temp.distance < res.distance) {
                        hit = true;
                        res = res_temp;
                    }
                }
            }
            
            return hit;
        }
};

#endif