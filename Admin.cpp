#include <iostream>
#include "Admin.h"

using namespace std;

/// CONSTRUCTOR VACIO
Admin::Admin() : Dni(0), Rol(0)
{

}

/// CONSTRUCTOR CON PARAMETROS
Admin::Admin(int dni, int rol) : Dni(dni), Rol(rol)
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

