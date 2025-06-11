#include <QApplication>
#include "mainwindow.h"
#include "calculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString darkStyleSheet = R"(
        QMainWindow {
            background-color: #2E2E2E;
        }

        QWidget {
            background-color: #2E2E2E;
            color: #E0E0E0;
            font-family: Arial, sans-serif;
            font-size: 10pt;
        }

        QLineEdit {
            background-color: #3C3C3C;
            border: 1px solid #555555;
            border-radius: 4px;
            padding: 6px;
            color: #E0E0E0;
        }

        QLineEdit:focus {
            border: 1px solid #0078D7;
        }

        QPushButton {
            background-color: #0078D7;
            color: white;
            border: none;
            border-radius: 4px;
            padding: 8px 16px;
            min-height: 20px;
        }

        QPushButton:hover {
            background-color: #005A9E;
        }

        QPushButton:pressed {
            background-color: #003C6B;
        }

        QLabel {
            color: #E0E0E0;
            padding: 5px;
        }

        QMessageBox {
            background-color: #3C3C3C;
        }
        QMessageBox QLabel {
            color: #E0E0E0;
        }
        QMessageBox QPushButton {
            background-color: #0078D7;
            color: white;
            border-radius: 4px;
            padding: 6px 12px;
            min-width: 70px;
        }
        QMessageBox QPushButton:hover {
            background-color: #005A9E;
        }
        QMessageBox QPushButton:pressed {
            background-color: #003C6B;
        }
    )";

    app.setStyleSheet(darkStyleSheet);

    Calculator calc;

    if (argc > 1) {
        std::string full_arg_string;
        if (argc == 2) {
            full_arg_string = argv[1];
        } else if (argc == 4) {
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
        MainWindow window;
        window.show();
        return app.exec();
    }
}
