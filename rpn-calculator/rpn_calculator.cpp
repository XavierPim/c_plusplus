#include "rpn_calculator.hpp"

abstract_operation* rpn_calculator::operation_type(char operation) {
    switch (operation) {
        case addition_operation::ADDITION_CODE:
            return new addition_operation();
        case subtraction_operation::SUBTRACTION_CODE:
            return new subtraction_operation();
        case multiplication_operation::MULTIPLICATION_CODE:
            return new multiplication_operation();
        case division_operation::DIVISION_CODE:
            return new division_operation();
        default:
            std::cout << "Unknown operation" << std::endl;
        return nullptr;
    }
}

void rpn_calculator::perform(abstract_operation* operation) {
    if (formulaStack.size() < 2) {
        std::cout << "Incorrect number of operands" << std::endl;
        return; // Early return in case of incorrect number of operands
    }

    int top = formulaStack.top();
    formulaStack.pop();
    int under = formulaStack.top();
    formulaStack.pop();
    int result = operation->perform(under, top);
    formulaStack.push(result);
}

int rpn_calculator::process_formula(const std::string& formula) {
    std::istringstream iss(formula);
    std::string word;

    while (iss >> word) {
        if (isdigit(word[0])) {
            int operand = std::stoi(word);
            formulaStack.push(operand);
        } else if (word.size() == 1) {
            char operation = word[0];
            if (!formulaStack.empty()) {
                abstract_operation* op = operation_type(operation);
                if (op != nullptr) {
                    perform(op);
                    delete op;
                }
            }
        }
    }

    if (!formulaStack.empty()) {
        return formulaStack.top();
    } else {
        std::cout << "No valid result found." << std::endl;
        return 0; // You can choose an appropriate error handling strategy
    }
}
