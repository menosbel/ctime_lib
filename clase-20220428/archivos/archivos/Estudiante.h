#pragma once
#include <cstring>
#include <iostream>
using namespace std;
#include "Fecha.h"

class Estudiante
{
private:
	int _legajo;
	char _apellidos[50];
	char _nombres[50];
	Fecha _fnac;
public:
	int getLegajo() { return _legajo; };
	void setApellidos(std::string valor) {
		strcpy_s(_apellidos, valor.c_str());
	}
	void cargar();
	void mostrar();
	bool leer_de_disco(int pos);
	bool guardar_en_disco();
	bool guardar_en_disco(int pos);
};
