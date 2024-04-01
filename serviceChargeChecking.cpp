// serviceChargeChecking.cpp
// serviceChargeChecking class member definitions

#include "serviceChargeChecking.h"

serviceChargeChecking::serviceChargeChecking(const std::string& name, int accountNumber,
    double balance, double fee, int maxChecks)
    : checkingAccount(name, accountNumber, balance), checkWritingFee(fee),
    maxChecks(maxChecks), numChecksWritten(0) {}

serviceChargeChecking::~serviceChargeChecking() {}

void serviceChargeChecking::writeCheck(double amount) {
    if (numChecksWritten >= maxChecks) {
        std::cout << "Account# " << retrieveAccountNumber() << ": Maximum number of checks written for this month." << std::endl;
        return;
    }
    if (amount > retrieveBalance()) {
        std::cout << "Account# " << retrieveAccountNumber() << ": Insufficient balance." << std::endl;
        return;
    }
    checkingAccount::withdraw(amount);
    numChecksWritten++;
}

void serviceChargeChecking::createMonthlyStatement() {
    std::cout << "\n******* Monthly statement for Account #" << retrieveAccountNumber() << " *******" << std::endl;
    std::cout << "Beginning balance: $" << retrieveBalance() << std::endl;
    monthlyFee();
    std::cout << "Ending balance: $" << retrieveBalance() << std::endl;
}

void serviceChargeChecking::monthlyFee() {
    double fee = checkWritingFee * numChecksWritten;
    checkingAccount::withdraw(fee);
    std::cout << "Account# " << retrieveAccountNumber() << ": Monthly service fee charged: $" << fee << "  ($" << checkWritingFee << " * " << numChecksWritten << " checks written)" << std::endl;
}
