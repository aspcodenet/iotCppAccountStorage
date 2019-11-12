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
