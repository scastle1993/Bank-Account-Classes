// savingsAccount.h
// savingsAccount class derived from class bankAccount
// Member functions defined in savingsAccount.cpp

#pragma once
#include "bankAccount.h"

class savingsAccount : public bankAccount {
protected:
    double interestRate;
public:
    savingsAccount(const std::string& name, int acctNum, double bal, double intRate);
    virtual ~savingsAccount();
    virtual void withdraw(double amount) override;
    virtual void createMonthlyStatement() override;
    virtual void addInterest();
};
