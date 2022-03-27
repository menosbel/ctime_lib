#include <iostream>
#include "funciones.h"

using namespace std;

void mostrar_recaudacion(float mat[3][31]) {
    cout << "Punto A)" << endl;
    for (int p = 0; p < 3; ++p) {
        for (int d = 0; d < 31; ++d) {
            if (mat[p][d] > 0) {
                cout << "Pais #" << p + 1 << " Dia #" << d + 1 << ": " << mat[p][d] << endl;
            }
        }
    }
}

void mostrar_cantidad_dias(float mat[3][31]) {
    cout << "Punto B)" << endl;
    for (int p = 0; p < 3; ++p) {
        int cant = 0;
        for (int d = 0; d < 31; ++d) {
            if (mat[p][d] == 0) {
                cant++;
            }
        }
        cout << "Pais #" << p + 1 << " cantidad de dias: " << cant << endl;
    }
}

void mostrar_nro_dias(float mat[3][31]) {
    cout << "Punto C)" << endl;
    for (int d = 0; d < 31; ++d) {
        bool recaudo = false;
        for (int p = 0; p < 3; ++p) {
            if (mat[p][d] != 0) {
                recaudo = true;
            }
        }
        if (!recaudo) {
            cout << "Dia #" << d + 1 << " no hubo recaudacion" << endl;
        }
    }
}
