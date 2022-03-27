#include<iostream>;
using namespace std;
#include<clocale>;
#include <ctime>;
#include "Hora.h"

Hora::Hora(int hora, int minuto){
    _hora = hora;
    _minuto = minuto;
}
Hora::Hora(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _hora = f->tm_hour;
    _minuto = f->tm_min;
}

int Hora::getHora(){
    return _hora;
}
int Hora::getMinuto(){
    return _minuto;
}
void Hora::setHora(int hora){
    _hora = hora;
}
void Hora::setMinuto(int minuto){
    _minuto = minuto;
}
void Hora::mostrar(){
    if(_hora < 10){
        cout << "0";
    }
    cout << _hora << ":";
    if (_minuto < 10){
        cout << "0";
    }
    cout << _minuto << endl;
}
