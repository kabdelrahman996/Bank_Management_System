#include "Account.h"

Account::Account(int num,int a, int ph,string n, string ad, double amount)
{
	acc_number = num;
	balance = amount;
	age = a;
	phone_number = ph;
	name = n;
	address = ad;
}

int Account::get_acc_number()
{
	return acc_number;
}

double Account::get_balance()
{
	return balance;
}

void Account::display()
{
	cout << "Welcome " << name << endl;
	cout << "here is your data: \nAccount Number: "<< acc_number<< "\nage: " << age << "          address : " << address << "          phone number : " << phone_number << "\nYour Balance IS : " << balance << endl;
}

void Account::set_acc_number(int num)
{
	acc_number = num;
}

void Account::deposit(double amount)
{
	balance += amount;
}

bool Account::withdraw(double amount)
{
	if (balance >= amount)
	{
		balance -= amount;
		return true;
	}
	else
		return false;
}

bool Account::transfer(Account& to_acc, double amount)
{
	if (balance >= amount)
	{
		balance -= amount;
		to_acc.deposit(amount);
		return true;
	}
	else
		return false;
}
