#include <iostream>
#include "Fecha.h"

int main()
{
    Fecha fecha;
    int dia, mes, anio;
    int continuar = 1;

    std::cout << "Hoy es ";
    fecha.mostrar();
    std::cout << std::endl;

    std::cout << "Segundo constructor: ";
    Fecha fecha2(1, 2, 2020);
    fecha2.mostrar();
    std::cout << std::endl;

    std::cout << "Tercer constructor: ";
    Fecha fecha3("02/10/1990");
    fecha3.mostrar();
    std::cout << std::endl;

    system("pause");
    system("cls");

    while (continuar != 0) {
        std::cout << "Dia: ";
        std::cin >> dia;
        fecha.setDia(dia);

        std::cout << "Mes: ";
        std::cin >> mes;
        fecha.setMes(mes);

        std::cout << "Año: ";
        std::cin >> anio;
        fecha.setAnio(anio);

        fecha.mostrar();

        system("pause");
        system("cls");

        std::cout << "--------" << std::endl;
        std::cout << "Presione 0 para terminar el programa" << std::endl;
        std::cin >> continuar;

        system("cls");

    }    
}
