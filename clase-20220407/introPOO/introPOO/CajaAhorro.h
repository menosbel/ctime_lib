#pragma once
#include <string>

class CajaAhorro
{
private:
	std::string _apellido;
	std::string _nombre;
	int _numeroCuenta;
	float _saldo;

public:
	CajaAhorro(int numeroCuenta, float saldo = 0);
	CajaAhorro();
	void setApellido(std::string apellido);
	void setNombre(std::string nombre);
	void setNumeroCuenta(int numeroCuenta);
	void setSaldo(float saldo);

	std::string getApellido();
	std::string getNombre();
	int getNumeroCuenta();
	float getSaldo();

	void deposito(float value);
	void extraccion(float value);
};

