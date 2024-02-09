#include "../sequence.hpp"

Sequence::Sequence(std::vector<std::string> sequences,int reward):seq(sequences),reward(reward){
    this->seq = sequences;
    this->reward = reward;
}

std::vector<std::string> Sequence::getSequence(){
    return this->seq;
}

int Sequence::getReward(){
    return this->reward;
}

void Sequence::printSequence(){
    std::cout<<"Sequence: ";
    for (int i=0; i<this->seq.size(); i++){
        std::cout<<this->seq[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Reward: "<<this->reward<<"\n";
}