#include "../readfile.hpp"
#include "../tools.hpp"
#include <chrono>

struct hasil {
    std::vector<std::string> hasilBuffer;
    std::vector<Langkah> hasilLangkah;
};

int countReward(std::vector<std::string> buffer,std::vector<Sequence> dataSequence){
    int reward = 0;
    for(int i=0;i<dataSequence.size();i++){
        if(isBufferHasSequence(buffer,dataSequence[i])){
            reward += dataSequence[i].getReward();
        }
    }
    return reward;
}

bool isLangkahSame(Langkah langkah1, Langkah langkah2){
    return (langkah1.i == langkah2.i) && (langkah1.j == langkah2.j); 
}

bool isSafe(Langkah currentTileIdx, std::vector<Langkah> listLangkah){
    bool cek = true;
    int idx = 0;
    while((idx < listLangkah.size()) && cek){
        if (isLangkahSame(currentTileIdx,listLangkah[idx])){
            cek = false;
        }
        else {
            idx++;
        }
    }
    return cek;
}

void printListLangkah(std::vector<Langkah> listLangkah){
    for (int i=0;i<listLangkah.size();i++){
        std::cout<<"("<<listLangkah[i].i<<","<<listLangkah[i].j<<") ";
    }
    std::cout<<std::endl;
}

void printBuffer(std::vector<std::string> buffer){
    for (int i=0;i<buffer.size();i++){
        std::cout<<buffer[i]<<" ";
    }
    std::cout<<std::endl;
}


void findOptimum(Matrix &dataMatrix,int &rewardMaks, std::vector<Langkah> &currentLangkah, bool isHorizontal, std::vector<std::string> &buffer,int bufferSize,std::vector<Sequence> &dataSequence, int idx, hasil &result){
    int tempReward = countReward(buffer,dataSequence);
    if((buffer.size() == bufferSize) || tempReward > rewardMaks){
        if (tempReward > rewardMaks){
            rewardMaks = tempReward;
            result.hasilLangkah = currentLangkah;
            result.hasilBuffer = buffer;
        }
    }
    else {
        if (isHorizontal){
            for (int ptr=0; ptr < dataMatrix.getWidth();ptr++){
                Langkah currentTilePtr;
                currentTilePtr.i = idx;
                currentTilePtr.j = ptr;

                if(isSafe(currentTilePtr,currentLangkah)){
                    std::vector<Langkah> tempCurrentLangkah = currentLangkah;
                    std::vector<std::string> tempBuffer = buffer;
                    tempCurrentLangkah.push_back(currentTilePtr);
                    tempBuffer.push_back(dataMatrix.getValue(idx,ptr));
                    findOptimum(dataMatrix,rewardMaks,tempCurrentLangkah,!isHorizontal,tempBuffer,bufferSize,dataSequence,ptr,result);
                }
            }
        } 
        else {
            for (int ptr=0; ptr < dataMatrix.getHeight();ptr++){
                Langkah currentTilePtr;
                currentTilePtr.i = ptr;
                currentTilePtr.j = idx;

                if(isSafe(currentTilePtr,currentLangkah) ){
                    std::vector<Langkah> tempCurrentLangkah = currentLangkah;
                    std::vector<std::string> tempBuffer = buffer;
                    tempCurrentLangkah.push_back(currentTilePtr);
                    tempBuffer.push_back(dataMatrix.getValue(ptr,idx));
                    findOptimum(dataMatrix,rewardMaks,tempCurrentLangkah,!isHorizontal,tempBuffer,bufferSize,dataSequence,ptr,result);
                }
            }
        }
    }
}

int main(){
    Matrix dataMatriks = getMatrix("src/tes.txt");
    std::vector<Sequence> dataSequence = getSequences("src/tes.txt");
    std::vector<Langkah> langkahTemp,langkahOptimum;
    std::vector<std::string> buffer;
    hasil myHasil;
    int rewardMaks = INT16_MIN;
    int bufferSize = getBufferSize("src/tes.txt");
    int counter = 0;

    std::cout<<"Matriks terbaca:"<<std::endl;
    dataMatriks.printValue();
    std::cout<<"Buffer Size: "<<bufferSize<<std::endl;

    std::cout<<"Please wait";
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i=0;i<dataMatriks.getWidth();i++){
        findOptimum(dataMatriks,rewardMaks,langkahOptimum,true,buffer,bufferSize,dataSequence,i,myHasil);
        std::cout<<".";
    }
    std::cout<<std::endl;
    auto endTime = std::chrono::high_resolution_clock::now();

    std::cout<<"Reward Maksimum: "<<rewardMaks<<std::endl;
    std::cout<<"Buffer : ";
    printBuffer(myHasil.hasilBuffer);
    printListLangkah(myHasil.hasilLangkah);

    auto seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout<<"Time execution: "<<seconds.count()<<"ms\n";
    return 0;
}
