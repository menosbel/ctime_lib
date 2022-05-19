#include <iostream>
using namespace std;
#include "Examen.h"
#include "rlutil.h"

void Examen::setLegajoAlumno(int valor) { _legajoAlumno = valor; };

void Examen::setCodMateria(int valor) { _codMateria = valor; };

bool Examen::setCalificacion(float valor) { 
	if (valor >= 1 && valor <= 10) {
		_calificacion = valor;
		return true;
	}
	else {
		cout << "La calificacion ingresada es invalida" << endl;
		rlutil::anykey();
		return false;
	}
};

bool Examen::setTipoExamen(char valor) { 
	if (toupper(valor) != 'P' || toupper(valor) != 'F')
	{
		cout << valor << endl;
		cout << "El tipo de examen ingresado es invalido" << endl;
		rlutil::anykey();
		return false;
	}
	else {
		_tipoExamen = valor;
		return true;
	}	
};

void Examen::cargar()
{
	int legajo, codMateria, dia, mes, anio;
	float calificacion;
	char tipoExamen;

	cout << "Dia del examen: ";
	cin >> dia;
	cout << "Mes del examen: ";
	cin >> mes;
	cout << "Año del examen: ";
	cin >> anio;
	_fecha = Fecha(dia, mes, anio);
	cout << "Legajo alumno: ";
	cin >> legajo;
	setLegajoAlumno(legajo);
	cout << "Codigo materia: ";
	cin >> codMateria;
	setCodMateria(codMateria);
	
	bool fallo = false;
	while (!fallo) {
		cout << "Calificaion (1 al 10): ";
		cin >> calificacion;
		fallo = setCalificacion(calificacion);
	}
	
	fallo = false;
	while (!fallo) {
		cout << "Tipo de examen (P o F): ";
		cin >> tipoExamen;
		fallo = setTipoExamen(codMateria);
	}
}

void Examen::mostrar()
{
	cout << "Fecha: ";
	_fecha.mostrar();
	cout << "Legajo alumno: " << _legajoAlumno << endl;
	cout << "Codigo materia: " << _codMateria << endl;
	cout << "Calificacion: " << _calificacion << endl;
	cout << "Tipo de examen: " << _tipoExamen << endl;
}

bool Examen::guardar_en_disco()
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "examenes.dat", "ab");
	if (err != 0) { return false; }

	bool guardo = fwrite(this, sizeof(Examen), 1, p);
	fclose(p);

	return guardo;
}

bool Examen::leer_de_disco(int pos)
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "examenes.dat", "rb");
	if (err != 0) { return false; };
	fseek(p, pos * sizeof(Examen), SEEK_SET);
	bool ok = fread(this, sizeof(Examen), 1, p);
	fclose(p);
	return ok;
}
