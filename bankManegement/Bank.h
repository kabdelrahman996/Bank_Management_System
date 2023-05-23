#pragma once
#include <vector>
#include "Account.h"

using namespace std;
class Bank
{
private:
	vector<Account> accounts;
	double fees = 120;
	double interest = 0.18;

public:

	// Constructor
	Bank();

	// Create New Account
	void create_acc(int, int, int, string, string, double);

	// Management Accounts
	bool deposit(int, double);
	bool withdraw(int, double);
	bool transfer(int, int, double);
	double calculate_interest(Account& );
	double calculate_fees(Account& );

	// change interest and fees
	void change_interest(double);
	void change_fees(double);
	
};

