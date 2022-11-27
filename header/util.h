#ifndef UTIL_H
#define UTIL_H

template <typename T> T clamp(T x, T min, T max) {
    if (x < min) return min;
    else if (max < x) return max;
    else return x;
}

#endif