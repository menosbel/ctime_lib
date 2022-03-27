#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"

class Empleado:public Persona
{
    public:
        void cargar();
        void mostrar();

    private:
        int antiguedad;
        float sueldo;
};

#endif // EMPLEADO_H
