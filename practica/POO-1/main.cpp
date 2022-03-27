#include <iostream>
#include <cstring>


using namespace std;
    class Materia {
        private:
            int nroMateria;
            char nombreMateria[40];
            int cantAlumnos;
        public:
            Materia(int nm=0, const char *nombre="nada", int ca=0){
                nroMateria=nm;
                strcpy(nombreMateria, nombre);
                cantAlumnos=ca;
            }

            Materia(const char *nombreMateria){
                strcpy(this->nombreMateria, nombreMateria);
                nroMateria = 0;
                cantAlumnos = 0;
            }

            ~Materia(){
                cout << "Hago cosas cuando el objeto deja de existir" << endl;
            }

            void mostrar(){
                cout << "Numero materia:" << nroMateria << endl;
                cout << "Nombre materia:" << nombreMateria << endl;
            }

            void mostrarDireccion(){
                cout << this << endl;
            }
    };

int main()
{
    Materia materia, mat[5], *puntero, conNombre("Programacion 2");
    puntero = &materia; // guarda direccion de objeto de la misma clase
    puntero -> mostrar();
    cout << endl;
    (*puntero).mostrar();
    cout << endl;
    cout << "Valor de puntero: " << puntero << endl;
    cout << "Direccion memoria: ";
    materia.mostrarDireccion();
    cout << endl;
    conNombre.mostrar();
    cout << endl << endl;
    return 0;
}
