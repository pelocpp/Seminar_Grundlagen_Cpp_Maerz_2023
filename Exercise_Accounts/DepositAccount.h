// ===============================================================================
// DepositAccount.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#pragma once

#include <iostream>

#include "Account.h"

namespace AccountsAndBank {

    class DepositAccount final : public Account
    {
        friend std::ostream& operator<< (std::ostream&, const DepositAccount&);

    private:
        double m_interestRate;

    public:
        // c'tors
        virtual ~DepositAccount() {
            std::cout << "~Account" << std::endl;
        };

        DepositAccount(int account);
        DepositAccount(int account, double interestRate);

        // public interface
        bool withdraw(double amount) override;
        void print(std::ostream& os) override;

        void computeInterest(int days);

        // getter / setter
        double getInterestRate();
    };
}
    
// ===============================================================================
// End-of-File
// ===============================================================================
