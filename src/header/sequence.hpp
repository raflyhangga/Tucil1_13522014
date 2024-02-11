#pragma once
#include <string>
#include <iostream>
#include "arraydin.hpp"

class Sequence{
    private:
        Arraydin<std::string> seq;
        int reward;
    public:

    Sequence(Arraydin<std::string> &sequences,int reward);
    std::string stringSequence();
    Arraydin<std::string> getSequence();
    int getReward();
    void printSequence();
};