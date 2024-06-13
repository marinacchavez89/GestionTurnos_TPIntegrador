#include <iostream>
#include "Admin.h"

using namespace std;

/// CONSTRUCTOR VACIO
Admin::Admin() : Dni(0), Rol(0), Estado()
{

}

/// CONSTRUCTOR CON PARAMETROS
Admin::Admin(int dni, int rol, bool estado) : Dni(dni), Rol(rol), Estado(estado)
{

}
/// GETTERS

int Admin::getDni()
{
    return Dni;
}
int Admin::getRol()
{
    return Rol;
}
bool Admin::getEstado()
{
    return Estado;
}
///SETTERS
void Admin:: setDni(int dni)
{
    if(dni > 0)
    {
        Dni = dni;
    }
    else
    {
        Dni = 0;
    }
}
void Admin:: setRol(int rol)
{
    if(rol >=0 || rol <=1)
    {
        Rol = rol;
    }
    else
    {
        Rol = 0;
    }
}

void Admin::setEstado(bool estado)
{
    Estado = estado;
}

