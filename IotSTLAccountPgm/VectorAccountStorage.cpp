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


void ListAccountStorage::AddAccount(std::string id)
{
	Account* account = new Account(id);
	accounts.push_back(account);
}

Account* ListAccountStorage::GetAccount(std::string id)
{
	for (auto a : accounts)
		if (a->GetId() == id) return a;
	return nullptr;
}






void VectorAccountNoPointerStorage::AddAccount(std::string id)
{
	Account account = Account(id);
	accounts.push_back(account);
}

Account* VectorAccountNoPointerStorage::GetAccount(std::string id)
{
	for (int i = 0; i < accounts.size(); i++)
		if (accounts[i].GetId() == id) return &accounts[i];
	return nullptr;
}




void MapAccountStorage::AddAccount(std::string id)
{
	Account account = Account(id);
	accounts[id] = account;
}

Account* MapAccountStorage::GetAccount(std::string id)
{
	Account a = accounts[id];
	if(a.GetId() == id)
		return &a;
	return nullptr;
}




