#include "Chofer.h"
#include <cstdio>
#include <cstring>

int Chofer::getID()
{
  return _ID;
}

void Chofer::setID(int ID)
{
  _ID = ID;
}

const char* Chofer::getApellidos()
{
  return _Apellidos;
}

void Chofer::setApellidos(const char* Apellidos)
{
  strcpy(_Apellidos, Apellidos);
}

const char* Chofer::getNombres()
{
  return _Nombres;
}

void Chofer::setNombres(const char* Nombres)
{
  strcpy(_Nombres, Nombres);
}

const char* Chofer::getPatente()
{
  return _Patente;
}

void Chofer::setPatente(const char* Patente)
{
  strcpy(_Patente, Patente);
}

int Chofer::getIDMarca()
{
  return _IDMarca;
}

void Chofer::setIDMarca(int IDMarca)
{
  _IDMarca = IDMarca;
}

int Chofer::getAnioPatentamiento()
{
  return _AnioPatentamiento;
}

void Chofer::setAnioPatentamiento(int AnioPatentamiento)
{
  _AnioPatentamiento = AnioPatentamiento;
}

std::string Chofer::toString() {
  std::string result;
  result = std::to_string(_ID) + ", " + _Apellidos + ", " + _Nombres + ", " + _Patente + ", " + std::to_string(_IDMarca) + ", " + std::to_string(_AnioPatentamiento);
  return result;
}

bool Chofer::LeerDeDisco(int nroRegistro) {
  FILE* p = fopen("Choferes.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Chofer), SEEK_SET);
  bool ok = fread(this, sizeof(Chofer), 1, p);
  fclose(p);
  return ok;
}

bool Chofer::GuardarEnDisco() {
  FILE* p = fopen("Choferes.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool guardo = fwrite(this, sizeof(Chofer), 1, p);
  fclose(p);
  return guardo;
}

bool Chofer::GuardarEnDisco(int nroRegistro) {
  FILE* p = fopen("Choferes.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Chofer), SEEK_SET);
  bool guardo = fwrite(this, sizeof(Chofer), 1, p);
  fclose(p);
  return guardo;
}

int cantidad_registros_choferes() {
  FILE* p = fopen("Choferes.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  size_t bytes;
  int cant_reg;

  fseek(p, 0, SEEK_END);
  bytes = ftell(p);
  fclose(p);
  cant_reg = bytes / sizeof(Chofer);
  return cant_reg;
}

int buscar_chofer(int id) {
  Chofer aux;
  int i = 0;
  int cant = cantidad_registros_choferes();
  for (i = 0; i < cant; i++) {
    aux.LeerDeDisco(i);
    if (aux.getID() == id) {
      return i;
    }
  }
  return -1;
}
