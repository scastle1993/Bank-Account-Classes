// noServiceChargeChecking.cpp
// noServiceChargeChecking class member definitions

#include "noServiceChargeChecking.h"

noServiceChargeChecking::noServiceChargeChecking(const std::string& name, int accountNumber, double balance, double minimumBalance, double interestRate)
    : checkingAccount(name, accountNumber, balance), minimumBalance(minimumBalance), interestRate(interestRate) {}

noServiceChargeChecking::~noServiceChargeChecking() {}

void noServiceChargeChecking::writeCheck(double amount) {
    if (balance - amount < minimumBalance) {
        std::cout << "Account# " << retrieveAccountNumber() << ": Error: Account balance cannot fall below minimum balance of $" << minimumBalance << std::endl;
    }
    else {
        checkingAccount::withdraw(amount);
    }
}

void noServiceChargeChecking::createMonthlyStatement() {
    std::cout << "\n******* Monthly statement for Account #" << retrieveAccountNumber() << " *******" << std::endl;
    std::cout << "Beginning balance: $" << retrieveBalance() << std::endl;
    addInterest();
    std::cout << "Ending balance: $" << retrieveBalance() << std::endl;
}

void noServiceChargeChecking::addInterest() {
    double interest = retrieveBalance() * interestRate / 12;
    bankAccount::deposit(interest);
    std::cout << "Account# " << retrieveAccountNumber() << ": Interest Paid: $" << std::fixed << std::setprecision(2) << interest << "\n";
}