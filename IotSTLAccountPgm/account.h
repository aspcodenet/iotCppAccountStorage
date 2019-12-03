#pragma once
#include <iostream>
#include <string>

using namespace std;
typedef enum {
	Ok,
	NotEnoughMoney,
	InvalidAmount
} ACCOUNT_ERRORS;

class Account
{
public:
	Account() { balance = 0.0f; }
	Account(string id, float balance = 0);
	string GetId();
	ACCOUNT_ERRORS Withdraw(float money);
	ACCOUNT_ERRORS Deposit(float money);
	float GetBalance();
private:
	string id;
	float balance;
};


