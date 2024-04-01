// bankAccount.h
// bankAccount class definition showing composition.
// 
// Member functions defined in implementation files bankAccount.cpp 
// serviceChargeChecking.cpp, noServiceChargeChecking.cpp, highInterestChecking.cpp, 
// savingsAccount.cpp, highInterestSavings.cpp, and certificateOfDeposit.cpp.
//
// Author: Sean Castle

#pragma once

#include <iostream>          // Preprocessing directives
#include <string>
#include <vector>
#include <iomanip>

class bankAccount {
protected:
    std::string name;
    int accountNumber;
    double balance;
public:
    bankAccount(const std::string& name, int accountNumber, double balance);
    virtual ~bankAccount();
    virtual std::string retrieveName() const;
    virtual int retrieveAccountNumber() const;
    virtual double retrieveBalance() const;
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void createMonthlyStatement() = 0; // pure virtual function
};

