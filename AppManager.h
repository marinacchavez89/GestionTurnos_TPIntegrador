#ifndef APPMANAGER_H_INCLUDED
#define APPMANAGER_H_INCLUDED

#include <iostream>
#include <locale.h>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "ProfesionalArchivo.h"
#include "Profesional.h"

using namespace std;

class AppManager
{
private:
    ProfesionalArchivo archiProf;
    Profesional profesional;
public:
    void configurarConsola();
    void dibujarEncabezado();
    void menuPrincipal();
};

void AppManager::configurarConsola()
{
    // Cambiar el tamaño de la ventana de la consola
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 79, 20};
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    // Cambiar el tamaño del buffer de la consola
    COORD bufferSize = {70, 20};
    SetConsoleScreenBufferSize(hOut, bufferSize);

    // Cambiar los colores de la consola
    SetConsoleTextAttribute(hOut, 15 | BACKGROUND_RED | BACKGROUND_BLUE);

    // Cambiar la fuente de la consola
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Ancho del carácter
    cfi.dwFontSize.Y = 20;                  // Altura del carácter
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Verdanas");      // Fuente a usar
    SetCurrentConsoleFontEx(hOut, FALSE, &cfi);
}

void AppManager::dibujarEncabezado()
{

    system("cls");

    // Dibuja un borde
    for(int i = 0; i < 80; ++i)
        std::cout << "-";
    std::cout << std::endl;

    // Dibuja el contenido
    std::cout << "|                                                                              |" << std::endl;
    std::cout << "|                              GESTIÓN DE TURNOS                               |" << std::endl;
    std::cout << "|                                                                              |" << std::endl;

    // Dibuja un borde
    for(int i = 0; i < 80; ++i)
        std::cout << "-";
    std::cout << std::endl;

    // Espera a que el usuario presione una tecla antes de salir
    //getch();

}

void AppManager::menuPrincipal()
{
    int opcion;
    do
    {
        system("cls");
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                               MENU PRINCIPAL                                 |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1- Cargar profesional" << endl;
        cout << "2- Listar profesionales" << endl;
        cout << "3- xxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
        {
            Profesional profesional;
            profesional.cargar();
            if (archiProf.grabarRegistro(profesional))
            {
                cout << "Profesional guardado exitosamente." << endl;
            }
            else
            {
                cout << "Error al guardar el profesional." << endl;
            }
            system("pause");
            break;
        }

        case 2:
        {
            if (!archiProf.listarRegistros())
            {
                std::cout << "Error al listar los profesionales." << std::endl;
            }
            system("pause");
            break;
        }

        case 3:
            //Llamar a la funcion correspondiente.
            system("pause");
            break;
        }
    }
    while(opcion != 0);

}

#endif // APPMANAGER_H_INCLUDED

