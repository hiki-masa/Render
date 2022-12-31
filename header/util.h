#ifndef UTIL_H
#define UTIL_H

template <typename T, typename U> T clamp(T x, U min, U max) {
    if (x < min) return min;
    else if (max < x) return max;
    else return x;
}

#endif