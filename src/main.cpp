// #include "readfile.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include "header/algorithm.hpp"
#include "header/fieldgenerator.hpp"
#include "header/writefile.hpp"
#include "header/readfile.hpp"
using namespace std;

void Clear()
{
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void isContinue(bool &status){
    string choice;
    bool cek = false; 
    while(!cek){
        cout<<"Do another test? (y/n)\n-> ";
        cin >> choice;
        if (choice == "y"){
            status = true;
            cek = true;
        }
        else if(choice == "n"){
            status = false;
            cek = true;
        }
        else{
            Clear();
            cout << "Input tidak valid!\n";
        }
    }

}

void startSolver(Matrix &dataMatrix,int &bufferSize,std::vector<Sequence> &dataSequence, double &execTime){
    Clear();
    cout<<"======================= Input =======================\n";
    cout<<"Matriks Input:\n";
    dataMatrix.printValue();
    cout << "Buffer size: "<<bufferSize<<std::endl;
    
    cout<<"\n======================= Result =======================\n";
    cout<<"Processing...\n";
    hasil dataHasil = findPath(dataMatrix,bufferSize,dataSequence,execTime);
    string printChoice,path;

    printHasil(dataHasil);
    cout<<"Time Execution "<<execTime<<" ms\n";

    bool cek = false;
    while(!cek){
        cout<<"Do you want to write this file? (y/n) -> ";
        cin >>printChoice;
        if(printChoice == "y"){
            cout << "Save as ( [yourfile].txt )-> ";
            cin >> path;
            path = "test/output/" + path;
            resultToTxt(path,dataHasil,dataSequence,dataMatrix,execTime,bufferSize);
            cek = true;
        } 
        else if(printChoice != "n") {
            cout << "Input is not valid!\n";
        }
        else {
            cek = true;
        }
    }
}

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
            std::vector<Sequence> sequenceList = getSequences(filePath);
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

            std::vector<std::string> token = getToken(tokenString,jumlahToken);
            Matrix dataMatrix = randomMatrix(matrixWidth,matrixHeight,token);
            std::vector<Sequence> sequenceList = randomSequence(jumlahSekuens,maximumReward,ukuranMaksSekuens,token);
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