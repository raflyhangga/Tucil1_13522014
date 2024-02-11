#include <string>
#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include "header/algorithm.hpp"
#include "header/fieldgenerator.hpp"
#include "header/writefile.hpp"
#include "header/readfile.hpp"
#include "header/tools.hpp"
using namespace std;

int main(){
    bool play = true;
    double executionTime;
    hasil dataHasil;
    while (play){
        Clear();
        cout<< "Welcome to Cyberpunk 2077 Breach Protocol\n";
        cout<<"Here we have two options for the input method in this game.\n";
        cout<<"1. Import a txt file\n";
        cout<<"2. We generate the field for you!\n";
        int mainChoice;
        string printChoice;
        cout<<"Your choice(1/2) -> ";
        cin>>mainChoice;
        if (mainChoice == 1){
            Clear();
            std::string filePath;
            cout<<"Input the txt file path inside the test folder";
            cout<<" -> ";
            cin >> filePath;
            Clear();

            filePath = "test/" + filePath;
            Matrix dataMatrix = getMatrix(filePath);
            int bufferSize = getBufferSize(filePath);
            Arraydin<Sequence> sequenceList = getSequences(filePath);
            startSolver(dataMatrix,bufferSize,sequenceList,executionTime);
            isContinue(play);
        }
        else if(mainChoice == 2){
            Clear();
            int jumlahToken,bufferSize,matrixWidth,matrixHeight,jumlahSekuens,ukuranMaksSekuens,maximumReward;
            string tokenString;
            cout<<"Token Amount (integer) -> ";
            cin >> jumlahToken;
            cout<<"Token (ex. A1 BB) -> ";
            cin.ignore();
            getline(cin,tokenString,'\n');
            cout<< "Buffer Size (integer) -> ";
            cin >> bufferSize;
            cout << "Matrices Width (integer) -> ";
            cin >> matrixWidth;
            cout << "Matrices Height (integer) -> ";
            cin >> matrixHeight;
            cout << "Sequence Amount (integer) -> ";
            cin >> jumlahSekuens;
            cout << "Maximum Sequence Length (integer) -> ";
            cin >> ukuranMaksSekuens;
            cout << "Maximum reward value (integer) -> ";
            cin >> maximumReward;

            Arraydin<std::string> token = getToken(tokenString,jumlahToken);
            Matrix dataMatrix = randomMatrix(matrixWidth,matrixHeight,token);
            Arraydin<Sequence> sequenceList = randomSequence(jumlahSekuens,maximumReward,ukuranMaksSekuens,token);
            startSolver(dataMatrix,bufferSize,sequenceList,executionTime);
            isContinue(play);
        }
        else {
            cout<<"invalid input, try another input\n";
        }

    }
    Clear();
    cout << "Thanks for playing!\n";
    return 0;
}