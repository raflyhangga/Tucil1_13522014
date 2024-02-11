#include "../header/matrix.hpp"

Matrix::Matrix(int height, int width): rows(height),cols(width){
    this->data = new std::string * [rows];
    for(int i=0;i<rows;i++){
        this->data[i] = new std::string [cols];
    }

    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            this->data[i][j] = "NULL";
        }
    }
}

int Matrix::getWidth(){
    return this->cols;
}

int Matrix::getHeight(){
    return this->rows;
}

bool Matrix::isInBounds(int i, int j){
    return ((i >= 0) && (i < this->rows) && (j >= 0) && (j < this->cols));
}

void Matrix::setValue(int row, int col, std::string token){
    if (isInBounds(row,col)){
        this->data[row][col] = token;
    } else {
        std::cerr << "Index tidak valid. Tidak bisa menge-set token" << std::endl;
    }
}

std::string Matrix::getValue(int row, int col){
    if(isInBounds(row,col)){
        return this->data[row][col];
    } else {
        std::cerr << "Index tidak valid. Tidak bisa mengembalikan nilai" << std::endl;
        return "NaS";
    }
}

void Matrix::printValue(){
    std::cout<<"Height: "<<this->getHeight()<<std::endl;
    std::cout<<"Width: "<<this->getWidth()<<std::endl;
    for (int i = 0; i < this->getHeight(); ++i) {
        for (int j = 0; j < this->getWidth(); ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

