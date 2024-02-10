#pragma once

#include <string>
#include <iostream>
#include <vector>

class Matrix {
    private:
        std::vector<std::vector<std::string>> data;
        int rows;
        int cols;
    public:
        Matrix(int height, int width);

        int getWidth();
        int getHeight();
        bool isInBounds(int i, int j);
        void setValue(int row, int col, std::string value);
        std::string getValue(int row, int col);
        void printValue();
};