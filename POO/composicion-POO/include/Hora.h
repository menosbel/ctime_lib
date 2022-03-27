#ifndef HORA_H
#define HORA_H

class Hora
{
    public:
        Hora(int hora, int minuto);
        Hora();
        int getHora();
        int getMinuto();
        void setHora(int hora);
        void setMinuto(int minuto);
        void mostrar();

    private:
        int _hora, _minuto;
};

#endif // HORA_H
