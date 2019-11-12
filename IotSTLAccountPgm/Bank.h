#pragma once
#include "account.h"
#include "vectoraccountstorage.h"

class Bank
{
public:
	Bank(VectorAccountStorage* storage);
	bool AddAccount(string id);
	Account* GetAccount(string id);
private:
	VectorAccountStorage* accountStorage;
};

