#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
{
    Dia= 1;
    Mes = 1;
    Anio = 1;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    Dia = dia;
    Mes = mes;
    Anio = anio;
}

int Fecha::getDia()
{
    return Dia;
}

int Fecha::getMes()
{
    return Mes;
}

int Fecha::getAnio()
{
    return Anio;
}

void Fecha::setDia(int dia)
{
    Dia = dia;
}

void Fecha::setMes(int mes)
{
    Mes = mes;
}

void Fecha::setAnio(int anio)
{
    Anio = anio;
}

string Fecha::toString()
{
    return to_string(Dia) + "/" + to_string(Mes) + "/" + to_string(Anio);
}

void Fecha::cargar()
{
    cout<<"Ingrese dia: ";
    cin>>Dia;
    cout<<"Ingrese mes: ";
    cin>>Mes;
    cout<<"Ingrese anio: ";
    cin>>Anio;
}

bool Fecha::operator<(Fecha otra){
    if (Anio < otra.Anio) return true;
    if (Anio == otra.Anio && Mes < otra.Mes) return true;
    if (Anio == otra.Anio && Mes == otra.Mes && Dia < otra.Dia) return true;
    return false;
}

bool Fecha::operator==(Fecha otra) {
    return (Dia == otra.Dia && Mes == otra.Mes && Anio == otra.Anio);
}
