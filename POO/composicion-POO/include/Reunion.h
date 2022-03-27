#ifndef REUNION_H
#define REUNION_H
#include "Fecha.h"
#include "Hora.h"

using namespace std;


class Reunion
{
    public:
        Reunion();
        Reunion(Fecha fecha, Hora horario, int duracion);
        Reunion(Fecha fecha, Hora horario, int duracion, string tema, string lugar);
        Reunion(int dia, int mes, int anio, int hora, int minuto, string lugar, string tema, int duracion);

        Fecha getFecha();
        Hora getHorario();
        int getDuracion();
        string getTema();
        string getLugar();

        void setFecha(Fecha fecha);
        void setHorario(Hora horario);
        void setDuracion(int duracion);
        void setTema(string tema);
        void setLugar(string lugar);

        void cargar();
        void mostrar();

    private:
        Fecha _fecha;
        Hora _horario;
        string _lugar;
        string _tema;
        int _duracion;
};

#endif // REUNION_H
