#include "BigInt.h"
#include <iostream>
using namespace std;

void main() {

    // Create BigInt objects
    BigInt a("123456789");
    BigInt b(98765);
    BigInt c("314159");

    // e.x 1: Addition of two BigInts.
    BigInt sum1 = a + b;
    cout << "Addition (a + b): " << sum1 << endl; 

    // e.x 2: Addition using friend overloads
    BigInt sum2 = 1000 + a;
    cout << "Addition (1000 + a): " << sum2 << endl;

    // e.x 3: Addition using friend overloads
    BigInt sum3 = string("5000") + b;
    cout << "Addition (\"5000\" + b): " << sum3 << endl;

    // e.x 4: Exponentiation using operator^.
    BigInt base(2);
    BigInt exponent(10);
    BigInt power = base ^ exponent;
    cout << "Exponentiation (2 ^ 10): " << power << endl;


    BigInt i = 15;
    BigInt j = 10;
    i++;
    BigInt k = i + j;
    //k++;
    cout << "Sum after increment= " << k << endl;


}
