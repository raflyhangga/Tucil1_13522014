#pragma once

#include <string>
#include <iostream>
#include "arraydin.hpp"

class Matrix {
    private:
        // Arraydin<Arraydin<std::string>> data;
        int rows;
        int cols;
        std::string** data;
    public:
        Matrix(int height, int width);

        int getWidth();
        int getHeight();
        bool isInBounds(int i, int j);
        void setValue(int row, int col, std::string value);
        std::string getValue(int row, int col);
        void printValue();
};