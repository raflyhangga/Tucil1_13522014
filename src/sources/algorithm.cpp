#include "../header/algorithm.hpp"

int recursionCounter = 0;

int countReward(std::vector<std::string> &buffer,std::vector<Sequence> &dataSequence){
    int reward = 0;
    for(int i=0;i<dataSequence.size();i++){
        if(isBufferHasSequence(buffer,dataSequence[i])){
            reward += dataSequence[i].getReward();
        }
    }
    return reward;
}

bool isLangkahSame(Langkah &langkah1, Langkah &langkah2){
    return (langkah1.i == langkah2.i) && (langkah1.j == langkah2.j); 
}

bool isSafe(Langkah &currentTileIdx, std::vector<Langkah> &listLangkah){
    bool cek = true;
    int idx = 0;
    while((idx < listLangkah.size()) && cek){
        if (isLangkahSame(currentTileIdx,listLangkah[idx])){
            cek = false;
            break;
        }
        else {
            idx++;
        }
    }
    return cek;
}

void printListSequence(std::vector<Sequence> sequenceList){
    for (int i=0;i<sequenceList.size();i++){
        sequenceList[i].printSequence();
    }
}

void printListLangkah(std::vector<Langkah> &listLangkah){
    for (int i=0;i<listLangkah.size();i++){
        if(i != listLangkah.size() - 1){
            std::cout<<listLangkah[i].j+1<<" "<<listLangkah[i].i+1<<std::endl;
        } else {
            std::cout<<listLangkah[i].j+1<<" "<<listLangkah[i].i+1;
        }
    }
    std::cout<<std::endl;
}

void printBuffer(std::vector<std::string> &buffer){
    for (int i=0;i<buffer.size();i++){
        std::cout<<buffer[i]<<" ";
    }
    std::cout<<std::endl;
}

void printHasil(hasil dataHasil){
    if (dataHasil.reward != 0){
        std::cout<<"Maximum point: "<<dataHasil.reward<<std::endl;
        std::cout<<"Buffer: ";
        for (int i=0;i<dataHasil.hasilBuffer.size();i++){
            std::cout<<dataHasil.hasilBuffer[i]<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"Langkah: "<<std::endl;
        printListLangkah(dataHasil.hasilLangkah);
    }
    else {
        std::cout<<"There is no solution\n";
    }
}


void findOptimum(Matrix &dataMatrix,int &rewardMaks, std::vector<Langkah> &currentLangkah, bool &isHorizontal, std::vector<std::string> &buffer,int &bufferSize,std::vector<Sequence> &dataSequence, int &idx, hasil &result){
    int tempReward = countReward(buffer,dataSequence);
    recursionCounter++;
    if((buffer.size() == bufferSize) || tempReward > rewardMaks){
        if (tempReward > rewardMaks){
            rewardMaks = tempReward;
            result.hasilLangkah = currentLangkah;
            result.hasilBuffer = buffer;
            result.reward = rewardMaks;
        }
    }
    else {
        if (isHorizontal){
            for (int ptr=0; ptr < dataMatrix.getWidth();ptr++){
                Langkah currentTilePtr;
                currentTilePtr.i = idx;
                currentTilePtr.j = ptr;

                if(isSafe(currentTilePtr,currentLangkah)){
                    bool check = !isHorizontal;
                    std::vector<Langkah> tempCurrentLangkah = currentLangkah;
                    std::vector<std::string> tempBuffer = buffer;
                    tempCurrentLangkah.push_back(currentTilePtr);
                    tempBuffer.push_back(dataMatrix.getValue(currentTilePtr.i,currentTilePtr.j));
                    findOptimum(dataMatrix,rewardMaks,tempCurrentLangkah,check,tempBuffer,bufferSize,dataSequence,ptr,result);
                }
            }
        } 
        else {
            for (int ptr=0; ptr < dataMatrix.getHeight();ptr++){
                Langkah currentTilePtr;
                currentTilePtr.i = ptr;
                currentTilePtr.j = idx;

                if(isSafe(currentTilePtr,currentLangkah) ){
                    bool check = !isHorizontal;
                    std::vector<Langkah> tempCurrentLangkah = currentLangkah;
                    std::vector<std::string> tempBuffer = buffer;
                    tempCurrentLangkah.push_back(currentTilePtr);
                    tempBuffer.push_back(dataMatrix.getValue(currentTilePtr.i,currentTilePtr.j));
                    findOptimum(dataMatrix,rewardMaks,tempCurrentLangkah,check,tempBuffer,bufferSize,dataSequence,ptr,result);
                }
            }
        }
    }
}

hasil findPath(Matrix &dataMatrix,int &bufferSize,std::vector<Sequence> &dataSequence, double &execTime){
    std::vector<Langkah> langkahTemp,langkahOptimum;
    std::vector<std::string> buffer;
    std::vector<hasil> listResult;
    hasil myHasil;

    int rewardMaks = 0;
    int counter = 0;
    int idx = 0;
    bool check = true;

    auto start = std::chrono::high_resolution_clock::now();
    findOptimum(dataMatrix,rewardMaks,langkahOptimum,check,buffer,bufferSize,dataSequence,idx,myHasil);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout<<"Banyak rekursi: "<<recursionCounter<<std::endl;
    execTime = duration.count() * 1000;

    return myHasil;
}