#ifndef RPN_CALCULATOR_HPP
#define RPN_CALCULATOR_HPP

#include <stack>
#include <string>
#include <iostream>
#include "operation.hpp"
#include "addition_operation.hpp"
#include "subtraction_operation.hpp"
#include "multiplication_operation.hpp"
#include "division_operation.hpp"
#include "abstract_operation.hpp"
#include <sstream>

class rpn_calculator {
public:
    // Process a Reverse Polish Notation (RPN) formula and return the result
    int process_formula(const std::string& formula);

private:
    std::stack<int> formulaStack;

    // Determine the operation type based on a character representation
    abstract_operation* operation_type(char operation);

    // Perform a specified operation on the top two operands of the stack
    void perform(abstract_operation* operation);
};

#endif // RPN_CALCULATOR_HPP
