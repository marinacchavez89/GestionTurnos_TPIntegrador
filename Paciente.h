#pragma once
#include "Persona.h"
#include <string>
#include "Hora.h"

using namespace std;

class Paciente: public Persona
{
private:
    int NroHistoriaClinica;
    float PorcCobertura;
    char Email[50];
public:
    /// CONSTRUCTOR
    Paciente();
    Paciente(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado,
             int nroHistoriaClinica, float porcCobertura, string email);

    /// GETTERS
    int getNroHistoriaClinica();
    float getPorcCobertura();
    string getEmail();

    ///SETTERS
    void setNroHistoriaClinica(int nroHistoriaClinica);
    void setPorcCobertura(float porcCobertura);
    void setEmail(string email);

};
