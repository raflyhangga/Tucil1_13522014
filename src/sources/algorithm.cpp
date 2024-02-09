#include "../readfile.hpp"
#include "../tools.hpp"
#include <ctime>

struct hasil {
    std::vector<std::string> hasilBuffer;
    std::vector<Langkah> hasilLangkah;
    int reward;
};

int countReward(std::vector<std::string> &buffer,std::vector<Sequence> &dataSequence){
    int reward = 0;
    for(int i=0;i<dataSequence.size();i++){
        if(isBufferHasSequence(buffer,dataSequence[i])){
            reward += dataSequence[i].getReward();
        }
    }
    return buffer.size() == 0? INT16_MIN : reward;
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

void printListLangkah(std::vector<Langkah> &listLangkah){
    for (int i=0;i<listLangkah.size();i++){
        std::cout<<"("<<listLangkah[i].i<<","<<listLangkah[i].j<<") ";
    }
    std::cout<<std::endl;
}

void printBuffer(std::vector<std::string> &buffer){
    for (int i=0;i<buffer.size();i++){
        std::cout<<buffer[i]<<" ";
    }
    std::cout<<std::endl;
}


void findOptimum(Matrix &dataMatrix,int &rewardMaks, std::vector<Langkah> &currentLangkah, bool &isHorizontal, std::vector<std::string> &buffer,int &bufferSize,std::vector<Sequence> &dataSequence, int &idx, hasil &result){
    int tempReward = countReward(buffer,dataSequence);
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

hasil findPath(Matrix &dataMatrix,int &bufferSize,std::vector<Sequence> &dataSequence){
    std::vector<Langkah> langkahTemp,langkahOptimum;
    std::vector<std::string> buffer;
    std::vector<hasil> listResult;
    hasil myHasil;

    int rewardMaks = INT16_MIN;
    int counter = 0;
    int idx = 0;
    bool check = true;

    findOptimum(dataMatrix,rewardMaks,langkahOptimum,check,buffer,bufferSize,dataSequence,idx,myHasil);

    return myHasil;
}

// int main(){
//     Matrix dataMatriks = getMatrix("src/tes.txt");
//     std::vector<Sequence> dataSequence = getSequences("src/tes.txt");
//     int bufferSize = getBufferSize("src/tes.txt");

//     std::cout<<"Matriks terbaca:"<<std::endl;
//     dataMatriks.printValue();
//     std::cout<<"Buffer Size: "<<bufferSize<<std::endl;


//     std::clock_t start = clock();
//     hasil myHasil = findPath(dataMatriks,bufferSize,dataSequence);
//     std::clock_t end = clock();

//     std::cout<<"Reward Maksimum: "<<myHasil.reward<<std::endl;
//     std::cout<<"Buffer : ";
//     printBuffer(myHasil.hasilBuffer);
//     printListLangkah(myHasil.hasilLangkah);

//     double duration_sec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
//     std::cout<<"Time execution: "<<duration_sec*1000<<" ms\n";
//     return 0;
// }
