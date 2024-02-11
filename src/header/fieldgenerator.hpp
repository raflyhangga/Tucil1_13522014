#pragma once
#include <string>
#include <random>
#include <sstream>
#include "matrix.hpp"
#include "sequence.hpp"
#include "arraydin.hpp"

int randomNumber(int batasBawah, int batasAtas);


Arraydin<std::string> getToken(std::string inputString, int tokenSize);

Matrix randomMatrix(int matrixWidth, int matrixHeight, Arraydin<std::string> token);

Arraydin<Sequence> randomSequence(int sequenceAmount, int rewardMaksimum, int sequenceMaximumSize, Arraydin<std::string> token);