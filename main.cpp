#include <iostream>
#include <locale.h>
#include <cstring>
#include <ctime>
#include <conio.h>

using namespace std;

#include "funciones.h"
#include "appManager.h"


int main()
{
    setlocale(LC_ALL, "spanish");

    AppManager appManager;
    appManager.configurarConsola();
    appManager.menuPrincipal();

    return 0;
}
