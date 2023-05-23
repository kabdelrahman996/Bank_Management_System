#pragma once
#include <iostream>

using namespace std;

class Account
{
private:
	int acc_number;
	double balance;
	string name;
	string address;
	int age;
	int phone_number;

public:
	// Constructor
	Account(int, int, int,string, string, double);

	// Get Account Data
	int get_acc_number();
	double get_balance();
	void display();
	void set_acc_number(int num);

	// Management The Account
	void deposit(double);
	bool withdraw(double);
	bool transfer(Account&, double);
	
};

