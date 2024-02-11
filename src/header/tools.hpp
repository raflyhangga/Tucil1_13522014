#pragma once
#include "sequence.hpp"
#include "matrix.hpp"
#include <string>
#include "arraydin.hpp"
#include "structs.hpp"

void isContinue(bool &status);

void startSolver(Matrix &dataMatrix,int &bufferSize,Arraydin<Sequence> &dataSequence, double &execTime);

void Clear();

bool isBufferHasSequence(Arraydin<std::string> &buffer, Sequence &sequenceData);

bool isLangkahEqual(Langkah &langkah, int i, int j );