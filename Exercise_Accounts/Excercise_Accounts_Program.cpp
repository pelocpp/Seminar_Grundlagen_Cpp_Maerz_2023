// ===========================================================================
// Program.cpp // Demo Implementation Inheritance (Accounts)
// ===========================================================================

#include <iostream>

#include "IAccount.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "DepositAccount.h"
#include "StudentsAccount.h"

// function prototypes
void test_accounts();

void test_accounts()
{
    using namespace AccountsAndBank;

    std::cout << "Testing accounts:" << std::endl;

    CurrentAccount ca(123456, 1000);
    ca.deposit(100);
    ca.withdraw(40);
    std::cout << ca << std::endl;

    StudentsAccount sa(343434);
    sa.deposit(50);
    sa.withdraw(25);
    std::cout << sa << std::endl;

    DepositAccount da(654321, 4.0);
    da.deposit(200);
    da.withdraw(120);
    da.computeInterest(31);
    std::cout << da << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
