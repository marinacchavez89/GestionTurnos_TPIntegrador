#pragma once
#include <string>
#include "Hora.h"

class HorariosProfesionales
{
private:
    int Matricula;
    int DiaAtencion;
    Hora HoraInicio;
    Hora HoraFin;
    int DuracionTurno;
    bool Estado;
public:
    /// CONSTRUCTOR
    HorariosProfesionales();
    HorariosProfesionales(int matricula, int diaAtencion, Hora horaInicio, Hora horaFin, int duracionTurno, bool estado);
    /// GETTERS
    int getMatricula();
    int getDiaAtencion();
    Hora getHoraInicio();
    Hora getHoraFin();
    int getDuracionTurno();
    bool getEstado();

    ///SETTERS
    void setMatricula(int matricula);
    void setDiaAtencion(int diaAtencion);
    void setHoraInicio(Hora horaInicio);
    void setHoraFin(Hora horaFin);
    void setDuracionTurno(int duracionTurno);
    void setEstado(bool estado);

};
