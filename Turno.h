#pragma once
#include <string>
#include "Hora.h"
#include "Fecha.h"

class Turno
{
private:
    int IdTurno;
    Fecha FechaTurno;
    int Matricula;
    int Dni;
    int IdEspecialidad;
    int Consultorio;
    Hora HoraTurno;
    int IdEstadoTurno;
    bool Estado;

public:
    /// CONSTRUCTOR
    Turno();
    Turno(int idTurno,Fecha fechaTurno, int matricula, int dni, int idEspecialidad, int consultorio,
          Hora horaTurno, int idEstadoTurno, bool estado);

    /// GETTERS
    int getIdTurno();
    Fecha getFechaTurno();
    int getMatricula();
    int getDni();
    int getIdEspecialidad();
    int getConsultorio();
    Hora getHoraTurno();
    int getIdEstadoTurno();
    bool getEstado();

    /// SETTERS
    void setIdTurno(int idTurno);
    void setFechaTurno(Fecha fechaTurno);
    void setMatricula(int matricula);
    void setDni(int dni);
    void setIdEspecialidad(int idEspecialidad);
    void setConsultorio(int consultorio);
    void setHoraTurno(Hora horaTurno);
    void setIdEstadoTurno(int idEstadoTurno);
    void setEstado(bool estado);
};
