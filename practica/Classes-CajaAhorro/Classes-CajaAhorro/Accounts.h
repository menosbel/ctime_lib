#pragma once
#include "SavingsAccount.h"

class Accounts
{
private:
	SavingsAccount _accounts[10] = {};
public:
	void createNew();
	void showAll();
	void update(SavingsAccount account);
	void add(SavingsAccount account);
	SavingsAccount findByAccountNumber();
};

