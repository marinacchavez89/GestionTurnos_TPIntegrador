#include "Hora.h"
#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;

/// Constructor por defecto
Hora::Hora() : Horas(0), Minutos(0) { }

/// Constructor con parámetros
Hora::Hora(int horas, int minutos) : Horas(horas), Minutos(minutos) { }

/// GETTERS
int Hora::getHoras()
{
    return Horas;
}

int Hora::getMinutos()
{
    return Minutos;
}

/// SETTERS
void Hora::setHoras(int horas)
{
    Horas = horas;
}

void Hora::setMinutos(int minutos)
{
    Minutos = minutos;
}

void Hora::cargar()
{
    int horas, minutos;
    cout << endl;
    cout << "Ingrese hora (Formato - hh):";
    cin >> horas;
    while(!validarIngresoNros(horas)){
        cout << "Ingrese hora (Formato: hh - Solo números):";
        cin >> horas;
    }
    if(horas >= 0 && horas <= 23)
    {
        setHoras(horas);
    }
    else
    {
        cout << "Ingrese hora válida (de 00 a 23):";
        cin >> horas;
        while(!validarIngresoNros(horas)){
        cout << "Ingrese hora (Formato: hh - Solo números):";
        cin >> horas;
        }
        setHoras(horas);
    }

    cout << "Ingrese minutos (Formato - mm):";
    cin >> minutos;
    while(!validarIngresoNros(minutos)){
        cout << "Ingrese minutos (Formato: mm - Solo números):";
        cin >> minutos;
    }
    if(minutos >=0 && minutos <= 59)
    {
        setMinutos(minutos);
    }
    else
    {
        cout << "Ingrese minutos válidos (de 00 a 59):";
        cin >> minutos;
        while(!validarIngresoNros(minutos)){
        cout << "Ingrese minutos (Formato: mm - Solo números):";
        cin >> minutos;
        }
        setMinutos(minutos);
    }

}

string Hora::toString()
{
    if(Minutos!=0)
    {
        return to_string(Horas) + ":" + to_string(Minutos) + " h.";
    }
    else
    {
        return to_string(Horas) + ":00 h.";
    }

}

bool Hora::operator<(Hora otra)
{
    if (Horas < otra.Horas)
    {
        return true;
    }
    if (Horas == otra.Horas && Minutos < otra.Minutos)
    {
        return true;
    }
    return false;
}

bool Hora::operator<=(Hora otra)
{
    return Horas < otra.Horas || Horas == otra.Horas;
}

bool Hora::operator>(Hora otra)
{
    return !(Horas <= otra.Horas);
}

bool Hora::operator>=(Hora otra)
{
    return !(Horas < otra.Horas);
}

bool Hora::operator==(Hora otra)
{
    return (Horas == otra.Horas && Minutos == otra.Minutos);
}

