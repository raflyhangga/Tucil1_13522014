#pragma once
#include "sequence.hpp"
#include <string>
#include <vector>

struct Langkah {
    int i;
    int j;
};

bool isBufferHasSequence(std::vector<std::string> &buffer, Sequence &sequenceData);

bool isLangkahEqual(Langkah &langkah, int i, int j );