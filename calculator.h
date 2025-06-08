#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stdexcept> // Для std::invalid_argument, std::overflow_error

class Operation {
public:
    virtual ~Operation() = default;
    virtual double calculate(double a, double b) const = 0;
};

class AddOperation : public Operation {
public:
    double calculate(double a, double b) const override;
};

class SubtractOperation : public Operation {
public:
    double calculate(double a, double b) const override;
};

class MultiplyOperation : public Operation {
public:
    double calculate(double a, double b) const override;
};

class DivideOperation : public Operation {
public:
    double calculate(double a, double b) const override;
};

class Calculator {
public:
    Calculator();
    double process(double a, char op, double b);
    struct ParsedInput {
        double num1;
        char operation;
        double num2;
    };
    ParsedInput parseString(const std::string& input);
};

#endif // CALCULATOR_H