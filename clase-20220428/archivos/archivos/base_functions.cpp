#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#include "rlutil.h"
#include "base_functions.h"

std::string ZeroPadNumber(int num)
{
	std::ostringstream ss;
	ss << std::setw(2) << std::setfill('0') << num;
	return ss.str();
}

// Funciones globales para gestionar estudiante
void listar_estudiantes()
{
    Estudiante aux;
    int cantEstudiantes = cantidad_registros_estudiantes();

    cout << "LISTADO DE ESTUDIANTES" << endl;
    cout << "----------------------------" << endl;

    for(int i = 0; i < cantEstudiantes; i++)
    {
        aux.leer_de_disco(i);
        aux.mostrar();
        cout << endl;
    }
    cout << "----------------------------" << endl;
    cout << "Total: " << cantEstudiantes;
}

int cantidad_registros_estudiantes() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, "estudiantes.dat", "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Estudiante);
    return cant_reg;

}

bool nuevo_estudiante() {
    Estudiante reg;
    reg.cargar();
    bool ok = reg.guardar_en_disco();
    return ok;
}

void mostrar_mensaje(string mensaje, int color, int colorFondo, int x, int y) {
    rlutil::locate(x, y);
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    cout << mensaje << endl;
    rlutil::setBackgroundColor(0);
};

void listar_estudiante_x_legajo()
{
    int legajo, pos;
    cout << "Legajo: ";
    cin >> legajo;

    pos = buscar_estudiante(legajo);
    if (pos >= 0) {
        Estudiante reg;
        reg.leer_de_disco(pos);
        cout << endl;
        reg.mostrar();
    }
    else {
        cout << endl << "No existe el estudiante" << endl;
    }
}

bool editar_estudiante() {
    int legajo, pos;
    string apellidoNuevo;
    bool ok = false;
    cout << "Legajo: ";
    cin >> legajo;

    pos = buscar_estudiante(legajo);
    if (pos >= 0) {
        Estudiante reg;
        reg.leer_de_disco(pos);
        cout << endl;
        reg.mostrar();
        cout << endl << endl;
        cout << "Apellido nuevo: ";
        cin >> apellidoNuevo;
        reg.setApellidos(apellidoNuevo);
        ok = reg.guardar_en_disco(pos);
    }
    return ok;
}

int buscar_estudiante(int legajo) {
    Estudiante aux;
    int cantEstudiantes = cantidad_registros_estudiantes();

    for (int i = 0; i < cantEstudiantes; i++)
    {
        aux.leer_de_disco(i);
        if (aux.getLegajo() == legajo) {
            return i;
        }
    }
    return -1;
};

bool nuevo_examen()
{
    Examen reg;
    reg.cargar();
    bool ok = reg.guardar_en_disco();
    return ok;
}

void listar_examenes()
{
    Examen aux;
    int cantExamenes = cantidad_registros_examenes();

    cout << "LISTADO DE EXAMENES" << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < cantExamenes; i++)
    {
        aux.leer_de_disco(i);
        aux.mostrar();
        cout << endl;
    }
    cout << "----------------------------" << endl;
    cout << "Total: " << cantExamenes;
}

int cantidad_registros_examenes() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, "examenes.dat", "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Examen);
    return cant_reg;
}
