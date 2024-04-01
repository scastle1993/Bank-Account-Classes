/**********************************************************************************************
 *
 * CIS269 - Data Structures
 * Pima College - Spring 2024
 * Chapter 12 - Pg 904 - Ex #5
 * Bank Accounts - "driver.cpp"
 *
 * This program creates and tests the functionalities of abstract and concrete bank account classes.
 *
 * Author: Sean Castle
 *
**********************************************************************************************/

#include "bankAccount.h"     // Class headers

#include "checkingAccount.h"
#include "serviceChargeChecking.h"
#include "noServiceChargeChecking.h"
#include "highInterestChecking.h"

#include "savingsAccount.h"
#include "highInterestSavings.h"

#include "certificateOfDeposit.h"

using namespace std;

// Main
int main() {
    
    // Creating a service charge checking account
    serviceChargeChecking checking1("John Smith", 1234, 500.00, 2.00, 5);
    checking1.writeCheck(100);
    checking1.createMonthlyStatement();
    cout << endl;
    
    // Creating a no service charge checking account
    noServiceChargeChecking checking2("Jane Doe", 5678, 1000.00, 200.00, 0.01);
    checking2.writeCheck(900);
    checking2.deposit(500);
    checking2.createMonthlyStatement();
    cout << endl;
    
    // Creating a high interest checking account
    highInterestChecking checking3("Bob Johnson", 9101, 5000, 200, 0.01);
    checking3.writeCheck(100);
    checking3.deposit(500);
    checking3.createMonthlyStatement();
    cout << endl;
    
    // Creating a savings account
    savingsAccount savings1("Mary Brown", 1112, 10000.00, 0.02);
    savings1.withdraw(500);
    savings1.deposit(1000);
    savings1.createMonthlyStatement();
    cout << endl;
    
    // Creating a high interest savings account
    highInterestSavings savings2("Tom Williams", 1314, 2500.00, 0.02, 1000.00);
    savings2.withdraw(2000);
    savings2.deposit(1000);
    savings2.createMonthlyStatement();
    cout << endl;
    
    // Creating a certificate of deposit
    certificateOfDeposit CD1("Harry White", 1516, 5000, 12, 0.08);
    CD1.withdraw(2000);
    CD1.deposit(1000);
    CD1.createMonthlyStatement();
    cout << endl;
    
    return 0;
}//End main

