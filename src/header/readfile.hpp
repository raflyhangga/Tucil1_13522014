#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "matrix.hpp"
#include "sequence.hpp"
// using namespace std;

std::string getText(std::string pathToFile);
// Mengembalikan isi .txt dalam bentuk string

int getBufferSize(std::string pathToFile);
// Mengambalikan buffer size yang diperoleh dari .txt

Matrix getMatrix(std::string pathToFile);
// Mengambalikan matriks size yang diperoleh dari .txt

std::vector<Sequence> getSequences(std::string pathToFile);
// Mengambalikan seluruh sequence dalam bentuk matriks size yang diperoleh dari .txt