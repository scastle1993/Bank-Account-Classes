// certificateOfDeposit.h
// certificateOfDeposit class derived from class bankAccount
// Member functions defined in certificateOfDeposit.cpp

#pragma once
#include "bankAccount.h"

class certificateOfDeposit : public bankAccount {
private:
    int maturityMonths;
    double interestRate;
    int currentMonth;
public:
    certificateOfDeposit(std::string name, int accountNumber, double balance, int maturityMonths, double interestRate);
    virtual ~certificateOfDeposit();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void createMonthlyStatement() override;
    void addInterest();
    double calculatePenalty();
};
