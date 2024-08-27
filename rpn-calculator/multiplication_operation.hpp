#pragma once

class multiplication_operation: public abstract_operation{
public:
    // SUMMARY: Default constructor for multiplication_operation.
    multiplication_operation() : abstract_operation(MULTIPLICATION_CODE) {}

    // SUMMARY: Perform multiplication operation on two operands.
    // PRE: 'under' and 'top' are valid integer operands.
    // POST: Multiplication operation is performed on 'under' and 'top'.
    // Return: The result of the multiplication operation.
    int perform(int under, int top) override{return under * top;}

    // SUMMARY: Virtual destructor for multiplication_operation.
    virtual ~multiplication_operation(){};

    // SUMMARY: Character code for multiplication operation.
    // POST: The character code representing multiplication operation ('*') is returned.
    static const char MULTIPLICATION_CODE = '*';
};