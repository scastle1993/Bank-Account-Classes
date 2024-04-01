// highInterestSavings.cpp
// highInterestSavings class member definitions

#include "highInterestSavings.h"

highInterestSavings::highInterestSavings(std::string name, int acctNumber, double bal, double intRate, double minBal)
    : savingsAccount(name, acctNumber, bal, intRate), minimumBalance(minBal)
{
    if (balance >= minimumBalance) {
        std::cout << "Account# " << accountNumber << ": Congratulations, you qualify for our premium interest rate!" << std::endl;
        interestRate += interestRatePremium;        // Add interest rate premium
    }
    else {
        std::cout << "Balance below minimum for the premium interest rate." << std::endl;
    }
}

highInterestSavings::~highInterestSavings() {}

void highInterestSavings::deposit(double amount)
{
    if (retrieveBalance() < minimumBalance) {
        savingsAccount::deposit(amount);
        if (retrieveBalance() >= minimumBalance) {
            std::cout << "Account# " << retrieveAccountNumber() << ": Congratulations, you qualify for our premium interest rate!" << std::endl;
            interestRate += interestRatePremium;    // Add interest rate premium
        }
    }
    else {
        savingsAccount::deposit(amount);
    }
}

void highInterestSavings::withdraw(double amount)
{
    if (retrieveBalance() >= minimumBalance) {
        savingsAccount::withdraw(amount);
        if (retrieveBalance() < minimumBalance) {
            std::cout << "Account# " << retrieveAccountNumber() << ": Balance below minimum for the premium interest rate." << std::endl;
            interestRate -= interestRatePremium;    // Remove interest rate premium
        }
    }
    else {
        savingsAccount::withdraw(amount);
    }
}

void highInterestSavings::createMonthlyStatement()
{
    savingsAccount::createMonthlyStatement(); // call base class function for regular monthly statement
    if (retrieveBalance() >= minimumBalance) {
        std::cout << "You currently qualify for our premium interest rate." << std::endl;
    }
}