#pragma once
#include "account.h"
#include <vector>
#include <list>
#include <map>

class AccountStorageBase
{
public:
	virtual void AddAccount(string id) = 0;
	virtual Account* GetAccount(string id) = 0;
};

class VectorAccountStorage : public AccountStorageBase
{
public:
	~VectorAccountStorage();
	void AddAccount(string id) ;
	Account* GetAccount(string id);
private:
	vector<Account*> accounts;
};

class VectorAccountNoPointerStorage : public AccountStorageBase
{
public:
	void AddAccount(string id);
	Account* GetAccount(string id);
private:
	vector<Account> accounts;
};




class ListAccountStorage : public AccountStorageBase
{
public:
	void AddAccount(string id);
	Account* GetAccount(string id);
private:
	list<Account*> accounts;
};



class MapAccountStorage : public AccountStorageBase
{
public:
	void AddAccount(string id);
	Account* GetAccount(string id);
private:
	map<string,Account> accounts;
};




