#include <iostream>
#include "rlutil.h"
using namespace std;

int main()
{
    int opcion;
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    do {
        rlutil::cls();
        cout << "-----------------------" << endl;
        cout << " 1 - Opcion 1" << endl;
        cout << " 2 - Opcion 2" << endl;
        cout << " 3 - Opcion 3" << endl;
        cout << "-----------------------" << endl;
        cout << " 0 - Salir" << endl;
        cout << endl << endl << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            cout << "Hasta luego" << endl << endl << endl;
            break;
        case 1:
            rlutil::cls();
            rlutil::locate(2, 5);
            cout << "Un mensaje";
            rlutil::anykey();
            break;
        case 2:
            int n1, n2;
            rlutil::cls();
            rlutil::locate(2, 2);
            cout << "   +    = ";
            rlutil::locate(2, 2);
            cin >> n1;
            rlutil::locate(7, 2);
            cin >> n2;
            rlutil::locate(13, 2);
            cout << n1 + n2;
            rlutil::anykey();
            break;
        case 3:
            break;
        default:
            rlutil::setColor(rlutil::RED);
            cout << "Esta opcion es incorrecta" << endl;
            rlutil::anykey();
            rlutil::setColor(rlutil::WHITE);
            break;
        } 

    } while (opcion != 0);

    return 0;
}
