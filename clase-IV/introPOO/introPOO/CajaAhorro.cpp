#include "CajaAhorro.h"

CajaAhorro::CajaAhorro(int numeroCuenta, float saldo)
{
	_numeroCuenta = numeroCuenta;
	_saldo = saldo;
}

CajaAhorro::CajaAhorro() {}

void CajaAhorro::setApellido(std::string apellido) {
	_apellido = apellido;
};

void CajaAhorro::setNombre(std::string nombre) {
	_nombre = nombre;
};

void CajaAhorro::setNumeroCuenta(int numeroCuenta) {
	_numeroCuenta = numeroCuenta;
};

void CajaAhorro::setSaldo(float saldo) {
	_saldo = saldo;
};

std::string CajaAhorro::getApellido() { return _apellido; };

std::string CajaAhorro::getNombre() { return _nombre; };

int CajaAhorro::getNumeroCuenta() { return _numeroCuenta; };

float CajaAhorro::getSaldo() { return _saldo; }

void CajaAhorro::deposito(float value)
{
	_saldo += value;
}

void CajaAhorro::extraccion(float value)
{
	if (_saldo >= value && value > 0) 
	{ 
		_saldo -= value; 
	}
}

