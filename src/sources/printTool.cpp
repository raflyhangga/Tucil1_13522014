#include "../header/printTool.hpp"

void isContinue(bool &status){
    std::string choice;
    bool cek = false; 
    while(!cek){
        std::cout<<"Do another test? (y/n)\n-> ";
        std::cin >> choice;
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
            std::cout << "Input tidak valid!\n";
        }
    }

}

void startSolver(Matrix &dataMatrix,int &bufferSize,Arraydin<Sequence> &dataSequence, double &execTime){
    Clear();
    std::cout<<"======================= Input =======================\n";
    std::cout<<"Matriks Input:\n";
    dataMatrix.printValue();
    std::cout << "Buffer size: "<<bufferSize<<std::endl;
    
    std::cout<<"\n======================= Result =======================\n";
    std::cout<<"Processing...\n";
    hasil dataHasil = findPath(dataMatrix,bufferSize,dataSequence,execTime);
    std::string printChoice,path;

    printHasil(dataHasil);
    std::cout<<"Time Execution "<<execTime<<" ms\n";

    bool cek = false;
    while(!cek){
        std::cout<<"Do you want to write this file? (y/n) -> ";
        std::cin >>printChoice;
        if(printChoice == "y"){
            std::cout << "Save as ( [yourfile].txt )-> ";
            std::cin >> path;
            path = "test/output/" + path;
            resultToTxt(path,dataHasil,dataSequence,dataMatrix,execTime,bufferSize);
            cek = true;
        } 
        else if(printChoice != "n") {
            std::cout << "Input is not valid!\n";
        }
        else {
            cek = true;
        }
    }
}

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