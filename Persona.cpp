#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;


Persona::Persona()
    :   FechaNacimiento(1,1,1)
{
    Dni = 0;
    strcpy(Nombre, "");
    strcpy(Apellido, "");
    Edad = 0;
    strcpy(Direccion, "");
    strcpy(Telefono, "");
    Genero = 'M';
    Estado = true;
}

Persona::Persona(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado)
{
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
    setEdad(edad);
    setDireccion(direccion);
    setTelefono(telefono);
    setGenero(genero);
    setEstado(estado);
}

void Persona::setDni(int dni)
{
    if(dni > 0)
    {
        Dni = dni;
    }
    else
    {
        cout << "No se ingresó un valor de DNI correcto. Intente nuevamente." << endl;
    }
}

int Persona::getDni()
{
    return Dni;
}

void Persona::setNombre(string nombre)
{
    if(nombre.size() <= 50)
    {
        strcpy(Nombre, nombre.c_str());
    }
    else
    {
        strcpy(Nombre, "SIN DATOS");
    }
}

string Persona::getNombre()
{
    return Nombre;
}

void Persona::setApellido(string apellido)
{
    if(apellido.size() <= 50)
    {
        strcpy(Apellido, apellido.c_str());
    }
    else
    {
        strcpy(Apellido, "SIN DATOS");
    }
}

string Persona::getApellido()
{
    return Apellido;
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    FechaNacimiento = fechaNacimiento;
}

Fecha Persona::getFechaNacimiento()
{
    return FechaNacimiento;
}

void Persona::setEdad(int edad)
{
    Edad = edad;
}

int Persona::getEdad()
{
    return Edad;
}

void Persona::setDireccion(string direccion)
{
    if(direccion.size() <= 50)
    {
        strcpy(Direccion, direccion.c_str());
    }
    else
    {
        strcpy(Direccion, "SIN DATOS");
    }
}

string Persona::getDireccion()
{
    return Direccion;
}

void Persona::setTelefono(string telefono)
{
    if(telefono.size() <= 18)
    {
        strcpy(Telefono, telefono.c_str());
    }
    else
    {
        strcpy(Telefono, "SIN DATOS");
    }
}

string Persona::getTelefono()
{
    return Telefono;
}

void Persona::setGenero(char genero)
{
    Genero = genero;
}

char Persona::getGenero()
{
    return Genero;
}

void Persona::setEstado(bool estado)
{
    Estado = estado;
}

bool Persona::getEstado()
{
    return Estado;
}


