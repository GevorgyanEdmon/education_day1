#include "calculator.h"
#include <sstream>      
#include <limits>       
#include <cmath>        

double AddOperation::calculate(double a, double b) const {
    return a + b;
}

double SubtractOperation::calculate(double a, double b) const {
    return a - b;
}

double MultiplyOperation::calculate(double a, double b) const {
    return a * b;
}

double DivideOperation::calculate(double a, double b) const {
    if (std::abs(b) < std::numeric_limits<double>::epsilon()) {
        throw std::overflow_error("Ошибка: Деление на ноль!");
    }
    return a / b;
}

Calculator::Calculator() {}

double Calculator::process(double a, char op, double b) {
    Operation* operation = nullptr;
    AddOperation addOp;
    SubtractOperation subOp;
    MultiplyOperation mulOp;
    DivideOperation divOp;

    switch (op) {
        case '+':
            operation = &addOp;
            break;
        case '-':
            operation = &subOp;
            break;
        case '*':
            operation = &mulOp;
            break;
        case '/':
            operation = &divOp;
            break;
        default:
            throw std::invalid_argument("Ошибка: Неизвестная операция '" + std::string(1, op) + "'");
    }
    return operation->calculate(a, b);
}

Calculator::ParsedInput Calculator::parseString(const std::string& input) {
    std::istringstream iss(input);
    ParsedInput result;
    std::string temp_op_str;

    if (!(iss >> result.num1)) {
        throw std::invalid_argument("Ошибка парсинга: не удалось прочитать первое число из строки \"" + input + "\"");
    }

    if (!(iss >> temp_op_str) || temp_op_str.length() != 1) {
         throw std::invalid_argument("Ошибка парсинга: не удалось прочитать оператор или оператор не один символ из строки \"" + input + "\"");
    }
    result.operation = temp_op_str[0];

    if (!(iss >> result.num2)) {
         throw std::invalid_argument("Ошибка парсинга: не удалось прочитать второе число из строки \"" + input + "\"");
    }

    std::string leftovers;
    if (iss >> leftovers) {
        throw std::invalid_argument("Ошибка парсинга: лишние символы в строке \"" + input + "\"");
    }
    
    return result;
}
