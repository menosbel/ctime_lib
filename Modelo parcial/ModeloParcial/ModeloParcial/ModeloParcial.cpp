#include "ModeloParcial.h"
#include "Estudiante.h"
#include "Examen.h"
#include <iostream>
#include <iomanip>

using namespace std;

template<typename T> void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(' ') << t;
}

void ModeloParcial::punto1()
{
	int cantEstudiantes = cantidad_registros_estudiantes();
	int cantExamenes = cantidad_registros_examenes();
	int legajo;
	Estudiante estudiante;
	Examen examen;
	bool rindio;

	cout << "Alumnos que NO rindieron examenes en 2022" << endl;
	for (int i = 0; i < cantEstudiantes; i++)
	{
		rindio = false;
		estudiante.LeerDeDisco(i);
		legajo = estudiante.getLegajo();

		for (int y = 0; y < cantExamenes; y++)
		{
			examen.LeerDeDisco(y);
			
			if (examen.getFecha().getAnio() == 2022) {
				if (examen.getLegajo() == legajo)
				{
					rindio = true;
				}
			}
		}

		if (!rindio)
		{
			cout << legajo << "\t" << estudiante.getNombres() << "\t" << estudiante.getApellidos() << endl;
		}
	}
}

bool ModeloParcial::punto1_version2()
{
	int cantEstudiantes = cantidad_registros_estudiantes();
	Estudiante estudiante;
	int pos = 0;

	bool* vecEstudiantes = new bool[cantEstudiantes];
	if (vecEstudiantes == nullptr) { return false; };

	while (estudiante.LeerDeDisco(pos++))
	{

	}

};


void ModeloParcial::punto2()
{
	int cantidadEstudiantes = cantidad_registros_estudiantes();
	int cantExamenes = cantidad_registros_examenes();
	int cantAprob, cantDesaprob;
	Estudiante estudiante;
	Examen examen;

	printPunto2Header();

	for (int i = 0; i < cantidadEstudiantes; i++)
	{
		cantAprob = 0;
		cantDesaprob = 0;
		estudiante.LeerDeDisco(i);

		for (int y = 0; y < cantExamenes; y++)
		{
			examen.LeerDeDisco(y);
			if (examen.getLegajo() == estudiante.getLegajo())
			{
				if (examen.getNota() >= 6)
				{
					cantAprob++;
				}
				else
				{
					cantDesaprob++;
				}
			}
		}

		printElement(estudiante.getLegajo(), 20);
		printElement(estudiante.getApellidos(), 20);
		printElement(estudiante.getNombres(), 20);
		printElement(cantAprob, 20);
		printElement(cantDesaprob, 20);
		cout << endl;
	}
}

void ModeloParcial::punto3()
{
	int cantEstudiantes = cantidad_registros_estudiantes();
	int cantExamenes = cantidad_registros_examenes();
	int rindieronMasUnaVez = 0;

	Estudiante estudiante;
	Examen examen;

	for (int i = 0; i < cantEstudiantes; i++)
	{
		int vMaterias[60] = {};
		estudiante.LeerDeDisco(i);
		for (int y = 0; y < cantExamenes; y++)
		{
			examen.LeerDeDisco(y);
			if (estudiante.getLegajo() == examen.getLegajo()) 
			{
				if (examen.getFecha().getAnio() >= 2018 && examen.getFecha().getAnio() <= 2022)
				{
					vMaterias[examen.getIDMateria() - 1]++;
				}
			}
		}

		if (rindioMasDeUnaVezMismaMateria(vMaterias, 60))
		{
			rindieronMasUnaVez++;
			printElement(estudiante.getLegajo(), 20);
			printElement(estudiante.getApellidos(), 20);
			printElement(estudiante.getNombres(), 20);
			cout << endl;

		}
	}
	cout << endl;
	cout << "En total " << rindieronMasUnaVez << " estudiantes rindieron examen mas de una vez para la misma materia entre 2018 y 2022" << endl;
}

void ModeloParcial::printPunto2Header()
{
	const char separator = ' ';
	const int width = 20;

	cout << left << setw(width) << setfill(separator) << "Legajo";
	cout << left << setw(width) << setfill(separator) << "Apellidos";
	cout << left << setw(width) << setfill(separator) << "Nombres";
	cout << left << setw(width) << setfill(separator) << "CantAprob";
	cout << left << setw(width) << setfill(separator) << "CantDesaprob";
	cout << endl;
	cout << left << setw(110) << setfill('_') << "";
	cout << endl << endl;
}

bool ModeloParcial::rindioMasDeUnaVezMismaMateria(int* v, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if (v[i] > 1)
		{
			return true;
		}
	}
	return false;
}
