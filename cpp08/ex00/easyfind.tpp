#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <class T>
bool easyfind(const T &container, int value) {
    if (std::find(container.begin(), container.end(), value) != container.end()) {
        return true;
    } else {
        return false;
    }
}

#endif