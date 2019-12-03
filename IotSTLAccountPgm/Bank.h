#pragma once
#include "account.h"
#include "vectoraccountstorage.h"


enum class TRANSFER_ERROR
{
	Ok,
	FromAccountNotFound,
	ToAccountNotFound,
	NotEnoughMoney,
	InvalidAmount
};

class Bank
{
public:
	Bank(AccountStorageBase* storage);
	bool AddAccount(string id);
	Account* GetAccount(string id);
	TRANSFER_ERROR Transfer(string idFrom, string idTo, float belopp);
private:
	AccountStorageBase* accountStorage;
};

