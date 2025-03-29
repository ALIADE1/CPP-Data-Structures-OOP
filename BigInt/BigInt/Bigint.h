#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class BigInt
{
private:

    string InternalString;

    // Adds two numeric strings, padding the shorter one with zeros.
    string AddNumbers(string N1, string N2) {

        // Pad the shorter string with zeros.
        while (N1.size() < N2.size())
            N1.insert(0, "0");
        while (N2.size() < N1.size())
            N2.insert(0, "0");

        int remainder = 0;
        string result = "";
        int n = N1.size(); 

        for (int i = n - 1; i >= 0; i--)
        {
            int d1 = N1[i] - '0';
            int d2 = N2[i] - '0';
            int summ = d1 + d2 + remainder;
            remainder = summ / 10;
            char digit = ((summ % 10) + '0');
            result.insert(result.begin(), digit);
        }

        if (remainder > 0)
            result.insert(result.begin(), '1');

        return result;
    }

public:

    // Constructors
    BigInt(string s = "0") {
        InternalString = s;
    }

    ~BigInt() {
        cout << "Dying" << endl;
    }

    BigInt(const char* s) {
        InternalString = s;
    }

    BigInt(int n) {
        InternalString = to_string(n);
    }

    // Member function to add a numeric string to InternalString.
    string Add(string n) {
        return AddNumbers(InternalString, n);
    }

    // Overload operator+ to add two BigInts.
    BigInt operator+(BigInt n) {
        string summ = AddNumbers(InternalString, n.InternalString);
        return BigInt(summ);
    }

    // Friend overloads to add BigInt with int or string.
    friend BigInt operator+(int n, BigInt m) {
        return BigInt(n) + m;
    }

    BigInt operator++(int) {
        BigInt temp(*this);
        *this = *this + 1;
        return temp;
    }


    friend BigInt operator+(string n, BigInt m) {
        return BigInt(n) + m;
    }

    // Overload operator<< to print BigInt.
    friend ostream& operator<<(ostream& out, BigInt& n) {
        out << n.InternalString;
        return out;
    }

    // EXP operator using math library's pow function,This approach converts BigInt to long long
    // so it is only suitable for numbers that fit in a 64-bit integer.
    BigInt operator^(const BigInt& exponent) const {
        // Convert the base and exponent from string to long long.
        long long base_val = stoll(this->InternalString);
        long long exp_val = stoll(exponent.InternalString);

        double res = pow(static_cast<double>(base_val), static_cast<double>(exp_val));

        // Convert the result ll.
        long long result_ll = static_cast<long long>(res);

        return BigInt(to_string(result_ll));
    }
    
};
