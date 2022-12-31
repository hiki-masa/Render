#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <time.h>

template <typename T, typename U> T clamp(T x, U min, U max) {
    if (x < min) return min;
    else if (max < x) return max;
    else return x;
}


template <typename T> T rnd(T min, T max) {
    // TODO: int型の場合，maxの値が滅多に出現しないバグの修正
    static bool init_flag = false;

    if (init_flag == false) {
        srand((unsigned int)time(NULL));
        init_flag = true;
    }
    
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

#endif