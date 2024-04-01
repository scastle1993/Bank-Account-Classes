// serviceChargeChecking.h
// serviceChargeChecking class derived from class checkingAccount
// Member functions defined in serviceChargeChecking.cpp

#pragma once
#include "checkingAccount.h"

class serviceChargeChecking : public checkingAccount {
private:
    double checkWritingFee;
    int maxChecks;
    int numChecksWritten;

public:
    serviceChargeChecking(const std::string& name, int accountNumber, double balance,
        double fee, int maxChecks);
    virtual ~serviceChargeChecking();
    void writeCheck(double amount) override;
    void monthlyFee();
    void createMonthlyStatement() override;
};

