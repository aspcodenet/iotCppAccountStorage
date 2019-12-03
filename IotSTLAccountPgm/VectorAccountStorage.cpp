#include "VectorAccountStorage.h"
#include <fstream>

VectorAccountStorage::~VectorAccountStorage()
{
	for (int i = 0; i < accounts.size(); i++)
		delete accounts[i];
}

void VectorAccountStorage::AddAccount(std::string id)
{
	Account* account = new Account(id);
	/*Need som docuementation of course
	Here we add new account*/
	accounts.push_back(account);
	
}


void VectorAccountNoPointerStorage::PaxaMinne(int antal)
{
	accounts.reserve(antal);
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






void DistributedVectorAccountNoPointerStorage::AddAccount(std::string id)
{
	Account account = Account(id);
	int index = id[0] - '0';
	switch (index)
	{
	case 0:
		accounts0.push_back(account);
		break;
	case 1:
		accounts1.push_back(account);
		break;
	case 2:
		accounts2.push_back(account);
		break;
	case 3:
		accounts3.push_back(account);
		break;
	case 4:
		accounts4.push_back(account);
		break;
	case 5:
		accounts5.push_back(account);
		break;
	case 6:
		accounts6.push_back(account);
		break;
	case 7:
		accounts7.push_back(account);
		break;
	case 8:
		accounts8.push_back(account);
		break;
	case 9:
		accounts9.push_back(account);
		break;
	}
}

Account * DistributedVectorAccountNoPointerStorage::GetAccount(std::string id)
{
	int index = id[0] - '0';

	switch (index)
	{
	case 0:
		for (int i = 0; i < accounts0.size(); i++)
			if (accounts0[i].GetId() == id) return &accounts0[i];
		break;
	case 1:
		for (int i = 0; i < accounts1.size(); i++)
			if (accounts1[i].GetId() == id) return &accounts1[i];
		break;
	case 2:
		for (int i = 0; i < accounts2.size(); i++)
			if (accounts2[i].GetId() == id) return &accounts2[i];
		break;
	case 3:
		for (int i = 0; i < accounts3.size(); i++)
			if (accounts3[i].GetId() == id) return &accounts3[i];
		break;
	case 4:
		for (int i = 0; i < accounts4.size(); i++)
			if (accounts4[i].GetId() == id) return &accounts4[i];
		break;
	case 5:
		for (int i = 0; i < accounts5.size(); i++)
			if (accounts5[i].GetId() == id) return &accounts5[i];
		break;
	case 6:
		for (int i = 0; i < accounts6.size(); i++)
			if (accounts6[i].GetId() == id) return &accounts6[i];
		break;
	case 7:
		for (int i = 0; i < accounts7.size(); i++)
			if (accounts7[i].GetId() == id) return &accounts7[i];
		break;
	case 8:
		for (int i = 0; i < accounts8.size(); i++)
			if (accounts8[i].GetId() == id) return &accounts8[i];
		break;
	case 9:
		for (int i = 0; i < accounts9.size(); i++)
			if (accounts9[i].GetId() == id) return &accounts9[i];
		break;
	}
	return nullptr;
}


void MultiDistributedVectorAccountNoPointerStorage::AddAccount(std::string id)
{
	Account account = Account(id);
	int index = id[0] - '0';
	accounts[index].push_back(account);
}

Account *MultiDistributedVectorAccountNoPointerStorage::GetAccount(std::string id)
{
	Account account = Account(id);
	int index = id[0] - '0';
	for (int i = 0; i < accounts[index].size(); i++)
		if (accounts[index][i].GetId() == id) return &accounts[index][i];
	return nullptr;
}





void FileAccountStorage::AddAccount(std::string id)
{
	string fileName = "0" + to_string(id[0] - '0') + ".txt";

	std::ofstream outfile;
	outfile.open(fileName, std::ios_base::app); // append instead of overwrite
	outfile << id << endl;
}

Account* FileAccountStorage::GetAccount(std::string id)
{
	string fileName = "0" + to_string(id[0] - '0') + ".txt";

	std::ifstream infile(fileName);
	string line;
	while (infile >> line)
		if (line == id) return new Account(id);
	return nullptr;
}



