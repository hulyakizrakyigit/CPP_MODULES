#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t len, F func) {
    if (!array) 
        return;
    for (size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

template <typename T, size_t N>
size_t arrayLength(T (&)[N]) {
    return N;
}


#endif