#ifndef TINY_CALCULATOR
#define TINY_CALCULATOR

enum OperationType{ADD = 0, SUBTRACT = 1, MULT =  2, DIVIDE = 3, MODULO = 4};

class TinyCalculator{
    public:
        TinyCalculator(); 
        TinyCalculator(int runValue);
        OperationType static displayUserMenu();
        void processInput(OperationType);
        void getRunTotal(TinyCalculator *calculatorArray[]);
        void setRunTotal(int result);
        void getCount();
        void static displayReport(TinyCalculator *calculatorArray[]);
        void static getAverage();
    private:
        static int add_count, sub_count, mult_count, div_count, mod_count;
        static int netTotal, netCount;
        int runTotal;
        void addition();
        void addition(int negate);
        void multiply();
        void divide();
        void modulo();
};

#endif