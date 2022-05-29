#pragma once
#include "Fecha.h"

class Examen
{
private:
	int _id;
	Fecha _fecha;
	int _legajoAlumno;
	int _codMateria;
	float _calificacion;
	char _tipoExamen;
public:
	void setId(int valor) { _id = valor; };
	void setLegajoAlumno(int valor);
	void setCodMateria(int valor);
	bool setCalificacion(float valor);
	bool setTipoExamen(char valor);
	int getId() { return _id; };
	Fecha getFecha() { return _fecha; };
	int getLegajo() { return _legajoAlumno; };
	int getCodigoMateria() { return _codMateria; };
	float getCalificacion() { return _calificacion; };
	char getTipoExamen() { return _tipoExamen; };
	bool cargar();
	void mostrar();
	bool guardar_en_disco();
	bool guardar_en_disco(int pos);
	bool leer_de_disco(int pos);
};

