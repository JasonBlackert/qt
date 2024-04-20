#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <utility>

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QIcon>


class Calculator : public QMainWindow {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);

private slots:
    void clearPrompt();
    void calculate();
    double evalExpression(const QString &expr);
    void onButtonClicked();

private:
    QLabel *displayLabel;
    QPushButton *pushButtons[20];

    void createButton(const QString &text, int row, int col, QGridLayout *gridLayout);
    void addFullWidthButton(const QString &text, int row, QGridLayout *gridLayout);
};

#endif // CALCULATOR_H
