// certificateOfDeposit.cpp
// certificateOfDeposit class member definitions

#include "certificateOfDeposit.h"

certificateOfDeposit::certificateOfDeposit(std::string name, int accountNumber, double balance, int maturityMonths, double interestRate)
    : bankAccount(name, accountNumber, balance), maturityMonths(maturityMonths), interestRate(interestRate), currentMonth(1) {}

certificateOfDeposit::~certificateOfDeposit() {}

void certificateOfDeposit::deposit(double amount) {
    if (currentMonth <= maturityMonths) {
        bankAccount::deposit(amount);
    }
    else {
        std::cout << "Account# " << retrieveAccountNumber() << ": Cannot deposit. Certificate of deposit has matured." << std::endl;
    }
}

void certificateOfDeposit::withdraw(double amount) {
    if (currentMonth <= maturityMonths) {
        double penalty = calculatePenalty();
        double totalWithdrawal = amount + penalty;
        if (totalWithdrawal <= retrieveBalance()) {
            std::cout << "Account# " << retrieveAccountNumber() << ": Early withdrawal penalty charged: $" << std::fixed << std::setprecision(2) << penalty << std::endl;
            bankAccount::withdraw(totalWithdrawal);
        }
        else {
            std::cout << "Account# " << retrieveAccountNumber() << ": Withdrawal amount exceeds balance and penalty." << std::endl;
        }
    }
    else {
        std::cout << "Account# " << retrieveAccountNumber() << ": Cannot withdraw. Certificate of deposit has matured." << std::endl;
    }
}

void certificateOfDeposit::createMonthlyStatement() {
    std::cout << "\n******* Certificate of Deposit statement for Account #" << retrieveAccountNumber() << " *******" << std::endl;
    std::cout << "Beginning balance: $" << retrieveBalance() << std::endl;
    addInterest();
    std::cout << "Ending balance: $" << retrieveBalance() << std::endl;
    currentMonth++;
}

void certificateOfDeposit::addInterest() {
    double interest = retrieveBalance() * interestRate / 12;
    bankAccount::deposit(interest);
    std::cout << "Account# " << retrieveAccountNumber() << ": Interest Paid: $" << std::fixed << std::setprecision(2) << interest << std::endl;
}

double certificateOfDeposit::calculatePenalty() {
    double penalty = retrieveBalance() * 0.1;
    return penalty;
}

