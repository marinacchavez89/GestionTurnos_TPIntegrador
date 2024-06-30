#ifndef APPMANAGER_H_INCLUDED
#define APPMANAGER_H_INCLUDED

#include <iostream>
#include <locale.h>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "LoginArchivo.h"
#include "LoginManager.h"
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

class AppManager
{
private:
    LoginArchivo archiLogin;
    LoginManager managerLogin;
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
    int menuLogin();
    void menuABMUsuarios();
    void menuConsultasPacientes();
    void menuConsultasProfesionales();
    void menuConsultasTurnos();
};

#endif // APPMANAGER_H_INCLUDED

