#include <iostream>
#include <cstdlib>
#include "Persona.h"
#include "Empleado.h"
#include "Director.h"
#include "Profesor.h"
#include "Alumno.h"


using namespace std;

int main()
{
    system("cls");
    /*
    Persona p;
    Empleado e;
    p.cargar();
    p.mostrar();
    cout << endl << endl;
    e.cargar();
    e.mostrar();
    cout << endl << endl;
    */

    Director d;
    Profesor pr;
    Alumno a;
    pr.cargar();
    pr.mostrar();
    cout << endl << endl;
    d.cargar();
    d.mostrar();
    cout << endl << endl;
    a.cargar();
    a.mostrar();
    a.setApellido("fernandez");
    a.mostrar();
    cout << endl << endl;

    return 0;
}
