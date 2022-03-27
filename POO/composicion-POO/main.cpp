/*Reunion con 5 personas. Reunion mas extensa. Cuantas personas por reunion*/

#include <iostream>
#include "Fecha.h"
#include "Hora.h"
#include "Reunion.h"


using namespace std;

int main()
{
    Fecha f(2, 9, 2022);
    Hora h(12, 50);

    Reunion r(2, 9, 2021, 19, 0, "zoom", "punteros", 120);
    r.mostrar();



    /*
    Fecha f1;
    f.mostrar();
    f1.mostrar();

    Hora h1;
    h.mostrar();
    h1.mostrar();
    */


     /*
     r.setTema("Clase de Laboratorio");
     r.setFecha(f);
     r.setHorario(h);
     r.setDuracion(240);
     r.setLugar("Zoom");
     r.mostrar();
    */

    if(r.getFecha().getAnio() == 2022){
        cout << "Esta reunion se realizara el proximo anio";
    }

    return 0;
}
