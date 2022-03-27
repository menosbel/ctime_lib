#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Empleado.h"

class Director:public Empleado
{
    public:
        void cargar();
        void mostrar();

    private:
        char carrera[50];
};

#endif // DIRECTOR_H
