#pragma once
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include "matrix.hpp"
#include "sequence.hpp"

int randomNumber(int batasBawah, int batasAtas);


std::vector<std::string> getToken(std::string inputString, int tokenSize);

Matrix randomMatrix(int matrixWidth, int matrixHeight, std::vector<std::string> token);

std::vector<Sequence> randomSequence(int sequenceAmount, int rewardMaksimum, int sequenceMaximumSize, std::vector<std::string> token);