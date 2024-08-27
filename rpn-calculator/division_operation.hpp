#pragma once

#include "abstract_operation.hpp"

class division_operation : public abstract_operation {
public:
    // SUMMARY: Default constructor for division_operation.
    division_operation() : abstract_operation(DIVISION_CODE) {}

    // SUMMARY: Perform division operation on two operands.
    // PRE: 'under' and 'top' are valid integer operands.
    // POST: Division operation is performed on 'under' and 'top'.
    // Return: The result of the division operation.
    int perform(int under, int top) override { return under / top; }

    // SUMMARY: Virtual destructor for division_operation.
    virtual ~division_operation() {}

    // SUMMARY: Character code for division operation.
    // POST: The character code representing division operation ('/') is returned.
    const static char DIVISION_CODE = '/';
};
