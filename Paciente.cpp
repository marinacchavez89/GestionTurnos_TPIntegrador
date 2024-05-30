#include "Paciente.h"
#include <cstring>
#include <iostream>

/// CONSTRUCTOR VACIO
Paciente::Paciente()
    : NroHistoriaClinica(0), PorcCobertura(0)
{
    strcpy(Email, "");
}

///CONSTRUCTOR CON SUS PARAMETROS
Paciente::Paciente(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado,
                   int nroHistoriaClinica, float porcCobertura, string email)
    : Persona(dni, nombre, apellido, fechaNacimiento, edad, direccion, telefono, genero, estado),
      NroHistoriaClinica(nroHistoriaClinica), PorcCobertura(porcCobertura)
{
    setEmail(email);
}


///GETTERS
int Paciente::getNroHistoriaClinica()
{
    return NroHistoriaClinica;
}
float Paciente::getPorcCobertura()
{
    return PorcCobertura;
}
string Paciente::getEmail()
{
    return Email;
}

///SETTERS
void Paciente::setNroHistoriaClinica(int nroHistoriaClinica)
{
    NroHistoriaClinica = nroHistoriaClinica;
}
void Paciente::setPorcCobertura(float porcCobertura)
{
    PorcCobertura = porcCobertura;
}
void Paciente::setEmail(string email)
{
    if(email.size() <= 50)
    {
        strcpy(Email, email.c_str());
    }
    else
    {
        strcpy(Email, "SIN DATOS");
    }
}
