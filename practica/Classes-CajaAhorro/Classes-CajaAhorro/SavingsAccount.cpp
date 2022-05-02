#include "SavingsAccount.h"
#include <iostream>
#include <cstring>

using namespace std;

SavingsAccount::SavingsAccount(){};

SavingsAccount::SavingsAccount(int accountNumber) {
	_accountNumber = accountNumber;
	_balance = 0;
	_isEmpty = false;
};

SavingsAccount::SavingsAccount(int accountNumber, float balance) {
	_accountNumber = accountNumber;
	_isEmpty = false;

	if (!validateBalance(balance)) _balance = balance;
};

bool SavingsAccount::validateBalance(float value) {
	cout << "Validando..." << endl;

	if (_balance + value > 0 && (_balance - value > 0)) {
		return true;
	}
	else {
		cout << "El saldo no puede ser menor a cero" << endl;
		return false;
	}
}

void SavingsAccount::load() {
	cout << "Nombre: ";
	cin >> _name;
	cout << "Apellido: ";
	cin >> _lastName;
	cout << "Numero de cuenta: ";
	cin >> _accountNumber;
	cout << "Saldo: ";
	cin >> _balance;
	_isEmpty = false;
}

void SavingsAccount::show() {
	cout << "Nombre: " << _name << endl;
	cout << "Apellido: " << _lastName << endl;
	cout << "Numero de cuenta: " << _accountNumber << endl;
	cout << "Saldo: " << _balance << endl << endl;
}

bool SavingsAccount::isEmpty() {
	return _isEmpty;
}

bool SavingsAccount::isEqualTo(SavingsAccount &account)
{
	return account.accountNumberIsEqualTo(_accountNumber);
}

void SavingsAccount::deposit(float amount) {
	if (validateBalance(amount)) {
		_balance += amount;
		cout << "Nuevo saldo: " << _balance << endl << endl;
	}
}

void SavingsAccount::withdraw(float amount) {
	if (validateBalance(amount)) {
		_balance -= amount;
		cout << "Nuevo saldo: " << _balance << endl << endl;
	}
}

bool SavingsAccount::accountNumberIsEqualTo(int accountNumber) {
	return  _accountNumber == accountNumber;
}
