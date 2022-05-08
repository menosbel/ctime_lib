#include <iostream>
#include "AddExpenseHandler.h"

int main()
{
    int option;

    AddExpenseHandler addExpenseHandler = AddExpenseHandler();

    while (option != 0)
    {
        std::cout << "1- Agregar gasto\n";
        std::cout << "0- Salir\n";
        std::cout << "Elegi una opcion: \n";
        std::cin >> option;


        switch (option)
        {
        case 1:
            addExpenseHandler.execute();
        default:
            break;
        }

        system("pause");
        system("cls");
    }
    return 0;
}

