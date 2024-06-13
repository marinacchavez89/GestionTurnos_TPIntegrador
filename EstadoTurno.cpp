#include <iostream>
#include "EstadoTurno.h"
#include <cstring>

using namespace std;

/// CONSTRUCTOR VACIO
EstadoTurno::EstadoTurno()
    : IdEstadoTurno(0), Estado()
{
    strcpy(Descripcion, "");
}

/// CONSTRUCTOR CON PARAMETROS
EstadoTurno::EstadoTurno(int idEstadoTurno, string descripcion, bool estado)
    : IdEstadoTurno(idEstadoTurno), Estado(estado)
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

bool EstadoTurno::getEstado()
{
    return Estado;
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

void EstadoTurno::setEstado(bool estado)
{
    Estado = estado;
}
