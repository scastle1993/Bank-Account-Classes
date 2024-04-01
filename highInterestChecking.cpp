// highInterestChecking.cpp
// highInterestChecking class member definitions

#include "highInterestChecking.h"

highInterestChecking::highInterestChecking(const std::string& name, int accountNumber, double balance, double minimumBalance, double interestRate)
    : noServiceChargeChecking(name, accountNumber, balance, minimumBalance, interestRate) {
    
    if (balance >= premiumMinimumBalance) {
        std::cout << "Account# " << accountNumber << ": Congratulations, you qualify for our premium interest rate!" << std::endl;
        interestRate += interestRatePremium;    // Add interest rate premium
    }
    else {
        std::cout << "Account# " << accountNumber << ": Balance below minimum for the premium interest rate." << std::endl;
    }
}

highInterestChecking::~highInterestChecking() {}

void highInterestChecking::deposit(double amount) {
    if (retrieveBalance() < premiumMinimumBalance) {
        noServiceChargeChecking::deposit(amount);
        if (retrieveBalance() >= premiumMinimumBalance) {
            std::cout << "Account# " << retrieveAccountNumber() << ": Congratulations, you qualify for our premium interest rate!" << std::endl;
            interestRate += interestRatePremium;    // Add interest rate premium
        }
    }
    else {
        noServiceChargeChecking::deposit(amount);
    }
}

void highInterestChecking::withdraw(double amount) {
    if (retrieveBalance() >= premiumMinimumBalance) {
        noServiceChargeChecking::withdraw(amount);
        if (retrieveBalance() < premiumMinimumBalance) {
            std::cout << "Account# " << retrieveAccountNumber() << ": Balance below minimum for the premium interest rate." << std::endl;
            interestRate -= interestRatePremium;    // Remove interest rate premium
        }
    }
    else {
        noServiceChargeChecking::withdraw(amount);
    }
}

void highInterestChecking::createMonthlyStatement() {
    noServiceChargeChecking::createMonthlyStatement(); // call base class function for regular monthly statement
    if (retrieveBalance() >= premiumMinimumBalance) {
        std::cout << "You currently qualify for our premium interest rate." << std::endl;
    }
}
