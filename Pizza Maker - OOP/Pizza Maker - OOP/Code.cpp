#include <iostream>
using namespace std;

// Representing a generic Pizza
class Pizza
{
private:
    void MakeDough() {
        cout << GetPizzaName() << " pizza dough" << endl;
    }

    void AddPizzaToppings() {
        cout << GetPizzaName() << " adding toppings" << endl;
    }

    void BakePizza() {
        cout << GetPizzaName() << " pizza baked" << endl;
    }

protected:
    // Return the name of the pizza
    virtual const char* GetPizzaName() const = 0;

public:
    void MakePizza() {
        MakeDough();
        AddPizzaToppings();
        BakePizza();
        cout << GetPizzaName() << " pizza done!" << endl;
    }

    // Cleanup of derived class objects
    virtual ~Pizza() = default;
};

// Derived class for Chicken Pizza
class ChickenPizza : public Pizza
{
protected:
    const char* GetPizzaName() const override {
        return "Chicken";
    }
};

// Derived class for Beef Pizza
class BeefPizza : public Pizza
{
protected:
    const char* GetPizzaName() const override {
        return "Beef";
    }
};

// Derived class for Cheese Pizza
class CheesePizza : public Pizza
{
protected:
    const char* GetPizzaName() const override {
        return "Cheese";
    }
};

// Accepts a pointer to a Pizza object and calls its MakePizza function
void MakePizza(Pizza* p)
{
    p->MakePizza();
}

int main() {
    int choice;
    cout << "Choose 1 for Beef, 2 for Cheese, 3 for Chicken: ";
    cin >> choice;

    // Pointer to store the dynamically created Pizza object
    Pizza* p = nullptr;

    switch (choice) {
    case 1:
        p = new BeefPizza;
        break;
    case 2:
        p = new CheesePizza;
        break;
    case 3:
        p = new ChickenPizza;
        break;
    default:
        cout << "Invalid Choice!" << endl;
        return 0;
    }

    // Call the MakePizza function for the created pizza
    MakePizza(p);

    // Free the dynamically allocated memory
    delete p;
    return 0;
}
