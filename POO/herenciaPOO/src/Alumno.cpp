#include<iostream>;
using namespace std;
#include<clocale>;
#include "Alumno.h"

void Alumno::cargar(){
    Persona::cargar();
    cout << "Legajo: ";
    cin >> legajo;
    cout << "Promedio: ";
    cin >> promedio;
}

void Alumno::mostrar(){
    Persona::mostrar();
    cout << "Su legajo es " << legajo << " y tiene un promedio de " << promedio << endl;
}
