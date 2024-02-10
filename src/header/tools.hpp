#pragma once
#include "sequence.hpp"
#include "matrix.hpp"
#include <string>
#include <vector>

struct Langkah {
    int i;
    int j;
};

void isContinue(bool &status);

void startSolver(Matrix &dataMatrix,int &bufferSize,std::vector<Sequence> &dataSequence, double &execTime);

void Clear();

bool isBufferHasSequence(std::vector<std::string> &buffer, Sequence &sequenceData);

bool isLangkahEqual(Langkah &langkah, int i, int j );