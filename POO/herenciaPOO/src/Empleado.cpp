#include<iostream>;
using namespace std;
#include<clocale>;
#include "Empleado.h"

void Empleado::cargar(){
    Persona::cargar();
    cout << "Antiguedad: ";
    cin >> antiguedad;
    cout << "Sueldo: $";
    cin >> sueldo;
}

void Empleado:: mostrar(){
    Persona::mostrar();
    cout << "Tiene una antiguedad de " << antiguedad << " y un sueldo de $" << sueldo << endl;
}
