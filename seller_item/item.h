#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <iostream>

class Item {
private:
    int id; // Added id
    int price;
    int quantity;
    std::string name;
    Buyer* buyer; // Pointer to associated Buyer

public:
    // Default constructor
    Seller() : id(0), price(0), quantity(0), name("Unknown"), buyer(nullptr) {}

    // Parameterized constructor
    Seller(int i, int p, int q, const std::string& n, Buyer* b = nullptr)
        : id(i), price(p), quantity(q), name(n), buyer(b) {}

    // Getters
    int getId() const { return id; }
    int getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    std::string getName() const { return name; }
    Buyer* getBuyer() const { return buyer; }

    // Setters
    void setId(int i) { id = i; }
    void setPrice(int p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void setName(const std::string& n) { name = n; }
    void setBuyer(Buyer* b) { buyer = b; }

    // Display info
    void display() const {
        std::cout << "Seller ID: " << id
                  << ", Name: " << name
                  << ", Price: " << price
                  << ", Quantity: " << quantity;
        if (buyer)
            std::cout << ", Buyer: " << buyer->getName();
        std::cout << std::endl;
    }
};

#endif
