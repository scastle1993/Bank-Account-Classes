// checkingAccount.cpp
// checkingAccount class member definitions

#include "checkingAccount.h"

checkingAccount::checkingAccount(const std::string& name, int accountNum, double balance)
    : bankAccount(name, accountNum, balance)
{
}

checkingAccount::~checkingAccount() {}

void checkingAccount::deposit(double amount)
{
    bankAccount::deposit(amount);
}

void checkingAccount::withdraw(double amount)
{
    bankAccount::withdraw(amount);
}
