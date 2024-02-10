#pragma once
#include <iostream>
#include <fstream>
#include "algorithm.hpp"

std::string resultString(hasil dataHasil, std::vector<Sequence> dataSequence, Matrix dataMatrix, double executionTime, int bufferSize);

void writeToTxt(std::string pathToFIle,std::string resultString);

void resultToTxt(std::string path, hasil dataHasil,std::vector<Sequence> dataSequence, Matrix dataMatrix, double executionTime, int bufferSize);



