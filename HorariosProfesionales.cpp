#include <cstring>
#include "HorariosProfesionales.h"
#include <string>

/// CONSTRUCTOR VACIO
HorariosProfesionales::HorariosProfesionales()
    : Matricula(0), DiaAtencion(0), HoraInicio(), HoraFin(), DuracionTurno(0), Estado() { }

///CONSTRUCTOR CON SUS PARAMETROS
HorariosProfesionales::HorariosProfesionales(int matricula, int diaAtencion, Hora horaInicio,
    Hora horaFin, int duracionTurno, bool estado)
    : Matricula(matricula), DiaAtencion(diaAtencion), HoraInicio(horaInicio),
    HoraFin(horaFin), DuracionTurno(duracionTurno), Estado(estado)
{

}

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
bool HorariosProfesionales::getEstado()
{
    return Estado;
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
void HorariosProfesionales::setEstado(bool estado)
{
    Estado = estado;
}
