#pragma once
#include <string>
#include "structs.hpp"

template <typename T>
class Arraydin {
    public:
    T* data;
    int length;
    Arraydin();
    ~Arraydin();
    void push_back(T value);
    int size();
};