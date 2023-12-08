/*
RA1000 - Gather information through the application of different learning strategies.
Overload operators
-Sources:
  https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170
Created by: Santiago Octavio Garcia Mtz & Ricardo Lupercio Almaras
20/10/2023
*/

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Default constructor
    Product() : name(""), price(0.0), quantity(0) {}

    // Parameterized constructor
    Product(const string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    // Copy constructor
    Product(const Product& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Destructor
    ~Product() {
        cout << "Destructor: " << name << " deleted." << endl;
    }

    // Function to display product details
    void showDetails() {
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity in stock: " << quantity << endl;
    }

    // Friend function to apply discount
    friend void applyDiscount(Product& product, double discount) {
        product.price -= (product.price * discount);
    }

    // Operator overloading for addition (+) to sum quantities, allows adding two objects of type 'Product'
    Product operator+(const Product& other) {
        Product sum;
        sum.name = name + " and " + other.name;
        sum.price = price + other.price;
        sum.quantity = quantity + other.quantity;
        return sum;
    }

    // Operator overloading for subtraction (-) to subtract quantities, allows subtracting two objects of type 'Product'
    Product operator-(const Product& other) {
        Product subtract;
        subtract.name = "Subtraction of " + name + " and " + other.name;
        subtract.price = price - other.price;
        subtract.quantity = quantity - other.quantity;
        return subtract;
    }

    // Operator overloading for equality (==) to compare product equality, compares two objects of type 'Product' to check if they are equal
    bool operator==(const Product& other) const {
        return (name == other.name && price == other.price && quantity == other.quantity);
    }
};

int main() {
    // Create two products
    Product laptop("Laptop Acer", 800.0, 10);
    Product tablet("Tablet Samsung", 300.0, 5);

    // Perform product addition (operator + overloading), create a new object sumProducts whose attributes are added
    Product sumProducts = laptop + tablet;

    // Display details of the sum of products
    cout << "Details of the sum of products:" << endl;
    sumProducts.showDetails();

    // Perform product subtraction (operator - overloading), create a new object subtractProducts whose attributes are subtracted
    Product subtractProducts = laptop - tablet;

    // Display details of the subtracted products
    cout << "\nDetails of the subtracted products:" << endl;
    subtractProducts.showDetails();

    // Compare product equality (operator == overloading), compare all attributes (name, price, and quantity) to check if two products are equal
    if (laptop == tablet) {
        cout << "\nThe products are equal." << endl;
    } else {
        cout << "\nThe products are different." << endl;
    }

    return 0;
}
