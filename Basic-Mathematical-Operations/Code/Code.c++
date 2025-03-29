#include <iostream>
using namespace std;

double Divide(double x, double y)
{
    if (y == 0)
    {
        cerr << "Error: Division by zero!" << endl;
        return 0;
    }
    else
    {
        return x / y;
    }
}

double Multiply(double x, double y)
{
    return x * y;
}

double Subtract(double x, double y)
{
    return x - y;
}

double Sum(double x, double y)
{
    return x + y;
}

int main()
{
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    double result;
    switch (operation)
    {
    case '+':
        result = Sum(num1, num2);
        break;
    case '-':
        result = Subtract(num1, num2);
        break;
    case '*':
        result = Multiply(num1, num2);
        break;
    case '/':
        result = Divide(num1, num2);
        break;
    default:
        cerr << "Invalid operation!" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}

