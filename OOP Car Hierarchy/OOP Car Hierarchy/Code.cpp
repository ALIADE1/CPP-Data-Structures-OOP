#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string VIN = "ABC123XYZ";
    int year = 2023;
    double price = 50000.0;
    double resaleValue = 40000.0;
    string weight = "1500 kg";
    string length = "4.7 meters";
    string width = "1.8 meters";
    string height = "1.5 meters";
    string Capacity = "5 passengers";
    string color = "Black";
    string doors = "4";
    string bodyType = "Sedan";
    string wheelsize = "18 inches";
    string bodymaterial = "Steel";
    string modelName;

public:
    Car(const string& name) : modelName(name) {}

    virtual void displayDetails()
    {
        cout << "Model: " << modelName << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << "$" << endl;
        cout << "Resale Value: " << resaleValue << "$" << endl;
        cout << "Weight: " << weight << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Capacity: " << Capacity << endl;
        cout << "Color: " << color << endl;
        cout << "Doors: " << doors << endl;
        cout << "Body Type: " << bodyType << endl;
        cout << "Wheel Size: " << wheelsize << endl;
        cout << "Body Material: " << bodymaterial << endl;
    }
};

class Electric : public Car
{
protected:
    string batteryType = "Lithium-ion";
    double batteryCapacity = 75.0;
    double chargingTime = 8.0;
    double range = 400.0;
    string chargingPortType = "CCS";
    string motorType = "AC Induction";
    string regenerativeBraking = "Yes";

public:
    Electric(const string& name) : Car(name) {}

    void displayDetails() override
    {
        Car::displayDetails();
        cout << "Battery Type: " << batteryType << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Charging Time: " << chargingTime << " hours" << endl;
        cout << "Range: " << range << " km" << endl;
        cout << "Charging Port Type: " << chargingPortType << endl;
        cout << "Motor Type: " << motorType << endl;
        cout << "Regenerative Braking: " << regenerativeBraking << endl;
    }
};

class Petrol : public Car
{
protected:
    string fuelType = "Petrol";
    double fuelTankCapacity = 60.0;
    double mileage = 15.5;
    string emissionStandard = "Euro 6";
    string engineType = "V6 Turbo";
    string exhaustSystem = "Dual Exhaust";

public:
    Petrol(const string& name) : Car(name) {}

    void displayDetails() override
    {
        Car::displayDetails();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters" << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Emission Standard: " << emissionStandard << endl;
        cout << "Engine Type: " << engineType << endl;
        cout << "Exhaust System: " << exhaustSystem << endl;
    }
};

// Toyota Models
class ToyotaElectric : public Electric
{
public:
    ToyotaElectric(const string& name) : Electric(name)
    {
        color = "Blue";
        bodyType = "SUV";
    }

    void displayDetails() override
    {
        cout << "Toyota Electric Car Details:" << endl;
        Electric::displayDetails();
    }
};

class ToyotaPetrol : public Petrol
{
public:
    ToyotaPetrol(const string& name) : Petrol(name)
    {
        color = "Red";
        bodyType = "Sedan";
    }

    void displayDetails() override
    {
        cout << "Toyota Petrol Car Details:" << endl;
        Petrol::displayDetails();
    }
};

// Mercedes Models
class MercedesElectric : public Electric
{
public:
    MercedesElectric(const string& name) : Electric(name)
    {
        color = "Silver";
        bodyType = "Coupe";
    }

    void displayDetails() override
    {
        cout << "Mercedes Electric Car Details:" << endl;
        Electric::displayDetails();
    }
};

class MercedesPetrol : public Petrol
{
public:
    MercedesPetrol(const string& name) : Petrol(name)
    {
        color = "Black";
        bodyType = "Sedan";
    }

    void displayDetails() override
    {
        cout << "Mercedes Petrol Car Details:" << endl;
        Petrol::displayDetails();
    }
};

// BMW Models
class BmwElectric : public Electric
{
public:
    BmwElectric(const string& name) : Electric(name)
    {
        color = "White";
        bodyType = "Sedan";
    }

    void displayDetails() override
    {
        cout << "BMW Electric Car Details:" << endl;
        Electric::displayDetails();
    }
};

class BmwPetrol : public Petrol
{
public:
    BmwPetrol(const string& name) : Petrol(name)
    {
        color = "Gray";
        bodyType = "Coupe";
    }

    void displayDetails() override
    {
        cout << "BMW Petrol Car Details:" << endl;
        Petrol::displayDetails();
    }
};

int main()
{
    int carType, brand, model;
    cout << "Enter 1 for Electric, 2 for Petrol: ";
    cin >> carType;
    cout << "Enter 1 for Toyota, 2 for Mercedes, 3 for BMW: ";
    cin >> brand;

    Car* car = nullptr;

    switch (carType)
    {
    case 1: // Electric
        switch (brand)
        {
        case 1: // Toyota
            cout << "Enter 1 for bZ4x, 2 for bZ3, 3 for Mirai: ";
            cin >> model;
            switch (model)
            {
            case 1:
                car = new ToyotaElectric("Toyota bZ4x");
                break;
            case 2:
                car = new ToyotaElectric("Toyota bZ3");
                break;
            case 3:
                car = new ToyotaElectric("Toyota Mirai");
                break;
            default:
                cout << "Invalid model entered." << endl;
                return 1;
            }
            break;

        case 2: // Mercedes
            cout << "Enter 1 for EOS, 2 for EOE, 3 for EOB: ";
            cin >> model;
            switch (model)
            {
            case 1:
                car = new MercedesElectric("Mercedes EOS");
                break;
            case 2:
                car = new MercedesElectric("Mercedes EOE");
                break;
            case 3:
                car = new MercedesElectric("Mercedes EOB");
                break;
            default:
                cout << "Invalid model entered." << endl;
                return 1;
            }
            break;

        case 3: // BMW
            cout << "Enter 1 for I4, 2 for IX, 3 for 17: ";
            cin >> model;
            switch (model)
            {
            case 1:
                car = new BmwElectric("BMW I4");
                break;
            case 2:
                car = new BmwElectric("BMW IX");
                break;
            case 3:
                car = new BmwElectric("BMW 17");
                break;
            default:
                cout << "Invalid model entered." << endl;
                return 1;
            }
            break;
        default:
            cout << "Invalid brand entered." << endl;
            return 1;
        }
        break;

    case 2: // Petrol
        switch (brand)
        {
        case 1: // Toyota
            cout << "Enter 1 for Camry, 2 for RAV4, 3 for Corolla: ";
            cin >> model;
            switch (model)
            {
            case 1:
                car = new ToyotaPetrol("Toyota Camry");
                break;
            case 2:
                car = new ToyotaPetrol("Toyota RAV4");
                break;
            case 3:
                car = new ToyotaPetrol("Toyota Corolla");
                break;
            default:
                cout << "Invalid model entered." << endl;
                return 1;
            }
            break;

        case 2: // Mercedes
            cout << "Enter 1 for C-Class, 2 for GLE, 3 for S-Class: ";
            cin >> model;
            switch (model)
            {
            case 1:
                car = new MercedesPetrol("Mercedes C-Class");
                break;
            case 2:
                car = new MercedesPetrol("Mercedes GLE");
                break;
            case 3:
                car = new MercedesPetrol("Mercedes S-Class");
                break;
            default:
                cout << "Invalid model entered." << endl;
                return 1;
            }
            break;

        case 3: // BMW
            cout << "Enter 1 for X5, 2 for M5, 3 for 3 Series: ";
            cin >> model;
            switch (model)
            {
            case 1:
                car = new BmwPetrol("BMW X5");
                break;
            case 2:
                car = new BmwPetrol("BMW M5");
                break;
            case 3:
                car = new BmwPetrol("BMW 3 Series");
                break;
            default:
                cout << "Invalid model entered." << endl;
                return 1;
            }
            break;
        default:
            cout << "Invalid brand entered." << endl;
            return 1;
        }
        break;
    default:
        cout << "Invalid car type entered." << endl;
        return 1;
    }

    car->displayDetails();
    delete car;

    return 0;
}
