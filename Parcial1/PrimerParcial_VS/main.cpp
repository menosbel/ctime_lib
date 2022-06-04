#include <iostream>
#include "Viaje.h"
#include "Chofer.h"
#include "Parcial.h"
using namespace std;

int main()
{
	Parcial parcial;
	cout << "PUNTO 1" << endl << endl;
	parcial.Punto1();
	cout << endl << endl;

	cout << "PUNTO 2" << endl << endl;
	parcial.Punto2();
	cout << endl << endl;

	cout << "PUNTO 3" << endl << endl;
	parcial.Punto3();
	cout << endl << endl;

	cout << "PUNTO 4" << endl << endl;
	parcial.Punto4();
	cout << endl << endl;

	return 0;
	Viaje viaje;
	int pos = 0;
	while (viaje.LeerDeDisco(pos++))
	{
		cout << viaje.toString() << endl;
	}
	return 0;
}

