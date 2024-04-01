// savingsAccount.cpp
// savingsAccount class member definitions

#include "savingsAccount.h"

savingsAccount::savingsAccount(const std::string& name, int acctNum, double bal, double intRate)
    : bankAccount(name, acctNum, bal), interestRate(intRate) {}

savingsAccount::~savingsAccount() {}

void savingsAccount::withdraw(double amount) {
    if (balance - amount < 0) {
        std::cout << "Account# " << retrieveAccountNumber() << ": Error: Insufficient funds.\n";
    }
    else {
        bankAccount::withdraw(amount);
    }
}

void savingsAccount::createMonthlyStatement() {
    double interest = retrieveBalance() * (interestRate / 12);
    std::cout << "\n******* Monthly statement for Account #" << retrieveAccountNumber() << " *******" << std::endl;
    std::cout << "Beginning Balance: $" << std::fixed << std::setprecision(2) << retrieveBalance() << "\n";
    addInterest();
    std::cout << "Ending Balance: $" << std::fixed << std::setprecision(2) << retrieveBalance() << "\n\n";
}

void savingsAccount::addInterest() {
    double interest = retrieveBalance() * interestRate / 12;
    bankAccount::deposit(interest);
    std::cout << "Account# " << retrieveAccountNumber() << ": Interest Paid: $" << std::fixed << std::setprecision(2) << interest << "\n";
}
