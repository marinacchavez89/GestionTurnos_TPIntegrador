#include <iostream>
#include "EstadoTurno.h"
#include <cstring>

using namespace std;

/// CONSTRUCTOR VACIO
EstadoTurno::EstadoTurno()
    : IdEstadoTurno(0)
{
    strcpy(Descripcion, "");
}

/// CONSTRUCTOR CON PARAMETROS
EstadoTurno::EstadoTurno(int idEstadoTurno, string descripcion)
    : IdEstadoTurno(idEstadoTurno)
{
    setDescripcion(descripcion);
}

/// GETTERS
int EstadoTurno::getIdEstadoTurno()
{
    return IdEstadoTurno;
}

string EstadoTurno::getDescripcion()
{
    return Descripcion;
}

/// SETTERS
void EstadoTurno::setIdEstadoTurno(int idEstadoTurno)
{
    IdEstadoTurno = idEstadoTurno;
}

void EstadoTurno::setDescripcion(string descripcion)
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
