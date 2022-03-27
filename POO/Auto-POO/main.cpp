#include <iostream>

using namespace std;

class Auto {
    private:
        int _velocidad;
    public:
        Auto();
       ~Auto();
        void acelerar(int valor);
        void mostrar();
        int getVelocidad();
};

void Auto::acelerar(int valor){
    _velocidad += valor;
}

void Auto::mostrar(){
    cout << _velocidad << endl;
}

int Auto::getVelocidad(){
    return _velocidad;
}


/// Constructor
Auto::Auto(){
    _velocidad = 0;
}

/// Destructor
Auto::~Auto(){
    cout << "Destruyendo al auto a " << _velocidad << " km/h" << endl;
}


int main()
{
    Auto a; // Se ejecuta el constructor
    Auto b;
    Auto c[2];
    a.acelerar(100);
    cout << a.getVelocidad() << endl;
    return 0;
}
