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
        cout << "Menu general" << endl;
        cout << "-------------------------------" << endl;
        cout << "1 - Menu estudiantes" << endl;
        cout << "2 - Menu examenes" << endl;
        cout << "3 - Menu informes" << endl;
        cout << "-------------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;
       
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            render_menu_estudiantes();
            break;
        case 2:
            render_menu_examenes();
            break;
        case 3:
            render_menu_informes();
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

