#pragma once
#include "account.h"
#include <vector>

class VectorAccountStorage
{
public:
	~VectorAccountStorage();
	void AddAccount(string id) ;
	Account* GetAccount(string id);
private:
	vector<Account*> accounts;
};

