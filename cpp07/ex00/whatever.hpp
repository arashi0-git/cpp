#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>
#include <iostream>

template <class T>
void  swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
        
template <class T>
const T &min(const T &c, const T &d) {
    return (c < d) ? c : d;
}

template <class T>
const T &max(const T &e, const T &f) {
    return (e > f) ? e : f;
}

#endif