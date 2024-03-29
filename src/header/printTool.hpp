#pragma once
#include <string>
#include "algorithm.hpp"
#include "writefile.hpp"

void isContinue(bool &status);

void startSolver(Matrix &dataMatrix,int &bufferSize,std::vector<Sequence> &dataSequence, double &execTime);

void Clear();