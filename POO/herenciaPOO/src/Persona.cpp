#include<iostream>;
using namespace std;
#include<clocale>;
#include "Persona.h"

void Persona::cargar(){
    cout << "Apellido: ";
    cin >> apellido;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "DNI: ";
    cin >> dni;
}

void Persona::mostrar(){
    cout << apellido << " " << nombre << " tiene " << edad << " años. DNI: " << dni << endl;
}
