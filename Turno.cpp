#include <cstring>
#include "Turno.h"
#include <string>

using namespace std;

/// CONSTRUCTOR VACIO
Turno::Turno()
    : IdTurno(),FechaTurno(), Matricula(), Dni(), IdEspecialidad(), Consultorio(), HoraTurno(), IdEstadoTurno(0), Estado()
{
}

/// CONSTRUCTOR CON PARAMETROS
Turno::Turno(int idTurno, Fecha fechaTurno, int matricula, int dni, int idEspecialidad, int consultorio,
             Hora horaTurno, int idEstadoTurno, bool estado)
    : IdTurno(idTurno), FechaTurno(fechaTurno), Matricula(matricula), Dni(dni), IdEspecialidad(idEspecialidad), Consultorio(consultorio),
      HoraTurno(horaTurno), IdEstadoTurno(idEstadoTurno), Estado(estado)
{
}

/// GETTERS
int Turno::getIdTurno()
{
    return IdTurno;
}
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
int Turno::getConsultorio()
{
    return Consultorio;
}
Hora Turno::getHoraTurno()
{
    return HoraTurno;
}
int Turno::getIdEstadoTurno()
{
    return IdEstadoTurno;
}
bool Turno::getEstado()
{
    return Estado;
}


/// SETTERS
void Turno::setIdTurno(int idTurno)
{
    IdTurno = idTurno;
}
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
void Turno::setConsultorio(int consultorio)
{
    Consultorio = consultorio;
}
void Turno::setHoraTurno(Hora horaTurno)
{
    HoraTurno = horaTurno;
}
void Turno::setIdEstadoTurno(int estadoTurno)
{
    IdEstadoTurno = estadoTurno;
}
void Turno::setEstado(bool estado)
{
    Estado = estado;
}
