#include "./include/main.h"
#include <iostream>
#include <utility>
//#include <QCoreApplication>
//#include <QDebug>

//using namespace std;

void test() {
    std::cout << " VARIABLE: " << VARIABLE << std::endl;
}

double addition(const std::pair<double, double>& numbers) {
    return numbers.first + numbers.second;
}

double subtraction(const std::pair<double, double>& numbers) {
    return numbers.first - numbers.second;
}

double multiplication(const std::pair<double, double>& numbers) {
    return numbers.first * numbers.second;
}

double division(const std::pair<double, double>& numbers) {
    if (numbers.second == 0) {
        std::cout << "Error: Cannot divid by zero (0)";
        return 0;
    }

    return numbers.first / numbers.second;
}

std::pair<double, double> retrieveNumbers() {
    double num1, num2;

        std::cout << "Enter first number: ";
        std::cin >> num1;

        std::cout << "Enter second number: ";
        std::cin >> num2;

    return std::pair<double, double>(num1, num2);
}

int main(int argc, char *argv[])
{
    double result;
    std::string choice;

    test();

    std::cout << "Enter operation (+, -, *, +)" << std::endl;
    std::cin >> choice;


    if (choice == "+" || choice == "add" || choice == "addition") {
        result = addition(retrieveNumbers());
    } else if (choice == "-" || choice == "subtract" || choice == "subtraction") {
        result = subtraction(retrieveNumbers());
    } else if (choice == "*" || choice == "multiply" || choice == "multiplication"){
        result = multiplication(retrieveNumbers());
    } else if (choice == "/" || choice == "divide" || choice == "division") {
        result = division(retrieveNumbers());
    } else {
        std::cout << "Invalid Operation!" << std::endl;
        return 1;
    }

    std::cout << "Result of operation " << choice << " is " << result;

    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello, Qt!";
    //return a.exec();

    return 0;

}