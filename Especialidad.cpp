#include <iostream>
#include "Especialidad.h"
#include <cstring>

using namespace std;

/// CONSTRUCTOR VACIO
Especialidad::Especialidad()
    : IdEspecialidad(0), Estado()
{
    strcpy(Descripcion, "");
}

/// CONSTRUCTOR CON PARAMETROS
Especialidad::Especialidad(int idEspecialidad, string descripcion, bool estado)
    : IdEspecialidad(idEspecialidad), Estado(estado)
{
    setDescripcion(descripcion);
}

/// GETTERS
int Especialidad::getIdEspecialidad()
{
    return IdEspecialidad;
}

string Especialidad::getDescripcion()
{
    return Descripcion;
}

bool Especialidad::getEstado()
{
    return Estado;
}

/// SETTERS
void Especialidad::setIdEspecialidad(int idEspecialidad)
{
    IdEspecialidad = idEspecialidad;
}

void Especialidad::setDescripcion(string descripcion)
{
    if (descripcion.size() < 30)
    {
        strcpy(Descripcion, descripcion.c_str());
    }
    else
    {
        strcpy(Descripcion, "SIN DATOS");
    }
}

void Especialidad::setEstado(bool estado)
{
    Estado = estado;
}

