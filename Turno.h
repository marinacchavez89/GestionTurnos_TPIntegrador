#pragma once
#include <string>
#include "Hora.h"
#include "Fecha.h"

class Turno
{
private:
    Fecha FechaTurno;
    int Matricula;
    int Dni;
    int IdEspecialidad;
    int IdConsultorio;
    int IdCobertura;
    Hora HoraTurno;
    int IdEstadoTurno;

public:
    /// CONSTRUCTOR
    Turno();
    Turno(Fecha fechaTurno, int matricula, int dni, int idEspecialidad, int idConsultorio, int idCobertura,
          Hora horaTurno, int estadoTurno);

    /// GETTERS
    Fecha getFechaTurno();
    int getMatricula();
    int getDni();
    int getIdEspecialidad();
    int getIdConsultorio();
    int getIdCobertura();
    Hora getHoraTurno();
    int getEstadoTurno();

    /// SETTERS
    void setFechaTurno(Fecha fechaTurno);
    void setMatricula(int matricula);
    void setDni(int dni);
    void setIdEspecialidad(int idEspecialidad);
    void setIdConsultorio(int idConsultorio);
    void setIdCobertura(int idCobertura);
    void setHoraTurno(Hora horaTurno);
    void setEstadoTurno(int estadoTurno);
};
