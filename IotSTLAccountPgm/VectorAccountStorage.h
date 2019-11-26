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

class DistributedVectorAccountNoPointerStorage : public AccountStorageBase
{
public:
	void AddAccount(string id);
	Account* GetAccount(string id);
private:
	vector<Account> accounts1;
	vector<Account> accounts2;
	vector<Account> accounts3;
	vector<Account> accounts4;
	vector<Account> accounts5;
	vector<Account> accounts6;
	vector<Account> accounts7;
	vector<Account> accounts8;
	vector<Account> accounts9;
	vector<Account> accounts0;
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




class MultiDistributedVectorAccountNoPointerStorage : public AccountStorageBase
{
public:
	void AddAccount(string id);
	Account* GetAccount(string id);
private:
	vector<Account> accounts[10];
};

class FileAccountStorage : public AccountStorageBase
{
public:
	void AddAccount(string id);
	Account* GetAccount(string id);
private:
};







