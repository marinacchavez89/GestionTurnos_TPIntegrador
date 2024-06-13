#include <cstring>
#include "Turno.h"
#include <string>

using namespace std;

/// CONSTRUCTOR VACIO
Turno::Turno()
    : FechaTurno(), Matricula(0), Dni(0), IdEspecialidad(0), IdConsultorio(0), IdCobertura(0), HoraTurno(), IdEstadoTurno(0), Estado()
{
}

/// CONSTRUCTOR CON PARAMETROS
Turno::Turno(Fecha fechaTurno, int matricula, int dni, int idEspecialidad, int idConsultorio, int idCobertura,
             Hora horaTurno, int estadoTurno, bool estado)
    : FechaTurno(fechaTurno), Matricula(matricula), Dni(dni), IdEspecialidad(idEspecialidad), IdConsultorio(idConsultorio),
      IdCobertura(idCobertura), HoraTurno(horaTurno), IdEstadoTurno(estadoTurno), Estado(estado)
{
}

/// GETTERS
Fecha Turno::getFechaTurno()
{
    return FechaTurno;
}
int Turno::getMatricula()
{
    return Matricula;
}
int Turno::getDni()
{
    return Dni;
}
int Turno::getIdEspecialidad()
{
    return IdEspecialidad;
}
int Turno::getIdConsultorio()
{
    return IdConsultorio;
}
int Turno::getIdCobertura()
{
    return IdCobertura;
}
Hora Turno::getHoraTurno()
{
    return HoraTurno;
}
int Turno::getEstadoTurno()
{
    return IdEstadoTurno;
}
bool Turno::getEstado()
{
    return Estado;
}


/// SETTERS
void Turno::setFechaTurno(Fecha fechaTurno)
{
    FechaTurno = fechaTurno;
}
void Turno::setMatricula(int matricula)
{
    Matricula = matricula;
}
void Turno::setDni(int dni)
{
    Dni = dni;
}
void Turno::setIdEspecialidad(int idEspecialidad)
{
    IdEspecialidad = idEspecialidad;
}
void Turno::setIdConsultorio(int idConsultorio)
{
    IdConsultorio = idConsultorio;
}
void Turno::setIdCobertura(int idCobertura)
{
    IdCobertura = idCobertura;
}
void Turno::setHoraTurno(Hora horaTurno)
{
    HoraTurno = horaTurno;
}
void Turno::setEstadoTurno(int estadoTurno)
{
    IdEstadoTurno = estadoTurno;
}
void Turno::setEstado(bool estado)
{
    Estado = estado;
}
