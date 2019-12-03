#include "bank.h"

Bank::Bank(AccountStorageBase* storage)
{
	accountStorage = storage;
}

bool Bank::AddAccount(std::string id)
{
	accountStorage->AddAccount(id);
	return true;
}

Account* Bank::GetAccount(std::string id)
{
	return accountStorage->GetAccount(id);
}

TRANSFER_ERROR Bank::Transfer(string idFrom, string idTo, float belopp)
{
	auto from = GetAccount(idFrom);
	if (from == nullptr)
		return TRANSFER_ERROR::FromAccountNotFound;
	
	auto to = GetAccount(idTo);
	if (to == nullptr)
		return TRANSFER_ERROR::ToAccountNotFound;

	if (belopp < 0)
		return TRANSFER_ERROR::InvalidAmount;

	if (from->GetBalance() < belopp)
		return TRANSFER_ERROR::NotEnoughMoney;
	
	from->Withdraw(belopp);
	to->Deposit(belopp);
	return TRANSFER_ERROR::Ok;
}



