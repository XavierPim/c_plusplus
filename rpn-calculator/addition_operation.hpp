#pragma once

#include "abstract_operation.hpp"

class addition_operation: public abstract_operation{
public:
    // SUMMARY: Default constructor for addition_operation.
    addition_operation() : abstract_operation(ADDITION_CODE){}

    // SUMMARY: Perform addition operation on two operands.
    // PRE: 'under' and 'top' are valid integer operands.
    // POST: Addition operation is performed on 'under' and 'top'.
    // Return: The result of the addition operation.
    int perform(int under, int top) override{return under + top;}

    // SUMMARY: Virtual destructor for addition_operation.
    virtual ~addition_operation() override{};

    // SUMMARY: Character code for addition operation.
    // POST: The character code representing addition operation ('+') is returned.
    const static char ADDITION_CODE = '+';
};