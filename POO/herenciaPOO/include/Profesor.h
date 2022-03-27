#ifndef PROFESOR_H
#define PROFESOR_H
#include "Empleado.h"

class Profesor:public Empleado
{
    public:
        void cargar();
        void mostrar();

    private:
        char titulo[50];
};

#endif // PROFESOR_H
