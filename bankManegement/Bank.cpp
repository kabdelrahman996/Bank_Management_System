#include "Bank.h"

Bank::Bank() {

}

void Bank::create_acc(int num, int a, int ph, string n, string ad, double amount)
{
	Account acc(num,  a,  ph, n,  ad,  amount);
	accounts.push_back(acc);
}

bool Bank::deposit(int num, double amount)
{
    for (auto& account : accounts) {
        if (account.get_acc_number() == num) {
            account.deposit(amount);
            return true;
        }
    }
    return false;
}

bool Bank::withdraw(int num, double amount)
{
    for (auto& account : accounts) {
        if (account.get_acc_number() == num) {
            if(account.get_balance() >= amount)
            {
                account.withdraw(amount);
                return true;
            }
        }
    }
    return false;
}

bool Bank::transfer(int from_account_number, int to_account_number, double amount) {
    Account* from_account = nullptr;
    Account* to_account = nullptr;
    for (auto& account : accounts) {
        if (account.get_acc_number() == from_account_number) {
            from_account = &account;
        }
        if (account.get_acc_number() == to_account_number) {
            to_account = &account;
        }
    }
    if (from_account != nullptr && to_account != nullptr) {
        return from_account->transfer(*to_account, amount);
    }
    return false;
}

double Bank::calculate_interest(Account& account) 
{
    return account.get_balance() * interest;
}

double Bank::calculate_fees(Account& account) 
{
    return account.get_balance() * fees;
}

void Bank::change_interest(double new_interest)
{
    interest = new_interest;
}

void Bank::change_fees(double new_fees)
{
    fees = new_fees;
}