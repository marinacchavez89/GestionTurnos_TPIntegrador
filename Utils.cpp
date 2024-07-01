#include "Utils.h"

string toUpperCase(string palabra) {
    string palabraMayus = palabra;
    transform(palabraMayus.begin(), palabraMayus.end(), palabraMayus.begin(), ::toupper);
    return palabraMayus;
}

bool validarIngresoNros(int nro)
{
    if (cin.fail() || nro < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "********************************************************************************" << endl;
        cout << "                     Entrada no válida. Ingrese solo números.                   " << endl;
        cout << "********************************************************************************" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
        return false;
    }
    else{
        return true;
    }
}
