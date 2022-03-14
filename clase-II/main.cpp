#include <iostream>
using namespace std;


/*
 * Asignacion dinamica de memoria para ubicar info en memoria heap
 * Se usan punteros.
 *
 * TAMANO DE UNA ARRAY NO PUEDE SER UNA VARIABLE
 * Solo con memoria dinamica
 * En modo estricto no compila
 */
int main() {
    float *vec = nullptr; // vector que no apunta a ningun lado
    const int TAM = 5000000;

    vec = new float[TAM]; // con new se pide memoria heap

    if (vec != nullptr) {
        for (int i = 0; i < TAM; ++i) {
            vec[i] = 0;
        }
    }
    cout << vec[TAM - 1] << endl;
    delete vec;

    // OTRO EJEMPLO
    int *vec2, n;
    cin >> n;
    vec2 = new int[n]; // n es la cantidad de elementos
    if(vec2 == nullptr) return 1; // no hay memoria
    delete vec2;

    cout << "Chau";
    return 0;
}
