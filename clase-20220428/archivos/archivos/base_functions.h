#pragma once
#include <string>
#include "Estudiante.h"
#include "Examen.h"

std::string ZeroPadNumber(int num);

// Declaraciones de funciones globales
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