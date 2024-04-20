#include "./include/calculator.h"

Calculator::Calculator(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Simple Calculator");
    setWindowIcon(QIcon("./assets/calculator.ico"));
    setGeometry(100, 100, 300, 300);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout *gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(10);

    displayLabel = new QLabel("0", centralWidget);
    displayLabel->setAlignment(Qt::AlignRight);
    gridLayout->addWidget(displayLabel, 0, 0, 1, 4);

    createButton("7", 1, 0, gridLayout);
    createButton("8", 1, 1, gridLayout);
    createButton("9", 1, 2, gridLayout);
    createButton("÷", 1, 3, gridLayout);

    createButton("4", 2, 0, gridLayout);
    createButton("5", 2, 1, gridLayout);
    createButton("6", 2, 2, gridLayout);
    createButton("*", 2, 3, gridLayout);

    createButton("1", 3, 0, gridLayout);
    createButton("2", 3, 1, gridLayout);
    createButton("3", 3, 2, gridLayout);
    createButton("-", 3, 3, gridLayout);

    createButton("0", 4, 0, gridLayout);
    createButton(".", 4, 1, gridLayout);
    createButton("=", 4, 2, gridLayout);
    createButton("+", 4, 3, gridLayout);

    addFullWidthButton("C", 5, gridLayout);

    centralWidget->setLayout(gridLayout);

    connect(pushButtons[20], &QPushButton::clicked, this, &Calculator::calculate);
}

void Calculator::calculate() {
    QString result = displayLabel->text();
    double res = evalExpression(result);
    displayLabel->setText(QString::number(res));
}

double Calculator::evalExpression(const QString &expr) {
    //TODO: Expand on expression evaluation
    return expr.toDouble();
}

void Calculator::onButtonClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton) {
        QString text = clickedButton->text();
        QString displayText = displayLabel->text();

        if (displayText == "0" || displayText == "Error")
            displayLabel->setText(text);
        else
            displayLabel->setText(displayText + text);
    }
}

void Calculator::createButton(const QString &text, int row, int col, QGridLayout *gridLayout) {
    QPushButton *button = new QPushButton(text, this);
    pushButtons[row * 4 + col] = button;
    gridLayout->addWidget(button, row, col);
    connect(button, &QPushButton::clicked, this, &Calculator::onButtonClicked);
}

void Calculator::addFullWidthButton(const QString &text, int row, QGridLayout *gridLayout) {
    QPushButton *button = new QPushButton(text, this);
    pushButtons[row * 4 + 0] = button;
    gridLayout->addWidget(button, row, 0, 1, 4);
    connect(button, &QPushButton::clicked, this, &Calculator::onButtonClicked);
}

// HELPERS
// Stash: Saved working directory and index state WIP on main: 66f5ca1 Update README
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

int main(int argc, char *argv[]){

    qDebug() << "Hello Worlds, From Qt!";

    QApplication app(argc, argv);

    Calculator calculator;
    calculator.show();

    return app.exec();



}