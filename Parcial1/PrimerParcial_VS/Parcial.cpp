#include "Parcial.h"
#include "Chofer.h"
#include "Viaje.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Parcial::Punto1()
{
	cout << left << setw(20) << setfill(' ') << "Tipo de viaje";
	cout << left << setw(8) << setfill(' ') << "Longitud promedio";
	cout << endl << endl;
	cout << left << setw(20) << setfill(' ') << "Diurno";
	cout << left << setw(8) << setfill(' ') << calcularLongPromViajeDiurno() << " kms";
	cout << endl;
	cout << left << setw(20) << setfill(' ') << "Vespertino";
	cout << left << setw(8) << setfill(' ') << calcularLongPromViajeVespertino() << " kms";
	cout << endl;
	cout << left << setw(20) << setfill(' ') << "Nocturno";
	cout << left << setw(8) << setfill(' ') << calcularLongPromViajeNocturno() << " kms";
	cout << endl;
	cout << left << setw(20) << setfill(' ') << "Madrugada";
	cout << left << setw(8) << setfill(' ') << calcularLongPromViajeMadrugada() << " kms";
	cout << endl;
}

float Parcial::calcularLongPromViajeDiurno()
{
	Viaje viaje;
	int pos = 0;
	float totalKms = 0;
	float totalViajes = 0;

	while (viaje.LeerDeDisco(pos++))
	{
		int hora = viaje.getFechaHora().getHora();
		if (hora >= 7 && hora <= 13)
		{
			totalViajes++;
			totalKms += viaje.getKms();
		}
	}
	return totalKms / totalViajes;
}

float Parcial::calcularLongPromViajeVespertino()
{
	Viaje viaje;
	int pos = 0;
	float totalKms = 0;
	float totalViajes = 0;

	while (viaje.LeerDeDisco(pos++))
	{
		int hora = viaje.getFechaHora().getHora();
		if (hora >= 13 && hora <= 19)
		{
			totalViajes++;
			totalKms += viaje.getKms();
		}
	}
	return totalKms / totalViajes;
}

float Parcial::calcularLongPromViajeNocturno()
{
	Viaje viaje;
	int pos = 0;
	float totalKms = 0;
	float totalViajes = 0;

	while (viaje.LeerDeDisco(pos++))
	{
		int hora = viaje.getFechaHora().getHora();
		int min = viaje.getFechaHora().getMinuto();
		if (hora >= 20 || hora == 0 && min <= 59)
		{
			totalViajes++;
			totalKms += viaje.getKms();
		}
	}
	return totalKms / totalViajes;
}

float Parcial::calcularLongPromViajeMadrugada()
{
	Viaje viaje;
	int pos = 0;
	float totalKms = 0;
	float totalViajes = 0;

	while (viaje.LeerDeDisco(pos++))
	{
		int hora = viaje.getFechaHora().getHora();
		if (hora >= 1 && hora <= 7)
		{
			totalViajes++;
			totalKms += viaje.getKms();
		}
	}
	return totalKms / totalViajes;
}

void Parcial::Punto2()
{
	Chofer chofer;
	int cantChoferes = cantidad_registros_choferes();
	int* choferesFacturacion = new int[cantChoferes];
	if (choferesFacturacion == nullptr) cout << "Error con asignacion memoria" << endl;
	
	int pos = 0;
	int facturacion;

	for (int i = 0; i < cantChoferes; i++)
	{
		choferesFacturacion[i] = 0;
	}

	for (int i = 0; i < cantChoferes; i++)
	{
		chofer.LeerDeDisco(i);
		facturacion = facturacionChofer(chofer.getID());
		choferesFacturacion[i] =+ facturacion;
	}
	
	int posMenor = 0;
	int valor;
	for (int i = 1; i < (cantChoferes - 1); i++)
	{
		valor = choferesFacturacion[i];
		if (valor > 0)
		{
			if (choferesFacturacion[i] < choferesFacturacion[i - 1])
			{
				posMenor = i;
			}
		}
	}

	delete[] choferesFacturacion;

	if (posMenor != -1)
	{
		chofer.LeerDeDisco(posMenor);
		cout << "Apellido: " << chofer.getApellidos() << endl;
		cout << "Nombre: " << chofer.getNombres() << endl;
		cout << "Patente: " << chofer.getPatente() << endl;
		cout << "Antiguedad vehiculo: " << calcularAntiguedadVehiculo(chofer.getAnioPatentamiento()) << endl;
	}
	else cout << "Nadie facturo mas de $0" << endl;
}

int Parcial::facturacionChofer(int idChofer)
{
	Viaje viaje;
	int pos = 0;
	int totalImportes = 0;

	while (viaje.LeerDeDisco(pos++))
	{
		if (viaje.getIDChofer() == idChofer && viaje.getFechaHora().getAnio() == 2021)
		{
			totalImportes += viaje.getImporte();
		}
	}
	return totalImportes;
}

int Parcial::calcularAntiguedadVehiculo(int anioPatentamiento)
{
	FechaHora fechaHora;
	int anioActual = fechaHora.getAnio();
	return anioActual - anioPatentamiento;
}

void Parcial::Punto3()
{
	Chofer chofer;
	int idChofer;
	bool cancelados;
	int pos = 0, cantidadChoferesSinViajesNocturnosCancelados = 0;

	while (chofer.LeerDeDisco(pos++))
	{
		idChofer = chofer.getID();
		cancelados = viajesNocturnosCancelados(idChofer);

		if (!cancelados)
		{
			cantidadChoferesSinViajesNocturnosCancelados++;
		}
	}

	cout << "Cantidad de choferes a quienes nunca les hayan cancelado un viaje nocturno: " << cantidadChoferesSinViajesNocturnosCancelados << endl;
}

bool Parcial::viajesNocturnosCancelados(int idChofer)
{
	Viaje viaje;
	int pos = 0;
	bool viajeNocturno;

	while (viaje.LeerDeDisco(pos++))
	{
		if (viaje.getIDChofer() == idChofer && viaje.getCancelado() == false && viajeEsNocturno(viaje.getFechaHora()))
		{
			return true;
		}
	}
	return false;
}

bool Parcial::viajeEsNocturno(FechaHora fechaHora)
{
	int hora = fechaHora.getHora();
	int min = fechaHora.getMinuto();
	if (hora >= 20 || hora == 0 && min <= 59)
	{
		return true;
	}
	return false;
}

void Parcial::Punto4()
{
	Chofer chofer;
	int pos = 0;
	int idChofer;
	bool soloEfectivo = false;

	cout << "Choferes que cobraron unicamente en efectivo: " << endl;
	while (chofer.LeerDeDisco(pos++))
	{
		idChofer = chofer.getID();
		
		if (cobroSoloEnEfectivo(idChofer))
		{
			soloEfectivo = true;
			cout << chofer.getApellidos() << ", " << chofer.getNombres() << endl;
		}
	}
	if (!soloEfectivo)
	{
		cout << "Nadie cobro solo en efectivo" << endl;
	}
}

bool Parcial::cobroSoloEnEfectivo(int idChofer)
{
	Viaje viaje;
	int pos = 0;
	bool soloEfectivo = true;

	while (viaje.LeerDeDisco(pos++))
	{
		if (viaje.getIDChofer() == idChofer && viaje.getIDFormaPago() != 1)
		{
			soloEfectivo = false;
		}
	}
	return soloEfectivo;
}
