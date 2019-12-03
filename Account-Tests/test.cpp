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


TEST(AccountTests, DepositShouldIncreaseBalance)
{
	Account acc;
	acc.Deposit(100.0f);
	acc.Deposit(200.0f);
	EXPECT_EQ(300.0f, acc.GetBalance());
}


TEST(AccountTests, WithdrawalShouldDecreaseBalance)
{
	Account acc;
	acc.Deposit(100.0f);
	acc.Withdraw(70.0f);
	EXPECT_EQ(30.0f, acc.GetBalance());
}

TEST(AccountTests, DepositShouldReturnOkWhenAmountIsPositive)
{
	Account acc;
	auto ret = acc.Deposit(100.0f);
	EXPECT_EQ(ACCOUNT_ERRORS::Ok, ret);
}

TEST(AccountTests, WithdrawalShouldReturnOkWhenAmountIsPositive)
{
	Account acc;
	acc.Deposit(1000.0f);
	auto ret = acc.Withdraw(100.0f);
	EXPECT_EQ(ACCOUNT_ERRORS::Ok, ret);
}



TEST(AccountTests, DepositShouldReturnErrorWhenAmountIsNegative)
{
	Account acc;
	auto ret = acc.Deposit(-100.0f);
	EXPECT_EQ(ACCOUNT_ERRORS::InvalidAmount, ret);
}

TEST(AccountTests, DepositShouldNotModifyBalanceWhenIsNegative)
{
	Account acc;
	acc.Deposit(5000.0f);
	auto ret = acc.Deposit(-100.0f);
	EXPECT_EQ(5000.0f, acc.GetBalance());
}


TEST(AccountTests, WithdrawShouldReturnErrorWhenAmountIsNegative)
{
	Account acc;
	auto ret = acc.Withdraw(-100.0f);
	EXPECT_EQ(ACCOUNT_ERRORS::InvalidAmount, ret);
}


TEST(AccountTests, WithdrawShouldReturnErrorWhenAmountIsLargerThanBalance)
{
	Account acc;
	acc.Deposit(50.0f);
	auto ret = acc.Withdraw(100.0f);
	EXPECT_EQ(ACCOUNT_ERRORS::NotEnoughMoney, ret);
}

TEST(AccountTests, WithdrawShouldNotModifyBalanceWhenAmountIsLargerThanBalance)
{
	Account acc;
	acc.Deposit(50.0f);
	auto ret = acc.Withdraw(100.0f);
	EXPECT_EQ(50.0f, acc.GetBalance());
}




