#pragma once
#include <string>

class BankAccount
{
private:
	double balance;
	std::string holderName;
public:
	BankAccount()
	{
		this->balance = 0.0;
		this->holderName = "";
	};
	BankAccount(double balance, std::string holderName)
	{
		this->balance = balance;
		this->holderName = holderName;
	};

	void setBalance(double balance)
	{
		this->balance = balance;
	};
	void setHolderName(std::string holderName)
	{
		this->holderName = holderName;
	};
	void updateBalance(double balance)
	{
		this->balance += balance;
	};

	double getBalance()
	{
		return this->balance;
	};
	std::string getHolderName()
	{
		return this->holderName;
	};
};