#pragma once
#include <string>
#include "Estudiante.h"
#include "Examen.h"

std::string ZeroPadNumber(int num);
std::string parseDayOfWeek(int numDay);

// Declaraciones de funciones globales

bool render_menu_estudiantes();
bool render_menu_examenes();
bool render_menu_informes();

void listar_estudiantes();
int cantidad_registros_estudiantes();
bool nuevo_estudiante();
void mostrar_mensaje(std::string mensaje, int color = 15, int colorFondo = 2, int x = 1, int y = 20);
void listar_estudiante_x_legajo();
bool editar_estudiante();
int buscar_estudiante(int legajo);

bool nuevo_examen();
void listar_examenes();
int cantidad_registros_examenes();
void buscar_mejor_nota();
float max_nota(int codMateria, int legajo);
bool examen_es_unico(Examen examen);
bool editar_examen();
void nueva_busqueda_examen();
int buscar_examen(Fecha fecha, int codMateria, int legajo);