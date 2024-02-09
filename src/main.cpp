// #include "readfile.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    system("cls");
    bool play = true;
    cout<< "Welcome to Cyberpunk 2077 Breach Protocol\n";
    cout<<"Here we have two options for the input method for this game.\n";
    cout<<"1. Import a txt file\n";
    cout<<"2. We generate the field for you!\n";
    while (play){
        int mainChoice;
        cout<<"Your choice(1/2): ";
        cin>>mainChoice;
        if (mainChoice == 1 || mainChoice == 2){
            cout<<"ON PROGRESSS\n";
            play = !play;
        } else {
            cout<<"invalid input, try another input\n";
        }

    }
    return 0;
}