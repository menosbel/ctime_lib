#include "reportes.h"
#include "estudiante.h"
#include "Fecha.h"
#include "base_functions.h"
#include "examen.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "rlutil.h"
using namespace std;

int contar_examenes_desaprobados_anio(int legajo, int anio)
{
	int cant = 0;
	Examen reg;
	int cant_examenes = cantidad_registros_examenes();
	for (int i = 0; i < cant_examenes; i++)
	{
		reg.leer_de_disco(i);
		if (reg.getLegajo() == legajo && reg.getFecha().getAnio() == anio && reg.getCalificacion() >= 6)
		{
			cant++;
		}
	}
	return cant;
}

void reporte_1() 
{
	Estudiante reg;
	Fecha fecha;
	int cant_estudiantes = cantidad_registros_estudiantes();
	for (int i = 0; i < cant_estudiantes; i++)
	{
		reg.leer_de_disco(i);
		int cantExamenesAprobados = 0;
		cantExamenesAprobados = contar_examenes_desaprobados_anio(reg.getLegajo(), fecha.getAnio());
		if (cantExamenesAprobados < 2)
		{
			cout << reg.getLegajo() + ", " + reg.getApellidos() + ", " + reg.getNombres() << endl;

		}
	};
};

bool rindio_conscutivamente_cada_anio(int legajo, int desde, int hasta)
{
	int cantElementos = hasta - desde + 1;
	bool* vecAnios = new bool[cantElementos];
	if (vecAnios == nullptr) { return false; };

	for (int i = 0; i < cantElementos; i++)
	{
		vecAnios[i] = false;
	}

	Examen reg;
	int pos = 0;
	while(reg.leer_de_disco(pos++))
	{
		int anio = reg.getFecha().getAnio();
		if (reg.getLegajo() == legajo && anio >= desde && anio <= hasta)
		{
			vecAnios[anio - desde] = true;
		}
	}

	bool todosLosAniosEnTrue = true;
	for (int i = 0; i < cantElementos; i++)
	{
		if (vecAnios[i] == false)
		{
			todosLosAniosEnTrue = false;
		}
	}

	delete vecAnios;
	return todosLosAniosEnTrue;
}

void reporte_2() 
{
	Estudiante reg;
	Fecha fecha;
	int pos = 0;
	while (reg.leer_de_disco(pos++))
	{
		if (rindio_conscutivamente_cada_anio(reg.getLegajo(), 2015, fecha.getAnio()))
		{
			cout << reg.getLegajo() + ", " + reg.getApellidos() + ", " + reg.getNombres() << endl;
		}
	}
};

void reporte_3() {

};