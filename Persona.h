#pragma once
#include <cstring>
#include "Fecha.h"

class Persona
{
private:
    int Dni;
    char Nombre[50];
    char Apellido[50];
    Fecha FechaNacimiento;
    int Edad;
    char Direccion[50];
    char Telefono[18];
    char Genero;
    bool Estado;
public:
    ///CONSTRUCTORES
    Persona();
    Persona(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado);
    ///SETTERS
    void setDni(int dni);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setEdad(int edad);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void setGenero(char genero);
    void setEstado(bool estado);
    ///GETTERS
    int getDni();
    string getNombre();
    string getApellido();
    Fecha getFechaNacimiento();
    int getEdad();
    string getDireccion();
    string getTelefono();
    char getGenero();
    bool getEstado();
};
