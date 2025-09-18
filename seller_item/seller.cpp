#include "seller.h"
#include "item.h"
#include <iostream>

// Constructor
Seller::Seller() : savings(0.0) {}

// Add item
void Seller::addItem(const std::string& name, int price, int quantity) {
    items.emplace_back(name, price, quantity);
}

// Display items
void Seller::displayItems() const {
    std::cout << "Items for sale:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.name
                  << " | Price: " << item.price
                  << " | Quantity: " << item.quantity << std::endl;
    }
}

// Deposit money
void Seller::deposit(double amount) {
    if (amount > 0) {
        savings += amount;
        std::cout << "Deposited: " << amount << ", Total savings: " << savings << std::endl;
    }
}

// Withdraw money
bool Seller::withdraw(double amount) {
    if (amount > 0 && amount <= savings) {
        savings -= amount;
        std::cout << "Withdrew: " << amount << ", Remaining savings: " << savings << std::endl;
        return true;
    }
    std::cout << "Withdrawal failed! Not enough savings.\n";
    return false;
}

// Receive payment for an item
bool Seller::receivePayment(const std::string& itemName, int qty) {
    for (auto& item : items) {
        if (item.name == itemName && item.quantity >= qty) {
            int totalPrice = item.price * qty;
            item.quantity -= qty;
            savings += totalPrice;
            std::cout << "Sold " << qty << " x " << itemName
                      << " for " << totalPrice
                      << ". New savings: " << savings << std::endl;
            return true;
        }
    }
    std::cout << "Transaction failed! Item not found or insufficient stock.\n";
    return false;
}

// Get savings
double Seller::getSavings() const {
    return savings;
}
