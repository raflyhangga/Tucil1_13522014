#include "../header/writefile.hpp"

std::string resultString(hasil dataHasil, std::vector<Sequence> dataSequence, Matrix dataMatrix, double executionTime,int bufferSize){
    std::string data;
    data += "Matrix:\n";
    for(int i=0;i<dataMatrix.getHeight();i++){
        for (int j=0; j<dataMatrix.getWidth();j++){
            data += dataMatrix.getValue(i,j).c_str();
            data += " ";
        }
        data += "\n";
    }
    data += "\nBuffer Maximum Size: ";
    data += std::to_string(bufferSize).c_str();
    data += "\n\n==== Sequence List ===\n";

    for (int i=0;i<dataSequence.size();i++){
        data += dataSequence[i].stringSequence().c_str();
    }

    data += "\n==== Result ====\n";
    data += "Execution time: ";
    data += std::to_string(executionTime).c_str();
    data += " ms\n";
    if (dataHasil.reward != 0){

        data += "Maximum point: ";
        data += std::to_string(dataHasil.reward).c_str();
        data += "\nBuffer: ";
        for (int i=0;i<dataHasil.hasilBuffer.size();i++){
            data += dataHasil.hasilBuffer[i];
            data += " ";
        }
        data += "\nLangkah: \n";
        for (int i=0;i<dataHasil.hasilLangkah.size();i++){
            data += std::to_string(dataHasil.hasilLangkah[i].j+1).c_str();
            data += " ";
            data += std::to_string(dataHasil.hasilLangkah[i].i+1).c_str();
            if (i != dataHasil.hasilLangkah.size() - 1){
                data += "\n";
            }

        }   
    }
    else {
        data += "No solution.";
    }

    return data;
}



void writeToTxt(std::string pathToFIle,std::string resultString){
    std::ofstream myFile(pathToFIle);

    if(myFile.is_open()){
        myFile << resultString.c_str();

        myFile.close();
        std::cout << "Text written succesfully!"<<std::endl;
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void resultToTxt(std::string path, hasil dataHasil,std::vector<Sequence> dataSequence, Matrix dataMatrix, double executionTime, int bufferSize){
    std::string data;
    data = resultString(dataHasil,dataSequence,dataMatrix,executionTime,bufferSize);
    writeToTxt(path,data);
}

