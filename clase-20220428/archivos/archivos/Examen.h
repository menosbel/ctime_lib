#pragma once
#include "Fecha.h"

class Examen
{
private:
	Fecha _fecha;
	int _legajoAlumno;
	int _codMateria;
	float _calificacion;
	char _tipoExamen;
public:
	void setLegajoAlumno(int valor);
	void setCodMateria(int valor);
	bool setCalificacion(float valor);
	bool setTipoExamen(char valor);
	void cargar();
	void mostrar();
	bool guardar_en_disco();
	bool leer_de_disco(int pos);
};

