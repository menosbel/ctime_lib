#pragma once
#include "FechaHora.h"
#include "Chofer.h"

class Parcial
{
public:
	void Punto1();
	float calcularLongPromViajeDiurno();
	float calcularLongPromViajeVespertino();
	float calcularLongPromViajeNocturno();
	float calcularLongPromViajeMadrugada ();

	void Punto2();
	int facturacionChofer(int idChofer);
	int calcularAntiguedadVehiculo(int anioPatentamiento);

	void Punto3();
	bool viajesNocturnosCancelados(int idChofer);
	bool viajeEsNocturno(FechaHora fechaHora);
	
	void Punto4();
	bool cobroSoloEnEfectivo(int idChofer);
};

