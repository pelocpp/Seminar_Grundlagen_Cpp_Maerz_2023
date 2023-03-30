// ===============================================================================
// Account.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#pragma once

#include <iostream>

#include "IAccount.h"

namespace AccountsAndBank {

    class Account : public IAccount
    {
    protected:
        int    m_accountNumber;
        double m_balance;

    public:
        // default c'tor / d'tor
        virtual ~Account() {
            std::cout << "~Account" << std::endl;
        
        };

        Account(int account);

        // getter / setter
        double getAccountNumber() final override;
        double getBalance() final override;

        // public interface
        void deposit(double amount) final override;

        // virtual bool withdraw(double amount) = 0;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
