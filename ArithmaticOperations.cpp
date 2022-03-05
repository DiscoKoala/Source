#include<iostream>
#include<string>

#include "tiny_calculator.hpp"

using std::cout;
using std::cin;
using std::endl;

int negate = -1;
int TinyCalculator::add_count = 0;
int TinyCalculator::sub_count = 0;
int TinyCalculator::mult_count = 0;
int TinyCalculator::div_count = 0;
int TinyCalculator::mod_count = 0;
int TinyCalculator::netTotal = 0;
int TinyCalculator::netCount = 0;

//Default constructor
TinyCalculator::TinyCalculator(){
    runTotal = 0;
};
//Constructor overloader for initializing desired running total value
TinyCalculator::TinyCalculator(int runValue):runTotal(runValue){};

/*
Displaying calculator menu, checking user input validity, returning corresponding 
operation type defined in header file.
*/
OperationType TinyCalculator::displayUserMenu(){
    
    char userInput;
    bool validInput = false;

    cout << "To choose an operation, enter a character seen in parathesis. \n";
    cout << "(A)ddition \n";
    cout << "(S)ubtraction \n";
    cout << "(M)ultiply \n";
    cout << "(D)ivide \n";
    cout << "(%)Modulo \n";
    cout << "Operation: \n";
    cin >> userInput;

    userInput = toupper(userInput);
    
    switch(userInput){
        case 'A': return ADD;
            validInput = true;
            break;
        case 'S': return SUBTRACT;
            validInput = true;
            break;
        case 'M': return MULT;
            validInput = true;
            break;
        case 'D': return DIVIDE;
            validInput = true;
            break;
        case '%': return MODULO;
            validInput = true;
            break;
        default:
            validInput = false;
    };
}

//Passing user input to call appropriate function
void TinyCalculator::processInput(OperationType op){
    switch(op){
        case ADD: addition(); 
            break;
        case SUBTRACT: addition(negate);
            break;
        case MULT: multiply();
            break;
        case DIVIDE: divide();
            break;
        case MODULO: modulo();
            break;
        default:
            cout << "Unknown Operation\n";

    }
}

//Adding lvalue and rvalue; outputting result
void TinyCalculator::addition(){
    int left, right, result;
    cout << "Enter first number: ";
    cin >> left;
    cout << "Enter second number: ";
    cin >> right;
    result = left + right;
    setRunTotal(result);
    netTotal += result;
    add_count++;
    netCount++;
    cout << "Answer: " << left << " + " << right << " = "<< result << endl;
}
//Addition function overload; passing negative variable to negate rvaule
void TinyCalculator::addition(int negate){
    int left, right, result;
    cout << "Enter first number: ";
    cin >> left;
    cout << "Enter second number: ";
    cin >> right;
    result = left + (negate * right);
    setRunTotal(result);
    netTotal += result;
    sub_count++;
    netCount++;
    cout << "Answer: " << left << " - " << right << " = "<< result << endl;      
}
//Adding lvalue to result, rvalue many times
void TinyCalculator::multiply(){
    int left, right, result = 0;
    cout << "Enter first number: ";
    cin >> left;
    cout << "Enter second number: ";
    cin >> right; 
    for(int i = 0; i < right; i++){
        result += left;
    }
    setRunTotal(result);
    netTotal += result;
    mult_count++;
    netCount++;
    cout << "Answer: " << left << " * " << right << " = "<< result << endl;
}

/*
Subtracting lvalue from rvalue until lvalue is equal too or less than rvalue
Incrementing denom by one for every time the rvalue goes into lvalue.
Pass denom to instance private member variable mutator.
Increment division and total count by one 
*/
void TinyCalculator::divide(){
    int left, right, result, denom = 0;
    cout << "Enter first number: ";
    cin >> left;
    cout << "Enter second number: ";
    cin >> right; 
    result = left;
    do{
        result -= right;
        denom++;
    }
    while(result >= right);
    setRunTotal(denom);
    netTotal += denom;
    div_count++;
    netCount++;
    cout << "Answer: " << left << " / " << right << " = "<< denom << endl;
}

//Subtracting rvalue from lvalue until equal to or greater than; outputting remainder
void TinyCalculator::modulo(){
    int left, right, result;
    cout << "Enter first number: ";
    cin >> left;
    cout << "Enter second number: ";
    cin >> right; 
    result = left;
    do{
        result -= right;
    }while(result >= right);
    if(result < 0){
        result = 0;
    }
    setRunTotal(result);
    netTotal += result;
    mod_count++;
    netCount++;
    cout << "Answer: " << left << " % " << right << " = "<< result << endl;
}

//Sets running total for current object instance
void TinyCalculator::setRunTotal(int result){
    this->runTotal+=result;
}

//Outputting totals from latest run
void TinyCalculator::getCount(){
    cout << "\tAddition: " << add_count << endl;
    cout << "\tSubtraction: " << sub_count << endl;
    cout << "\tMultiplication: " << mult_count << endl;
    cout << "\tDivision: " << div_count << endl;
    cout << "\tModulo: " << mod_count << endl;
    cout << "\tTotal Operations: " << netCount << endl;
    cout << "\tRunnning total of all operations: " << netTotal << endl;
}

//Passing object array and pointing to object member variables for running total
void TinyCalculator::getRunTotal(TinyCalculator *calculatorArray[]){
    cout << "\tRunning total for evenCalculator: " << calculatorArray[0]->runTotal << endl;
    cout << "\tRunning total for oddCalculator: " << calculatorArray[1]->runTotal << endl;
}

//Using division algorithm to divide running total by total operation count
void TinyCalculator::getAverage(){
    int denom = 0;
    do{
    netTotal -= netCount;
    denom++;
    }
    while(netTotal >= netCount);
    cout << "\tAverage of total operations: " << denom << endl;
}

//Passing object array to call getters
void TinyCalculator::displayReport(TinyCalculator *calculatorArray[]){
    
    cout << "\nCalculator Report " << endl;
    cout << "__________________" << endl;
    calculatorArray[0]->getCount();
    calculatorArray[0]->getRunTotal(&calculatorArray[0]);
    calculatorArray[0]->getAverage();
};
