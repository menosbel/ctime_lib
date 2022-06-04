#include "Viaje.h"
#include <cstdio>
#include <iomanip>
#include <sstream>


int Viaje::getID()
{
    return _ID;
}

void Viaje::setID(int ID)
{
    _ID = ID;
}

int Viaje::getIDChofer()
{
    return _IDChofer;
}

void Viaje::setIDChofer(int IDChofer)
{
    _IDChofer = IDChofer;
}

int Viaje::getDNI()
{
    return _DNI;
}

void Viaje::setDNI(int DNI)
{
    _DNI = DNI;
}

float Viaje::getKms()
{
    return _Kms;
}

void Viaje::setKms(float Kms)
{
    _Kms = Kms;
}

int Viaje::getIDFormaPago()
{
    return _IDFormaPago;
}

void Viaje::setIDFormaPago(int IDFormaPago)
{
    _IDFormaPago = IDFormaPago;
}

FechaHora Viaje::getFechaHora()
{
    return _FechaHora;
}

void Viaje::setFechaHora(FechaHora FechaHora)
{
    _FechaHora = FechaHora;
}

int Viaje::getDuracion()
{
    return _Duracion;
}

void Viaje::setDuracion(int Duracion)
{
    _Duracion = Duracion;
}

int Viaje::getImporte()
{
    return _Importe;
}

void Viaje::setImporte(int Importe)
{
    _Importe = Importe;
}

bool Viaje::getCancelado()
{
    return _Cancelado;
}

void Viaje::setCancelado(bool Cancelado)
{
    _Cancelado = Cancelado;
}

std::string Viaje::toString() {
  std::string result;
  std::ostringstream out;
  out.precision(1);
  out << std::fixed << _Kms;
  result = std::to_string(_ID) + ", " + std::to_string(_IDChofer) + ", " + std::to_string(_DNI) + ", " + out.str() + ", " + std::to_string(_IDFormaPago) + ", " + _FechaHora.toString() + ", " + std::to_string(_Duracion) + ", " + std::to_string(_Importe) + ", " + std::to_string(_Cancelado);
  return result;
}

bool Viaje::LeerDeDisco(int nroRegistro) {
  FILE* p = fopen("Viajes.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Viaje), SEEK_SET);
  bool ok = fread(this, sizeof(Viaje), 1, p);
  fclose(p);
  return ok;
}

bool Viaje::GuardarEnDisco() {
  FILE* p = fopen("Viajes.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool guardo = fwrite(this, sizeof(Viaje), 1, p);
  fclose(p);
  return guardo;
}

bool Viaje::GuardarEnDisco(int nroRegistro) {
  FILE* p = fopen("Viajes.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Viaje), SEEK_SET);
  bool guardo = fwrite(this, sizeof(Viaje), 1, p);
  fclose(p);
  return guardo;
}

int cantidad_registros_viajes(){
  FILE* p = fopen("Viajes.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  size_t bytes;
  int cant_reg;

  fseek(p, 0, SEEK_END);
  bytes = ftell(p);
  fclose(p);
  cant_reg = bytes / sizeof(Viaje);
  return cant_reg;
}

int buscar_viaje(int id) {
  Viaje aux;
  int i = 0;
  int cant = cantidad_registros_viajes();
  for (i = 0; i < cant; i++) {
    aux.LeerDeDisco(i);
    if (aux.getID() == id) {
      return i;
    }
  }
  return -1;
}
