#include <iostream>
#include "Fecha.h"
#include "Utils.h"

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
    cout << endl;
    cout<<"Ingrese dia: ";
    cin>>Dia;
    while(!validarIngresoNros(Dia)){
        cout << "Ingrese dia: ";
        cin >> Dia;
    }
    while(Dia<0 || Dia>31 || Dia==0 || Dia ==00){
        cout<<"Dia inválido (01 a 31): ";
        cin>>Dia;
    }
    cout<<"Ingrese mes: ";
    cin>>Mes;
    while(!validarIngresoNros(Dia)){
        cout << "Ingrese mes: ";
        cin >> Mes;
    }
    while(Mes<=0 || Mes>12){
        cout<<"Mes inválido (01 a 12): ";
        cin>>Mes;
    }
    cout<<"Ingrese año: ";
    cin>>Anio;
    while(!validarIngresoNros(Anio)){
        cout << "Ingrese año: ";
        cin >> Anio;
    }
    while(Anio<1900){
        cout<<"Año inválido (solo mayor a 1900): ";
        cin>>Anio;
    }
}

bool Fecha::operator<(Fecha otra){
    if (Anio < otra.Anio) return true;
    if (Anio == otra.Anio && Mes < otra.Mes) return true;
    if (Anio == otra.Anio && Mes == otra.Mes && Dia < otra.Dia) return true;
    return false;
}

bool Fecha::operator<=(Fecha otra) {
    return (*this < otra) || (*this == otra);
}

bool Fecha::operator>(Fecha otra) {
    return !(*this <= otra);
}

bool Fecha::operator>=(Fecha otra) {
    return !(*this < otra);
}

bool Fecha::operator==(Fecha otra) {
    return (Dia == otra.Dia && Mes == otra.Mes && Anio == otra.Anio);
}
