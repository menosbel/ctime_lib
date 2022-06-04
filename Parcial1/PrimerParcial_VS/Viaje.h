#pragma once
#include <string>
#include "FechaHora.h"

class Viaje
{
private:
  int _ID;
  int _IDChofer;
  int _DNI;
  float _Kms;
  int _IDFormaPago;
  FechaHora _FechaHora;
  int _Duracion;
  int _Importe;
  bool _Cancelado;
public:
    int getID();
    void setID(int ID);

    int getIDChofer();
    void setIDChofer(int IDChofer);

    int getDNI();
    void setDNI(int DNI);

    float getKms();
    void setKms(float Kms);

    int getIDFormaPago();
    void setIDFormaPago(int IDFormaPago);

    FechaHora getFechaHora();
    void setFechaHora(FechaHora FechaHora);

    int getDuracion();
    void setDuracion(int Duracion);

    int getImporte();
    void setImporte(int Importe);

    bool getCancelado();
    void setCancelado(bool Cancelado);

    std::string toString();

    bool LeerDeDisco(int nroRegistro);
    bool GuardarEnDisco();
    bool GuardarEnDisco(int nroRegistro);
};

int cantidad_registros_viajes();
int buscar_viaje(int id);
