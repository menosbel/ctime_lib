#include<iostream>;
using namespace std;
#include<clocale>;
#include<Empleado.h>
#include<Profesor.h>

void Profesor::cargar(){
    Empleado::cargar();
    cout << "Titulo: ";
    cin >> titulo;
}

void Profesor::mostrar(){
    Empleado::mostrar();
    cout << "Tiene el titulo de " << titulo << endl;
}
