#pragma once
class SavingsAccount
{
private:
	char _name[30] = "";
	char _lastName[30] = "";
	int _accountNumber;
	float _balance;
	bool _isEmpty = true;
public:
	SavingsAccount();
	SavingsAccount(int accountNumber);
	SavingsAccount(int accountNumber, float balance);
	bool validateBalance(float value);
	void load();
	void show();
	bool isEmpty();
	bool isEqualTo(SavingsAccount &account);
	void deposit(float amount);
	void withdraw(float amount);
	bool accountNumberIsEqualTo(int accountNumber);
};
