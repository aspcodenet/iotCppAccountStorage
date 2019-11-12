#include "bank.h"

Bank::Bank(VectorAccountStorage* storage)
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



