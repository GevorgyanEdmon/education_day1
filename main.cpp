#include <QApplication> // Для GUI
#include "mainwindow.h"  // Для GUI
#include "calculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric> // Для std::accumulate

int main(int argc, char *argv[]) {
    Calculator calc;

    if (argc > 1) {
        std::string full_arg_string;
        if (argc == 2) { // Один аргумент-строка, например "./calculator "10 + 5""
            full_arg_string = argv[1];
        } else if (argc == 4) { // Три аргумента, например "./calculator 10 + 5"
            full_arg_string = std::string(argv[1]) + " " + std::string(argv[2]) + " " + std::string(argv[3]);
        } else {
             std::cerr << "Использование (командная строка):" << std::endl;
             std::cerr << "  " << argv[0] << " \"число операция число\"" << std::endl;
             std::cerr << "  " << argv[0] << " число операция число" << std::endl;
             std::cerr << "Использование (GUI):" << std::endl;
             std::cerr << "  " << argv[0] << std::endl;
             return 1;
        }

        try {
            Calculator::ParsedInput input = calc.parseString(full_arg_string);
            double result = calc.process(input.num1, input.operation, input.num2);
            std::cout << "Результат: " << result << std::endl;
            return 0;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    } else {
        QApplication app(argc, argv);
        MainWindow window;
        window.show();
        return app.exec();
    }
}