#include <cstring>
#include "HorariosProfesionales.h"
#include <string>

/// CONSTRUCTOR VACIO
HorariosProfesionales::HorariosProfesionales()
    : Matricula(0), DiaAtencion(0), HoraInicio(), HoraFin(), DuracionTurno(0) { }

///CONSTRUCTOR CON SUS PARAMETROS
HorariosProfesionales::HorariosProfesionales(int matricula, int diaAtencion, Hora horaInicio,
                                             Hora horaFin, int duracionTurno) { }

///GETTERS
int HorariosProfesionales::getMatricula()
{
    return Matricula;
}
int HorariosProfesionales::getDiaAtencion()
{
    return DiaAtencion;
}
Hora HorariosProfesionales::getHoraInicio()
{
    return HoraInicio;
}
Hora HorariosProfesionales::getHoraFin()
{
    return HoraFin;
}
int HorariosProfesionales::getDuracionTurno()
{
    return DuracionTurno;
}

///SETTERS
void HorariosProfesionales::setMatricula(int matricula)
{
    Matricula = matricula;
}
void HorariosProfesionales::setDiaAtencion(int diaAtencion)
{
    DiaAtencion = diaAtencion;
}
void HorariosProfesionales::setHoraInicio(Hora horaInicio)
{
    HoraInicio = horaInicio;
}
void HorariosProfesionales::setHoraFin(Hora horaFin)
{
    HoraFin = horaFin;
}
void HorariosProfesionales::setDuracionTurno(int duracionTurno)
{
    DuracionTurno = duracionTurno;
}
