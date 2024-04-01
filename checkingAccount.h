// checkingAccount.h
// checkingAccount class derived from class bankAccount
// Member functions defined in checkingAccount.cpp

#pragma once
#include "bankAccount.h"

class checkingAccount : public bankAccount {
public:
    checkingAccount(const std::string& name, int accountNum, double balance);
    virtual ~checkingAccount();
    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void createMonthlyStatement() override = 0;
    virtual void writeCheck(double amount) = 0; 
};
