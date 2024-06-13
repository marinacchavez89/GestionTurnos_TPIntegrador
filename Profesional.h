#pragma once
#include "Persona.h"
#include <string>
#include "Hora.h"

class Profesional: public Persona
{
private:
    int IdEspecialidad;
    int Matricula;
    int Consultorio;
    float Honorario;
    int DuracionTurno;
public:
    /// CONSTRUCTOR
    Profesional();
    Profesional(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado,
                int idEspecialidad, int matricula, int consultorio, float honorario, int DuracionTurno);
    /// GETTERS
    int getIdEspecialidad();
    int getMatricula();
    int getConsultorio();
    float getHonorario();
    int getDuracionTurno();

    ///SETTERS
    void setIdEspecialidad(int idEspecialidad);
    void setMatricula(int matricula);
    void setConsultorio(int consultorio);
    void setHonorario(float honorario);
    void setDuracionTurno(int duracionTurno);
};
