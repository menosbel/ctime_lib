#include <iostream> // cin cout
using namespace std;

#include "funciones.h"

int main() {
    int dia, pais;
    float rec;

    // punto A
    float matRec[3][31]{};

    cout << "Ingrese pais: ";
    cin >> pais;

    while (pais != -1) {
        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese recaudacion: ";
        cin >> rec;

        matRec[pais - 1][dia - 1] += rec;

        cout << "Ingrese pais: ";
        cin >> pais;
    }

    mostrar_recaudacion(matRec);
    mostrar_cantidad_dias(matRec);
    mostrar_nro_dias(matRec);

    return 0;
}

