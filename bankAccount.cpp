// bankAccount.cpp
// bankAccount class member definitions

#include "bankAccount.h"

bankAccount::bankAccount(const std::string& name, int accountNumber, double balance)
    : name(name), accountNumber(accountNumber), balance(balance) {
    std::cout << "******* New Account Created *******" << std::endl;
    std::cout << "Name: " << name << "   Account# " << accountNumber << "   Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

bankAccount::~bankAccount() {}

std::string bankAccount::retrieveName() const {
    return name;
}

int bankAccount::retrieveAccountNumber() const {
    return accountNumber;
}

double bankAccount::retrieveBalance() const {
    return balance;
}

void bankAccount::deposit(double amount) {
    balance += amount;
    std::cout << "Account# " << accountNumber << ": Deposit of $" << std::fixed << std::setprecision(2) << amount << " processed." << std::endl;
}

void bankAccount::withdraw(double amount) {
    balance -= amount;
    std::cout << "Account# " << accountNumber << ": Withdrawal of $" << std::fixed << std::setprecision(2) << amount << " processed." << std::endl;

    if (balance < 0) {
        std::cout << "Account# " << accountNumber << ": **Warning** Your balance is now negative!" << std::endl;
    }
}
