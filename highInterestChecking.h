// highInterestChecking.h
// highInterestChecking class derived from class noServiceChargeChecking
// Member functions defined in highInterestChecking.cpp

#pragma once
#include "noServiceChargeChecking.h"

class highInterestChecking : public noServiceChargeChecking {
private:
    double premiumMinimumBalance = 5000.00;
    double interestRatePremium = 0.01; 
public:
    highInterestChecking(const std::string& name, int accountNumber, double balance, double minimumBalance, double interestRate);
    virtual ~highInterestChecking();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void createMonthlyStatement() override;
};
