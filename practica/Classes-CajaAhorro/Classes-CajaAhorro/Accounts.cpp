#include "Accounts.h"
#include <iostream>
#include <cstring>

using namespace std;

void Accounts::createNew() {
	int i;
	int arrSize = sizeof(_accounts) / sizeof(_accounts[0]);
		
	for (i = 0; i < arrSize; i++)
	{
		if (_accounts[i].isEmpty()) {
			_accounts[i].load();
			return;
		}
	}	
};

void Accounts::add(SavingsAccount account) {
	int i;
	int arrSize = sizeof(_accounts) / sizeof(_accounts[0]);

	for (i = 0; i < arrSize; i++)
	{
		if (_accounts[i].isEmpty()) {
			_accounts[i] = account;
			return;
		}
	}
};

void Accounts::showAll() {
	int i;
	int arrSize = sizeof(_accounts) / sizeof(_accounts[0]);

	for (i = 0; i < arrSize; i++)
	{
		_accounts[i].show();
		cout << endl;
	}
}

void Accounts::update(SavingsAccount account)
{
	int i;
	int arrSize = sizeof(_accounts) / sizeof(_accounts[0]);

	for (i = 0; i < arrSize; i++)
	{
		if (account.isEqualTo(_accounts[i]))
		{
			_accounts[i] = account;
		}
	}
}

SavingsAccount Accounts::findByAccountNumber() {
	int i, accountNumber;
	int arrSize = sizeof(_accounts) / sizeof(_accounts[0]);

	cout << "Numero de cuenta: ";
	cin >> accountNumber;

	for (i = 0; i < arrSize; i++)
	{
		if (_accounts[i].accountNumberIsEqualTo(accountNumber)) {
			return _accounts[i];
		}
	}
};
