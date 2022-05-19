#include <iostream>
#include "Estudiante.h"
#include "base_functions.h"
#include "rlutil.h"

using namespace std;

int main()
{
    int opcion;
    char confirmarSalida;
    while (true) {
        rlutil::cls();
        rlutil::setColor(rlutil::WHITE);
        cout << "Menu estudiantes" << endl;
        cout << "-------------------------------" << endl;
        cout << "1 - Cargar nuevo estudiante" << endl;
        cout << "2 - Editar estudiante" << endl;
        cout << "3 - Listar todos los estudiantes" << endl;
        cout << "4 - Listar estudiante por legajo" << endl;
        cout << "5 - Eliminar estudiante" << endl;
        cout << "6 - Cargar examen" << endl;
        cout << "7 - Modificar examen" << endl;
        cout << "8 - Eliminar examen" << endl;
        cout << "9 - Listar examenes" << endl;
        cout << "10 - Buscar examen" << endl;
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
        case 6:
            if (nuevo_examen()) mostrar_mensaje("Examen registrado correctamente");
            else mostrar_mensaje("No se pudo guardar el examen", 15, 4);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9: 
            listar_examenes();
            break;
        case 10:
            break;
        case 0:
            cout << "Confirma salir? (S/N): ";
            cin >> confirmarSalida;
            if (tolower(confirmarSalida) == 's') {
                return 0;
            }
            break;
        }
        rlutil::anykey();
    }
    return 0;
}

