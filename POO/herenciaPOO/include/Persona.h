#ifndef PERSONA_H
#define PERSONA_H
#include<cstring>


class Persona
{
    //protected mantiene encapsulamiento, pero permite que clases derivadas accedan
    public:
        void cargar();
        void mostrar();
        void setApellido(const char *a){strcpy(apellido, a);}

    protected:
        char apellido[50];
        char nombre[50];
        int edad;
        int dni;
};

#endif // PERSONA_H
