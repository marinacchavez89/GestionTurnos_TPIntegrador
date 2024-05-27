#include <iostream>
#include "Especialidad.h"
#include <cstring>

using namespace std;

/// CONSTRUCTOR VACIO
Especialidad::Especialidad()
    : IdEspecialidad(0)
{
    strcpy(Descripcion, "");
}

/// CONSTRUCTOR CON PARAMETROS
Especialidad::Especialidad(int idEspecialidad, string descripcion)
    : IdEspecialidad(idEspecialidad)
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

