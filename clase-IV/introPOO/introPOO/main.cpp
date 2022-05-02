#include "CajaAhorro.h"
#include <iostream>

using namespace std;

int main() {
	CajaAhorro caja;

	caja.setApellido("Lopez");
	cout << caja.getApellido() << endl;

	return 0;
}