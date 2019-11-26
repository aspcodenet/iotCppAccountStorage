#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
	Account() {}
	Account(string id, float balance = 0);
	string GetId();
private:
	string id;
	float balance;
};

