#pragma once
#include <iostream>
#include <string>

using namespace std;
//typedef enum {
//	Ok,
//	Account_NotEnoughMoney
//} ACCOUT_ERRORS;

class Account
{
public:
	Account() {}
	Account(string id, float balance = 0);
	string GetId();
	//ACCOUT_ERRORS Withdraw(float money);
private:
	string id;
	float balance;
};

