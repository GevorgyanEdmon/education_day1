#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCalculateClicked();

private:
    Ui::MainWindow *ui; // Если используешь Qt Designer
    
    // Ручное создание элементов интерфейса
    QLineEdit *num1Edit;
    QLineEdit *operatorEdit;
    QLineEdit *num2Edit;
    QPushButton *calculateButton;
    QLabel *resultLabel;
    
    Calculator m_calculator;
};
#endif // MAINWINDOW_H