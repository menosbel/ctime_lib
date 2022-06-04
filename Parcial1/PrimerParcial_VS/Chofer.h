#pragma once
#include <string>

class Chofer
{
private:
  int _ID;
  char _Apellidos[50];
  char _Nombres[50];
  char _Patente[10];
  int _IDMarca;
  int _AnioPatentamiento;

public:
    int getID() ;
    void setID(int ID);

    const char* getApellidos() ;
    void setApellidos(const char *Apellidos);

    const char* getNombres() ;
    void setNombres(const char *Nombres);

    const char* getPatente() ;
    void setPatente(const char* Patente);

    int getIDMarca() ;
    void setIDMarca(int IDMarca);

    int getAnioPatentamiento() ;
    void setAnioPatentamiento(int AnioPatentamiento);

    std::string toString();

    bool LeerDeDisco(int nroRegistro);
    bool GuardarEnDisco();
    bool GuardarEnDisco(int nroRegistro);
};

int cantidad_registros_choferes();
int buscar_chofer(int id);