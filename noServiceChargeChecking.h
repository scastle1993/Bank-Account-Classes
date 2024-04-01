// noServiceChargeChecking.h
// noServiceChargeChecking class derived from class checkingAccount
// Member functions defined in noServiceChargeChecking.cpp

#pragma once
#include "checkingAccount.h"

class noServiceChargeChecking : public checkingAccount {
protected:
    double minimumBalance;
    double interestRate;
public:
    noServiceChargeChecking(const std::string& name, int accountNumber, double balance, double minimumBalance, double interestRate);
    virtual ~noServiceChargeChecking();
    virtual void writeCheck(double amount) override;
    virtual void createMonthlyStatement() override;
    virtual void addInterest();
};
