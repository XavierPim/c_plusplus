#pragma once

#include "abstract_operation.hpp"

class subtraction_operation : public abstract_operation {
public:
    // SUMMARY: Default constructor for subtraction_operation.
    subtraction_operation() : abstract_operation(SUBTRACTION_CODE) {}

    // SUMMARY: Perform subtraction operation on two operands.
    // PRE: 'under' and 'top' are valid integer operands.
    // POST: Subtraction operation is performed on 'under' and 'top'.
    // Return: The result of the subtraction operation.
    int perform(int under, int top) override { return under - top; }

    // SUMMARY: Virtual destructor for subtraction_operation.
    virtual ~subtraction_operation() {}

    // SUMMARY: Character code for subtraction operation.
    // POST: The character code representing subtraction operation ('-') is returned.
    const static char SUBTRACTION_CODE = '-';
};
