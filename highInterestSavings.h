// highInterestSavings.h
// highInterestSavings class derived from class savingsAccount
// Member functions defined in highInterestSavings.cpp

#pragma once
#include "savingsAccount.h"

class highInterestSavings : public savingsAccount
{
private:
    double minimumBalance;
    double interestRatePremium = 0.01;
public:
    highInterestSavings(std::string name, int acctNumber, double bal, double intRate, double minBal);
    virtual ~highInterestSavings();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void createMonthlyStatement() override;
};
