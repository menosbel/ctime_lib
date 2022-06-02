#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#include "rlutil.h"
#include "base_functions.h"
#include "reportes.h"

std::string ZeroPadNumber(int num)
{
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << num;
    return ss.str();
};

std::string parseDayOfWeek(int numDay) {
    switch (numDay) {
    case 0:
        return "Domingo";
    case 1:
        return "Lunes";
    case 2:
        return "Martes";
    case 3:
        return "Miercoles";
    case 4:
        return "Jueves";
    case 5:
        return "Viernes";
    case 6:
        return "Sabado";
    default:
        return "Dia inexistente";
    }
}

// Funciones globales para gestionar estudiante

bool render_menu_estudiantes()
{
    int opcion;
    
    while (true)
    {
        rlutil::cls();
        cout << "Menu estudiantes" << endl;
        cout << "-------------------------------" << endl;
        cout << "1 - Cargar nuevo estudiante" << endl;
        cout << "2 - Editar estudiante" << endl;
        cout << "3 - Listar todos los estudiantes" << endl;
        cout << "4 - Listar estudiante por legajo" << endl;
        cout << "5 - Eliminar estudiante" << endl;
        cout << "-------------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        rlutil::cls();

        switch (opcion) {
        case 1:
            if (nuevo_estudiante()) mostrar_mensaje("Estudiante registrado correctamente");
            else mostrar_mensaje("No se pudo guardar el estudiante", 15, 4);
            break;
        case 2:
            if (editar_estudiante()) mostrar_mensaje("Estudiante registrado correctamente");
            else mostrar_mensaje("No se pudo guardar el estudiante", 15, 4);
            break;
        case 3:
            listar_estudiantes();
            break;
        case 4:
            listar_estudiante_x_legajo();
            break;
        case 5:
            break;
        case 0:
            return 0;
            break;
        }
        rlutil::anykey();
    }    
};

bool render_menu_examenes()
{
    int opcion;

    while (true)
    {
        rlutil::cls();
        cout << "Menu estudiantes" << endl;
        cout << "-------------------------------" << endl;
        cout << "1 - Cargar examen" << endl;
        cout << "2 - Modificar examen" << endl;
        cout << "3 - Eliminar examen" << endl;
        cout << "4 - Listar examenes" << endl;
        cout << "5 - Buscar examen" << endl;
        cout << "6 - Buscar mejor nota" << endl;
        cout << "-------------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        rlutil::cls();

        switch (opcion) {
        case 1:
            if (nuevo_examen()) mostrar_mensaje("Examen registrado correctamente");
            else mostrar_mensaje("No se pudo guardar el examen", 15, 4);
            break;
        case 2:
            editar_examen();
            break;
        case 3:
            break;
        case 4:
            listar_examenes();
            break;
        case 5:
            nueva_busqueda_examen();
            break;
        case 6:
            buscar_mejor_nota();
            break;
        case 0:
            return 0;
            break;
        }
        rlutil::anykey();
    }
}

bool render_menu_informes()
{
    int opcion;

    while (true)
    {
        rlutil::cls();
        cout << "Menu informes" << endl;
        cout << "-------------------------------" << endl;
        cout << "1 - Reporte 1" << endl;
        cout << "2 - Reporte 2" << endl;
        cout << "3 - Reporte 3" << endl;
        cout << "-------------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        rlutil::cls();

        switch (opcion) {
        case 1:
            reporte_1();
            break;
        case 2:
            reporte_2();
            break;
        case 3:
            reporte_3();
            break;
        case 0:
            return 0;
            break;
        }
        rlutil::anykey();
    }
};

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

void listar_estudiantes_ordenado_apellido()
{
    int cantEstudiantes = cantidad_registros_estudiantes();
    Estudiante *estudiantes = new Estudiante[cantEstudiantes];
    Estudiante aux;

    cout << "LISTADO DE ESTUDIANTES" << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < cantEstudiantes; i++)
    {
        estudiantes[i].leer_de_disco(i);
    }

    for (int i = 0; i < cantEstudiantes - 1; i++)
    {
        for (int j = i + 1; j < cantEstudiantes; j++)
        {
            if (estudiantes[i].getApellidos() > estudiantes[j].getApellidos())
            {
                aux = estudiantes[i];
                estudiantes[i] = estudiantes[j];
                estudiantes[j] = aux;
            }
        }
    }

    for (int i = 0; i < cantEstudiantes; i++)
    {
        estudiantes[i].leer_de_disco(i);
        aux.mostrar();
        cout << endl;
    }

    cout << "----------------------------" << endl;
    cout << "Total: " << cantEstudiantes;

    delete estudiantes;
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
    if (!reg.cargar()) return false;
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

void buscar_mejor_nota() {
    int codMateria, legajo;
    cout << "Codigo materia: ";
    cin >> codMateria;
    cout << "Legajo estudiante: ";
    cin >> legajo;
    cout << endl << endl;
    float maxNota;
    maxNota = max_nota(codMateria, legajo);
    cout << "La mejor nota en un examen parcial del alumno con legajo " << legajo << " en la materia con codigo " << codMateria << " fue de " << maxNota << endl;
}

float max_nota(int codMateria, int legajo)
{
    int pos = 0;
    float maxNota = 0;
    Examen examen;
    while (examen.leer_de_disco(pos++))
    {
        if (examen.getLegajo() == legajo && examen.getCodigoMateria() == codMateria && examen.getTipoExamen() == 'P')
        {
            if (examen.getCalificacion() > maxNota)
            {
                maxNota = examen.getCalificacion();
            }
        }
    }
    if (maxNota == 0) { return -1; };
    return maxNota;
}

bool examen_es_unico(Examen examen)
{
    Examen aux;
    int pos = 0;
    while (aux.leer_de_disco(pos++))
    {
        if (aux.getFecha().equals(examen.getFecha()) && aux.getCodigoMateria() == examen.getCodigoMateria() && aux.getLegajo() == examen.getLegajo())
        {
            return false;
            break;
        }
    }
    return true;
}

bool editar_examen() {
    int codMateria, legajo, pos;
    Fecha fecha;
    float calificacion;
    bool ok = false;
    
    cout << "Codigo materia: ";
    cin >> codMateria;
    cout << "Legajo: ";
    cin >> legajo;
    fecha.cargar();

    pos = buscar_examen(fecha, codMateria, legajo);
    if (pos >= 0) {
        Examen reg;
        reg.leer_de_disco(pos);
        cout << endl;
        reg.mostrar();
        cout << endl << endl;
        cout << "Calificacion nueva: ";
        cin >> calificacion;
        reg.setCalificacion(calificacion);
        ok = reg.guardar_en_disco(pos);
    }
    return ok;
}

void nueva_busqueda_examen()
{
    int codMateria, legajo;
    Fecha fecha;
    int pos = -1;
    cout << "Codigo materia: ";
    cin >> codMateria;
    cout << "Legajo: ";
    cin >> legajo;
    fecha.cargar();
    pos = buscar_examen(fecha, codMateria, legajo);
    
    if (pos != -1) {
        Examen examen;
        examen.leer_de_disco(pos);
        cout << endl;
        examen.mostrar();
    }
}

int buscar_examen(Fecha fecha, int codMateria, int legajo) {
    Examen aux;
    int cantExamenes = cantidad_registros_examenes();

    for (int i = 0; i < cantExamenes; i++)
    {
        aux.leer_de_disco(i);
        if (aux.getFecha().equals(fecha) && aux.getCodigoMateria() == codMateria && aux.getLegajo() == legajo) {
            return i;
        }
    }
    mostrar_mensaje("El examen soliciotado no existe", 15, 4);
    return -1;
};
