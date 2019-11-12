#include "VectorAccountStorage.h"

VectorAccountStorage::~VectorAccountStorage()
{
	for (int i = 0; i < accounts.size(); i++)
		delete accounts[i];
}

void VectorAccountStorage::AddAccount(std::string id)
{
	Account* account = new Account(id);
	accounts.push_back(account);
}

Account* VectorAccountStorage::GetAccount(std::string id)
{
	for (int i = 0; i < accounts.size(); i++)
		if (accounts[i]->GetId() == id) return accounts[i];
	return nullptr;
}


