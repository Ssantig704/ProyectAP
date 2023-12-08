/*
OOP
Created by: Santiago Octavio Garcia Mtz & Ricardo Lupercio Almaras
Date: 11/10/2023
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract class: Product
class Product {
public:
    Product(string name, double price)
        : name_(name), price_(price) {}

    virtual void showInformation() const {
        cout << "Name: " << name_ << ", Price: $" << price_ << " MXN" << endl;
    }

    // Getters and setters
    string getName() const { return name_; }
    double getPrice() const { return price_; }
    void setName(const string& name) { name_ = name; }
    void setPrice(double price) { price_ = price; }

    // Pure virtual method (must be implemented by derived classes)
    virtual void applyDiscount() = 0;

private:
    string name_;
    double price_;
};

// Derived class: Pizza (inherits from Product)
class Pizza : public Product {
public:
    Pizza(string name, double price, string size)
        : Product(name, price), size_(size), ingredients_("Cheese, Tomato, Pepperoni") {}

    void showInformation() const override {
        Product::showInformation();
        cout << "Size: " << size_ << endl;
        cout << "Ingredients: " << ingredients_ << endl;
    }

    // Additional getters and setters
    string getSize() const { return size_; }
    void setSize(const string& size) { size_ = size; }

    // Unique methods of the Pizza class
    void addIngredient(string ingredient) { ingredients_ += ", " + ingredient; }
    void applyDiscount() override { setPrice(getPrice() * 0.9); } // 10% discount

private:
    string size_;
    string ingredients_;
};

// Derived class: Beverage (inherits from Product)
class Beverage : public Product {
public:
    Beverage(string name, double price, string type)
        : Product(name, price), type_(type), volume_(500) {}

    void showInformation() const override {
        Product::showInformation();
        cout << "Type: " << type_ << endl;
        cout << "Volume: " << volume_ << " ml" << endl;
    }

    // Additional getters and setters
    string getType() const { return type_; }
    void setType(const string& type) { type_ = type; }
    int getVolume() const { return volume_; }
    void setVolume(int volume) { volume_ = volume; }

    // Unique methods of the Beverage class
    void cool() { cout << "Cooling the beverage..." << endl; }
    void applyDiscount() override { setPrice(getPrice() * 0.95); } // 5% discount

private:
    string type_;
    int volume_;
};

// Non-member function accessing information from a derived class
void showPrice(const Product& product) {
    cout << "Product price: $" << product.getPrice() << " MXN" << endl;
}

int main() {
    // Create objects of the classes and test constructors
    Pizza pizza1("Margherita Pizza", 145.0, "Medium"); // Changed to Mexican pesos (MXN)
    Beverage beverage1("Coca-Cola", 25.0, "Soft Drink"); // Changed to Mexican pesos (MXN)

    // Object tests
    cout << "Pizza details:\n";
    pizza1.showInformation();
    pizza1.addIngredient("Olives");
    cout << "Pizza details after adding ingredient:\n";
    pizza1.showInformation();

    cout << "\nBeverage details:\n";
    beverage1.showInformation();
    beverage1.cool();

    // Polymorphism: Example of pointers and virtual functions
    vector<Product*> products;
    products.push_back(&pizza1);
    products.push_back(&beverage1);

    cout << "\nProduct information (polymorphism):\n";
    for (Product* product : products) {
        product->showInformation();
        product->applyDiscount(); // Call to the virtual method
        cout << "Price with discount: $" << product->getPrice() << " MXN" << endl;
    }

    // Access information from a derived class using the non-member function
    showPrice(beverage1);

    return 0;
}
