#include "Estudiante.h"
#include <iostream>

using namespace std;

void Estudiante::cargar()
{
	cout << "Legajo: ";
	cin >> _legajo;
	cout << "Nombre: ";
	cin >> _nombres;
	cout << "Apellido: ";
	cin >> _apellidos;
	_fnac.cargar();
}

void Estudiante::mostrar()
{
	cout << "Legajo: " << _legajo << endl;
	cout << "Nombre: " << _nombres << endl;
	cout << "Apellido: " << _apellidos << endl;
	cout << "Fecha de nacimiento: ";
	_fnac.mostrar();
}

bool Estudiante::leer_de_disco(int pos)
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "estudiantes.dat", "rb");
	if (err != 0) { return false; };
	fseek(p, pos * sizeof(Estudiante), SEEK_SET);
	bool ok = fread(this, sizeof(Estudiante),1, p);
	fclose(p);
	return ok;
}

bool Estudiante::guardar_en_disco()
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "estudiantes.dat", "ab");
	if (err != 0) { return false; }

	bool guardo = fwrite(this, sizeof(Estudiante), 1, p);
	fclose(p);

	return guardo;
}

bool Estudiante::guardar_en_disco(int pos)
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "estudiantes.dat", "rb+");
	if (err != 0) { return false; }
	fseek(p, pos * sizeof(Estudiante), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Estudiante), 1, p);
	fclose(p);

	return guardo;
}
