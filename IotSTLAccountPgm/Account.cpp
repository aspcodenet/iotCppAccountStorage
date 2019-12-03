#include "account.h"
#include <algorithm>

Account::Account(string id, float balance)
{
	this->id = id;
	this->balance = balance;
}

string Account::GetId()
{
	return this->id;
}

ACCOUNT_ERRORS Account::Withdraw(float money)
{
	if(money < 0) return ACCOUNT_ERRORS::InvalidAmount;
	if (money > balance) return ACCOUNT_ERRORS::NotEnoughMoney;
	balance -= money;
	return ACCOUNT_ERRORS::Ok;
}

ACCOUNT_ERRORS Account::Deposit(float money)
{
	if (money < 0) return ACCOUNT_ERRORS::InvalidAmount;
	balance += money;
	return ACCOUNT_ERRORS::Ok;
}

float Account::GetBalance()
{
	return balance;
}
