#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _size = n;
}

template <class T>
Array<T>::Array(const Array &other) {
    _size = other._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = other._array[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this == &other)
        return *this;
    delete[] _array;
    _size = other._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
    return *this;
}

template <class T>
Array<T>::~Array() {
    delete[] _array;
}

template <class T>
T &Array<T>::operator[](unsigned int n){
    if (n >= _size)
        throw std::out_of_range("Index is out of array");
    return _array[n];
}

template <class T>
const T &Array<T>::operator[](unsigned int n) const {
    if (n >= _size)
        throw std::out_of_range("Index is out of array");
    return _array[n];
}

template <class T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif