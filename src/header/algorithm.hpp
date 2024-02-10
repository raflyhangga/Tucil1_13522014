#pragma once
#include "matrix.hpp"
#include "tools.hpp"
#include <ctime>
#include <chrono>

struct hasil {
    std::vector<std::string> hasilBuffer;
    std::vector<Langkah> hasilLangkah;
    int reward;
};

int countReward(std::vector<std::string> &buffer,std::vector<Sequence> &dataSequence);

bool isLangkahSame(Langkah &langkah1, Langkah &langkah2);

bool isSafe(Langkah &currentTileIdx, std::vector<Langkah> &listLangkah);

void printListLangkah(std::vector<Langkah> &listLangkah);

void printBuffer(std::vector<std::string> &buffer);

void findOptimum(Matrix &dataMatrix,int &rewardMaks, std::vector<Langkah> &currentLangkah, bool &isHorizontal, std::vector<std::string> &buffer,int &bufferSize,std::vector<Sequence> &dataSequence, int &idx, hasil &result);

hasil findPath(Matrix &dataMatrix,int &bufferSize,std::vector<Sequence> &dataSequence, double &execTime);

void printHasil(hasil dataHasil);