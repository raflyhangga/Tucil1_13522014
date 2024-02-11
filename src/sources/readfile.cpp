#include "../header/readfile.hpp"

std::string getText(std::string pathToFile){
    std::ifstream myFile(pathToFile);

    std::string data,line;

    while(std::getline(myFile,line)){
        data += line + "\n";
    }
    return data;
}

int getBufferSize(std::string pathToFile){
    std::string line;
    std::string data = getText(pathToFile);
    std::stringstream stream(data);
    std::getline(stream,line);

    return std::stoi(line);
}

Matrix getMatrix(std::string pathToFile){
    int width,height;
    std::string word,matrRowString,line;
    std::string data = getText(pathToFile);
    std::stringstream mainstream(data);
    std::getline(mainstream,line);
    std::getline(mainstream,line);
    std::stringstream linestream(line);
    linestream>>word;
    width = std::stoi(word);
    linestream>>word;
    height = std::stoi(word);

    Matrix mat(height,width);
    for (int i=0;i<height;i++){
        std::getline(mainstream,matrRowString);
        std::stringstream rowstream(matrRowString);
        std::string token;
        for (int j=0;j<width;j++){
            rowstream>>token;
            mat.setValue(i,j,token.c_str());
        }
    }
    return mat;
}

Arraydin<Sequence> getSequences(std::string pathToFile){
    std::string line,word;
    int height;
    std::string data = getText(pathToFile);
    std::stringstream mainstream(data);
    std::getline(mainstream,line);
    std::getline(mainstream,line);
    std::stringstream linestream(line);
    linestream>>word;
    linestream>>word;
    height = std::stoi(word);

    while(height--){
        std::getline(mainstream,line);
    }

    std::getline(mainstream,line);

    Arraydin<Sequence> seqLists;
    int sequenceLength = std::stoi(line);
    int idx = sequenceLength;
    while(idx--){
        std::string sequenceString,sequence;
        Arraydin<std::string> sequenceList;
        int reward;
        std::getline(mainstream,line);
        sequenceString = line.c_str();
        std::getline(mainstream,line);
        reward = std::stoi(line);

        std::stringstream sequenceStream(sequenceString);
        while(sequenceStream>>sequence){
            sequenceList.push_back(sequence);
        }
        Sequence mySequence(sequenceList,reward);
        seqLists.push_back(mySequence);
    }

    return seqLists;
}