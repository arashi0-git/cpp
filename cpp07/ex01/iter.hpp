#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>
#include <iostream>
#include <algorithm>

template <class T, class F>
void iter(T *address, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(address[i]);
    }
}

#endif