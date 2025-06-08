#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    this->setWindowTitle("Калькулятор");

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QFormLayout *formLayout = new QFormLayout();

    num1Edit = new QLineEdit();
    operatorEdit = new QLineEdit();
    operatorEdit->setMaxLength(1); // Оператор - один символ
    num2Edit = new QLineEdit();
    
    formLayout->addRow("Первое число:", num1Edit);
    formLayout->addRow("Операция (+, -, *, /):", operatorEdit);
    formLayout->addRow("Второе число:", num2Edit);

    calculateButton = new QPushButton("Вычислить");
    resultLabel = new QLabel("Результат: ");
    resultLabel->setWordWrap(true);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(calculateButton);
    mainLayout->addWidget(resultLabel);
    
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::onCalculateClicked);
    
    // Устанавливаем разумный минимальный размер окна
    setMinimumSize(300, 200);
}

MainWindow::~MainWindow()
{
    // Qt автоматически удалит дочерние виджеты, если ui не используется
}

void MainWindow::onCalculateClicked() {
    QString num1Str = num1Edit->text();
    QString opStr = operatorEdit->text();
    QString num2Str = num2Edit->text();

    bool ok1, ok2;
    double num1 = num1Str.toDouble(&ok1);
    double num2 = num2Str.toDouble(&ok2);
    char op = ' ';

    if (opStr.length() == 1) {
        op = opStr.at(0).toLatin1();
    } else {
        QMessageBox::warning(this, "Ошибка ввода", "Оператор должен быть одним символом.");
        resultLabel->setText("Результат: Ошибка ввода оператора");
        return;
    }

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Ошибка ввода", "Пожалуйста, введите корректные числа.");
        resultLabel->setText("Результат: Ошибка ввода чисел");
        return;
    }

    try {
        double result = m_calculator.process(num1, op, num2);
        resultLabel->setText("Результат: " + QString::number(result));
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка вычисления", e.what());
        resultLabel->setText("Результат: " + QString(e.what()));
    }
}