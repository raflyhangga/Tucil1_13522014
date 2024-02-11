#pragma once
#include "matrix.hpp"
#include "tools.hpp"
#include <ctime>
#include <chrono>

struct hasil {
    Arraydin<std::string> hasilBuffer;
    Arraydin<Langkah> hasilLangkah;
    int reward;
};

int countReward(Arraydin<std::string> &buffer,Arraydin<Sequence> &dataSequence);

bool isLangkahSame(Langkah &langkah1, Langkah &langkah2);

bool isSafe(Langkah &currentTileIdx, Arraydin<Langkah> &listLangkah);

void printListLangkah(Arraydin<Langkah> &listLangkah);

void printBuffer(Arraydin<std::string> &buffer);

void findOptimum(Matrix &dataMatrix,int &rewardMaks, Arraydin<Langkah> &currentLangkah, bool &isHorizontal, Arraydin<std::string> &buffer,int &bufferSize,Arraydin<Sequence> &dataSequence, int &idx, hasil &result);

hasil findPath(Matrix &dataMatrix,int &bufferSize,Arraydin<Sequence> &dataSequence, double &execTime);

void printHasil(hasil dataHasil);