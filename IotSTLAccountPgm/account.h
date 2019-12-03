#pragma once
#include <iostream>
#include <string>

using namespace std;
enum class ACCOUNT_ERRORS
 {
	Ok,
	NotEnoughMoney,
	InvalidAmount
} ;

class Account
{
public:
	Account() { balance = 0.0f; 	}
	Account(string id, float balance = 0);
	string GetId();
	ACCOUNT_ERRORS Withdraw(float money);
	ACCOUNT_ERRORS Deposit(float money);
	float GetBalance();
private:
	string id;
	float balance;
};


