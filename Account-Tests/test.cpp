#include "pch.h"
#include "../IotSTLAccountPgm/VectorAccountStorage.h"

TEST(VectorAccountStorageTests, GetAccountShouldReturnNullIfAccountIsNotFound) 
{
	VectorAccountStorage storage;
	storage.AddAccount("12345");
	Account* acc = storage.GetAccount("AAAAA");
	EXPECT_EQ(nullptr, acc);
}

TEST(VectorAccountStorageTests, GetAccountShouldReturnAccountIfAccountIsFound)
{
	VectorAccountStorage storage;
	storage.AddAccount("12345");
	Account* acc = storage.GetAccount("12345");
	EXPECT_EQ("12345", acc->GetId());
}