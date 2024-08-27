#pragma once

class abstract_operation : public operation {
public:
    // SUMMARY: Default constructor for abstract_operation.
    abstract_operation();

    // SUMMARY: Parameterized constructor for abstract_operation.
    // PRE: 'operation' is a valid character representing the operation type.
    // POST: 'operation_type' is initialized with the provided 'operation'.
    abstract_operation(char operation) : operation_type(operation) {}


    // SUMMARY: Get the character code representing the operation.
    // POST: The character code representing the operation is returned.
    char get_code() override {
        return operation_type;
    }

    // SUMMARY: Perform the operation on two operands.
    // PRE: 'under' and 'top' are valid integer operands.
    // POST: The specified operation is performed on 'under' and 'top'.
    // Return: The result of the operation.
    virtual int perform(int under, int top) override = 0;

    // SUMMARY: Virtual destructor for abstract_operation.
    virtual ~abstract_operation() {}

private:
    char operation_type;
};

