#include<iostream>
#include<string>

#include "tiny_calculator.hpp"
using std::cout;
using std::cin;
using std::endl;

int main(){

    bool playLoop = true;
    char userInput;
    const int arraySize = 2;
    TinyCalculator evenCalculator(0), oddCalculator(0);
    TinyCalculator *calculatorArray[arraySize] = {&evenCalculator, &oddCalculator};
    OperationType selectedOperation;
    
    while(playLoop == true){
        
        selectedOperation = evenCalculator.displayUserMenu();
        evenCalculator.processInput(selectedOperation);
        cout << "Anymore calculations for me? (y/n)" << endl;
        cin >> userInput;
        if(tolower(userInput) == 'n'){
            break;
        };
        
        selectedOperation = oddCalculator.displayUserMenu();
        oddCalculator.processInput(selectedOperation);
        std::cin.clear();
        std::cin.ignore();
        cout << "Anymore calculations for me? (y/n)" << endl;
        cin >> userInput;
        if(tolower(userInput) == 'n'){
            playLoop = false;
        };
    }
    evenCalculator.displayReport(calculatorArray);
    return 0;
};