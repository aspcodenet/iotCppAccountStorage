#include "pch.h"
#include "../IotSTLAccountPgm/VectorAccountStorage.h"
#include "../IotSTLAccountPgm/Bank.h"

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

TEST(BankTests, TransferShouldReturnErrorWhenFromAccountNoIsNotFound)
{
	Bank b(new VectorAccountStorage());
	b.AddAccount("222");
	auto ret = b.Transfer("111", "222", 100.0f);
	EXPECT_EQ(TRANSFER_ERROR::FromAccountNotFound, ret);
}

TEST(BankTests, TransferShouldReturnErrorWhenToaAccountNoIsNotFound)
{
	Bank b(new VectorAccountStorage());
	b.AddAccount("111");
	auto ret = b.Transfer("111", "222", 100.0f);
	EXPECT_EQ(TRANSFER_ERROR::ToAccountNotFound, ret);
}

TEST(BankTests, TransferShouldReturnErrorWhenQAmountIsNegative)
{
	Bank b(new VectorAccountStorage());
	b.AddAccount("111");
	b.AddAccount("222");
	auto ret = b.Transfer("111", "222", -100.0f);
	EXPECT_EQ(TRANSFER_ERROR::InvalidAmount, ret);
}

TEST(BankTests, TransferShouldReturnErrorWhenNotEnoughMoneyInFromAmount)
{
	Bank b(new VectorAccountStorage());
	b.AddAccount("111");
	b.GetAccount("111")->Deposit(100);
	b.AddAccount("222");
	auto ret = b.Transfer("111", "222", 110.0f);
	EXPECT_EQ(TRANSFER_ERROR::NotEnoughMoney, ret);
}

TEST(BankTests, TransferShouldWithdrawCorrectAmountInFromAccount)
{
	Bank b(new VectorAccountStorage());
	b.AddAccount("111");
	b.GetAccount("111")->Deposit(100);
	b.AddAccount("222");
	auto ret = b.Transfer("111", "222", 10.0f);
	EXPECT_EQ(90.0f, b.GetAccount("111")->GetBalance());
}


TEST(BankTests, TransferShouldDepositCorrectAmountInToAccount)
{
	Bank b(new VectorAccountStorage());
	b.AddAccount("111");
	b.GetAccount("111")->Deposit(100);
	b.AddAccount("222");
	b.GetAccount("222")->Deposit(20);
	auto ret = b.Transfer("111", "222", 10.0f);
	EXPECT_EQ(30.0f, b.GetAccount("222")->GetBalance());
}








