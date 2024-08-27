#include <iostream>
#include "rpn_calculator.hpp"
using  namespace std;

int main() {
    //BETA TESTCASE
//    rpn_calculator calc;
//    string formula = "6 4 8 2 - + *";            ;
//    int result = calc.process_formula(formula);
//    cout << "Result: " << result << endl;


    cout << "Enter your formula:\n";
    string formula;
    getline(cin, formula);
    cout << "You entered " << formula <<endl;
    rpn_calculator calculator;
    int result = calculator.process_formula(formula);

    cout << "The result is:\n";
    cout << result << endl;


    return 0;
}
