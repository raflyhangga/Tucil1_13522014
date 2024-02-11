#include "../header/fieldgenerator.hpp"

int randomNumber(int batasBawah, int batasAtas){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int>  distr(batasBawah, batasAtas);
    return distr(generator);
}


Arraydin<std::string> getToken(std::string inputString, int tokenSize){
    std::string lineString,token;
    Arraydin<std::string> tokenData;
    std::stringstream ss(inputString);
    std::getline(ss,lineString);
    std::stringstream lineStream(lineString);

    while(tokenSize--){
        lineStream >> token;
        tokenData.push_back(token);
    }
    return tokenData;
}

Matrix randomMatrix(int matrixWidth, int matrixHeight, Arraydin<std::string> token){
    Matrix dataMatrix(matrixHeight,matrixWidth);
    for(int i=0; i<matrixHeight; i++){
        for(int j=0; j<matrixWidth;j++){
            std::string randomToken = token.data[randomNumber(0,token.size()-1)];
            dataMatrix.setValue(i,j,randomToken);
        }
    }
    return dataMatrix;
}

Arraydin<Sequence> randomSequence(int sequenceAmount, int rewardMaksimum, int sequenceMaximumSize, Arraydin<std::string> token){
    Arraydin<Sequence> sequencesData;
    while(sequenceAmount--){
        int sequenceSize = randomNumber(2,sequenceMaximumSize);
        Arraydin<std::string> sequenceToken;
        while(sequenceSize--){
            std::string randomToken = token.data[randomNumber(0,token.size()-1)];
            sequenceToken.push_back(randomToken);
        }
        int sequenceReward = randomNumber(1,rewardMaksimum);
        Sequence aSequence(sequenceToken,sequenceReward);
        sequencesData.push_back(aSequence);
    }

    return sequencesData;
}