#pragma once
#include <string>
#include "bank_customer.h"
#include "item.h"

using namespace std;

class Seller {
private:
    int id;
    std::string name;
    BankCustomer& account;

public:
    Seller(int id, const std::string& name, BankCustomer& account) : id(id), name(name), account(account) {}

    int getId() const { return id; }
    std::string getName() const { return name; }

    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
};