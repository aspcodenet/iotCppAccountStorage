#pragma once
#include "account.h"
#include "vectoraccountstorage.h"

class Bank
{
public:
	Bank(AccountStorageBase* storage);
	bool AddAccount(string id);
	Account* GetAccount(string id);
private:
	AccountStorageBase* accountStorage;
};

