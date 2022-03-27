#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"

class Alumno:public Persona
{
    public:
        void cargar();
        void mostrar();
        void setLegajo(int l){legajo=l;}
        int getLegajo(){return legajo;}

    private:
        int legajo;
        float promedio;
};

#endif // ALUMNO_H
