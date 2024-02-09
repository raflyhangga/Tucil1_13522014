#pragma once
#include <string>
#include <iostream>
#include <vector>

class Sequence{
    private:
        std::vector<std::string> seq;
        int reward;
    public:

    Sequence(std::vector<std::string> sequences,int reward);
    std::vector<std::string> getSequence();
    int getReward();
    void printSequence();
};