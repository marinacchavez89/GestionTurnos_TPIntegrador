#include <iostream>
#include <cstring>
#include "Profesional.h"
#include <string>

using namespace std;

/// CONSTRUCTOR VACIO
Profesional::Profesional()
    : IdEspecialidad(0), Matricula(0), Consultorio(0), Honorario(0.00), DuracionTurno(0) { }

///CONSTRUCTOR CON SUS PARAMETROS
Profesional::Profesional(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado,
                         int idEspecialidad, int matricula, int consultorio, float honorario,int duracionTurno)
    : Persona(dni, nombre, apellido, fechaNacimiento, edad, direccion, telefono, genero, estado),
      IdEspecialidad(idEspecialidad), Matricula(matricula), Consultorio(consultorio),
      Honorario(honorario), DuracionTurno(duracionTurno) { }

///GETTERS
int Profesional::getIdEspecialidad()
{
    return IdEspecialidad;
}
int Profesional::getMatricula()
{
    return Matricula;
}
int Profesional::getConsultorio()
{
    return Consultorio;
}
float Profesional::getHonorario()
{
    return Honorario;
}
int Profesional::getDuracionTurno()
{
    return DuracionTurno;
}

///SETTERS
void Profesional::setIdEspecialidad(int idEspecialidad)
{
    IdEspecialidad = idEspecialidad;
}
void Profesional::setMatricula(int matricula)
{
    Matricula = matricula;
}
void Profesional::setConsultorio(int consultorio)
{
    Consultorio = consultorio;
}
void Profesional::setHonorario(float honorario)
{
    Honorario = honorario;
}
void Profesional::setDuracionTurno(int duracionTurno)
{
    DuracionTurno = duracionTurno;
}


