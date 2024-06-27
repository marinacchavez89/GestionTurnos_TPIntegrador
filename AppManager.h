#ifndef APPMANAGER_H_INCLUDED
#define APPMANAGER_H_INCLUDED

#include <iostream>
#include <locale.h>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "ProfesionalArchivo.h"
#include "ProfesionalManager.h"
#include "EspecialidadArchivo.h"
#include "EspecialidadManager.h"
#include "EstadoTurnoArchivo.h"
#include "EstadoTurnoManager.h"
#include "PacienteArchivo.h"
#include "PacienteManager.h"
#include "HorariosProfesionalesArchivo.h"
#include "HorariosProfesionalesManager.h"
#include "TurnoArchivo.h"
#include "TurnoManager.h"

using namespace std;

class AppManager{
private:
    ProfesionalArchivo archiProf;
    ProfesionalManager managerProfesional;
    EspecialidadArchivo archiEspe;
    EspecialidadManager managerEspecialidad;
    EstadoTurnoArchivo  archiEstadoTurno;
    EstadoTurnoManager  managerEstadoTurnos;
    PacienteArchivo archiPacientes;
    PacienteManager managerPaciente;
    HorariosProfesionalesArchivo archiHorariosProf;
    HorariosProfesionalesManager managerHorariosProf;
    TurnoArchivo archiTurno;
    TurnoManager managerTurno;
public:
    void configurarConsola();
    void dibujarEncabezado();
    void dibujarAdios();
    void menuABMTurnos();
    void menuABMProfesionales();
    void menuABMPacientes();
    void menuABMEspecialidades();
    void menuABMAgendaProfesionales();
    void menuPrincipal();
    void errorOpcion();
};
void AppManager::configurarConsola(){
    // Cambiar el tamaño de la ventana de la consola
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 79, 40};
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
    cfi.dwFontSize.Y = 18;                  // Altura del carácter
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Verdanas");      // Fuente a usar
    SetCurrentConsoleFontEx(hOut, FALSE, &cfi);
}
void AppManager::dibujarEncabezado(){

    system("cls");

    // Dibuja un borde
    for(int i = 0; i < 80; ++i)
    std::cout << "-";
    std::cout << std::endl;

    // Dibuja el contenido
    std::cout << "|                              GESTIÓN DE TURNOS                               |" << std::endl;

    // Dibuja un borde
    for(int i = 0; i < 80; ++i)
    std::cout << "-";
    std::cout << std::endl;
}
void AppManager::dibujarAdios(){
    cout << endl;
    cout << "********************************************************************************" << endl;
    cout << "|                                      ¡ADIÓS!                                 |" << endl;
    cout << "********************************************************************************" << endl;
}
void AppManager::errorOpcion(){
    cout<<"Ingrese una opción correcta del menu."<<endl;
    system("pause");
}

void AppManager::menuABMTurnos(){
    int opcionTurnos;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                 MENU TURNOS                                  |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta turno" << endl;
        cout << "2  - Modificar turno" << endl;
        cout << "3  - Eliminar turno" << endl;
        cout << "4  - Listar turnos" << endl;
        cout << "5  - Alta estado del turno" << endl;
        cout << "6  - Modificar estado del turno" << endl;
        cout << "7  - Eliminar estado del turno" << endl;
        cout << "8  - Listar estado de los turnos" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionTurnos;

        switch(opcionTurnos)
        {
        case 1:
            managerTurno.agregar();
            system("pause");
            break;
        case 2:
            managerTurno.modificar();
            system("pause");
            break;
        case 3:
            managerTurno.eliminar();
            system("pause");
            break;
        case 4:
            managerTurno.listar();
            system("pause");
            break;
        case 5:
            managerEstadoTurnos.agregar();
            system("pause");
            break;
        case 6:
            managerEstadoTurnos.modificar();
            system("pause");
            break;
        case 7:
            managerEstadoTurnos.eliminar();
            system("pause");
            break;
        case 8:
            managerEstadoTurnos.listar();
            system("pause");
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionTurnos >= 0 || opcionTurnos <= 8);

}
void AppManager::menuABMProfesionales(){
    int opcionProfesionales;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                             MENU PROFESIONALES                                |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta profesional" << endl;
        cout << "2  - Modificar profesional" << endl;
        cout << "3  - Eliminar profesional" << endl;
        cout << "4  - Listar profesionales" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionProfesionales;

        switch(opcionProfesionales)
        {
        case 1:
            managerProfesional.agregar();
            system("pause");
            break;
        case 2:
            managerProfesional.modificar();
            system("pause");
            break;
        case 3:
            managerProfesional.eliminar();
            system("pause");
            break;
        case 4:
            managerProfesional.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionProfesionales >= 0 || opcionProfesionales <= 5);

}
void AppManager::menuABMPacientes(){
    int opcionPacientes;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                               MENU PACIENTES                                  |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta paciente" << endl;
        cout << "2  - Modificar paciente" << endl;
        cout << "3  - Eliminar paciente" << endl;
        cout << "4  - Listar paciente" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionPacientes;

        switch(opcionPacientes)
        {
        case 1:
            managerPaciente.agregar();
            system("pause");
            break;
        case 2:
            managerPaciente.modificar();
            system("pause");
            break;
        case 3:
            managerPaciente.eliminar();
            system("pause");
            break;
        case 4:
            managerPaciente.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionPacientes >= 0 || opcionPacientes <= 5);

}
void AppManager::menuABMEspecialidades(){
    int opcionEspecialidades;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                             MENU ESPECIALIDADES                               |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta especialidad" << endl;
        cout << "2  - Modificar especialidad" << endl;
        cout << "3  - Eliminar especialidad" << endl;
        cout << "4  - Listar especialidades" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionEspecialidades;

        switch(opcionEspecialidades)
        {
        case 1:
            managerEspecialidad.agregar();
            system("pause");
            break;
        case 2:
            managerEspecialidad.modificar();
            system("pause");
            break;
        case 3:
            managerEspecialidad.eliminar();
            system("pause");
            break;
        case 4:
            managerEspecialidad.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            system("pause");
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionEspecialidades >= 0 || opcionEspecialidades <= 5);

}
void AppManager::menuABMAgendaProfesionales(){
    int opcionAgenda;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                          MENU AGENDA PROFESIONALES                            |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta horario" << endl;
        cout << "2  - Modificar horario" << endl;
        cout << "3  - Eliminar horario" << endl;
        cout << "4  - Listar horarios" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionAgenda;

        switch(opcionAgenda)
        {
        case 1:
            managerHorariosProf.agregar();
            system("pause");
            break;
        case 2:
            managerHorariosProf.modificar();
            system("pause");
            break;
        case 3:
            managerHorariosProf.eliminar();
            system("pause");
            break;
        case 4:
            managerHorariosProf.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            break;
        case 0:
            menuPrincipal();
            break;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionAgenda >= 0 || opcionAgenda <= 5);

}


void AppManager::menuPrincipal(){
    int opcion;
    do
    {
        system("cls");
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                               MENU PRINCIPAL                                 |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Administrar turnos" << endl;
        cout << "2  - Administrar profesionales" << endl;
        cout << "3  - Administrar pacientes" << endl;
        cout << "4  - Administrar especialidades" << endl;
        cout << "5  - Administrar agenda profesionales" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                MENU REPORTES                                 |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "6  - Recaudación anual" << endl;
        cout << "7  - Recaudación por profesional" << endl;
        cout << "8  - Recaudación por especialidad" << endl;
        cout << "9  - Cantidad de turnos asignados" << endl;
        cout << "10 - Administrar agenda profesionales" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                MENU CONSULTAS                                |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "11 - Consulta de pacientes" << endl;
        cout << "12 - Consulta de Profesionales" << endl;
        cout << "13 - Consulta de turnos" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            menuABMTurnos();
            system("pause");
            break;
        case 2:
            menuABMProfesionales();
            system("pause");
            break;
        case 3:
            menuABMPacientes();
            system("pause");
            break;
        case 4:
            menuABMEspecialidades();
            system("pause");
            break;
        case 5:
            menuABMAgendaProfesionales();
            system("pause");
            break;
        case 0:
            dibujarAdios();
            break;
        default:
            errorOpcion();
            menuPrincipal();
            break;
        }
    }
    while(opcion != 0);
}

#endif // APPMANAGER_H_INCLUDED

