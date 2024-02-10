# Tugas Kecil 1 - Strategi Algoritma - 13522014

## Description
This project is a minigame solver for **Cyberpunk 2077's Breach Protocol Minigame** with a bit of modification using *brute force* approach to find the optimum solution (i.e maximum reward) for every buffer combination. The algorithm will return the optimum solution by command line interface or ```.txt``` format.

## Building the Project
### Windows Based OS
1. Clone the project repository to your local machine.
2. Open a command prompt or terminal and navigate to the project directory.
3. Run the ```run.bat``` script by executing the following command:
```
./run.bat
```

### Unix Based OS
1. Clone the project repository to your local machine.
2. Open a command prompt or terminal and navigate to the project directory.
3. Run the ```run.sh``` script by executing the following command:
```
./run.sh
```

## Running the Application
### Windows Based OS
Run the executable, built by ```run.bat```, by opening the ```main.exe``` file.
### UNIX Based OS
Run the executable, built by ```run.sh```, by opening the ```main``` file.

## How to Use the Application
This application will provide the user for the input method. There is two input method that the user can choose from, ***Import*** and ***Random***.

### Import Method
The user have to provide the program a ```.txt``` file that has the format by the following:
```
[maximum buffer size]
[matrix widht] [matrix height]
[matrix]
[amount of sequence]
[sequences]
```
For references, check the test folder and modify to the user's specifics.

### Random Method
The user will have to input the parameters manually into the program's *command line interface*.

The paramaters incudes:
1. Token Amount - ```integer```
2. Token - ```string```
3. Buffer Size - ```integer```
4. Matrix Width - ```integer```
5. Matrix Height - ```integer```
1. Sequence Amount - ```integer```
1. Maximum Sequence Length - ```integer```
1. Maximum Reward - ```integer```

**IMPORTANT!!!**<br>
If the user mistakenly input the wrong type into these parameters, please re-open the program to achieve an accurate solution.
