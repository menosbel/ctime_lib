#include "SavingsAccount.h"
#include "Accounts.h"
#include <iostream>
using namespace std;

int loadMenu() {
	int option;
	cout << "1 -  Cargar datos" << endl;
	cout << "2 -  Buscar por numero de cuenta" << endl;
	cout << "3 -  Depositar" << endl;
	cout << "4 -  Extraer" << endl;
	cout << "5 -  Crear cuenta con numero de cuenta y saldo cero" << endl;
	cout << "6 -  Crear cuenta con numero de cuenta y saldo" << endl;
	cout << "0 -  Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> option;
	cout << endl;

	return option;
}

void executeSelected(int option, Accounts &accounts) {
	SavingsAccount account;
	int amount, accountNumber;
	float balance;

	switch (option)
	{
	case 1:
		accounts.createNew();
		system("pause");
		system("cls");
		break;
	case 2:
		account = accounts.findByAccountNumber();
		account.show();
		system("pause");
		system("cls");
		break;
	case 3:
		account = accounts.findByAccountNumber();
		cout << "Monto a depositar: $ ";
		cin >> amount;
		account.deposit(amount);
		accounts.update(account);
		system("pause");
		system("cls");
		break;
	case 4:
		account = accounts.findByAccountNumber();
		cout << "Monto a extraer: $ ";
		cin >> amount;
		account.withdraw(amount);
		accounts.update(account);
		system("pause");
		system("cls");
		break;
	case 5:
		cout << "Ingrese un numero de cuenta: ";
		cin >> accountNumber;
		account = SavingsAccount(accountNumber);
		accounts.add(account);
		cout << "Cuenta creadacon exito" << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	case 6:
		cout << "Ingrese un numero de cuenta: ";
		cin >> accountNumber;
		cout << "Ingrese el saldo: ";
		cin >> balance;
		account = SavingsAccount(accountNumber, balance);
		accounts.add(account);
		cout << endl;
		cout << "Cuenta creada" << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	default:
		system("pause");
		system("cls");
		break;
	};
}


int main()
{
	int option = 1;
	Accounts accounts;

	while (option != 0)
	{
		option = loadMenu();
		executeSelected(option, accounts);
	}

	return 0;
}
