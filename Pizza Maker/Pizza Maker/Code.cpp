#include <iostream>
using namespace std;

// Prepare the dough
void MakeDough() {
    cout << "Making Dough..." << endl;
}

// Bake the pizza
void BakePizza() {
    cout << "Baking Pizza..." << endl;
}

// Add beef toppings
void AddBeefToppings() {
    cout << "Adding Beef Toppings..." << endl;
}

// Add cheese toppings
void AddCheeseToppings() {
    cout << "Adding Cheese Toppings..." << endl;
}

// Add chicken toppings
void AddChickenToppings() {
    cout << "Adding Chicken Toppings..." << endl;
}

// Make a beef pizza
void MakeBeefPizza() {
    MakeDough();
    AddBeefToppings();
    BakePizza();
    cout << "Beef Pizza is Done!" << endl;
}

// Make a cheese pizza
void MakeCheesePizza() {
    MakeDough();
    AddCheeseToppings();
    BakePizza();
    cout << "Cheese Pizza is Done!" << endl;
}

// Make a chicken pizza
void MakeChickenPizza() {
    MakeDough();
    AddChickenToppings();
    BakePizza();
    cout << "Chicken Pizza is Done!" << endl;
}

// Main function
int main() {
    int choice;
    cout << "Choose 1 for Beef, 2 for Cheese, 3 for Chicken: ";
    cin >> choice;

    switch (choice) {
    case 1:
        MakeBeefPizza();
        break;
    case 2:
        MakeCheesePizza();
        break;
    case 3:
        MakeChickenPizza();
        break;
    default:
        cout << "Invalid Choice!" << endl;
        break;
    }

    return 0;
}
