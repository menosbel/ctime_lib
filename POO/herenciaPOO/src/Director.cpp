#include<iostream>;
using namespace std;
#include<clocale>;
#include<Director.h>


void Director::cargar(){
    Empleado::cargar();
    cout << "Carrera: ";
    cin >> carrera;
}

void Director::mostrar(){
    Empleado::mostrar();
    cout << "Es director de la carrera " << carrera << endl;
}
