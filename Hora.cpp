#include "Hora.h"
#include <iostream>
#include <string>
using namespace std;

/// Constructor por defecto
Hora::Hora() : Horas(0), Minutos(0) { }

/// Constructor con par�metros
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
    cout << "Ingrese hora (Formato - hh):";
    cin >> horas;
    if(horas >= 0 && horas <= 23)
    {
        setHoras(horas);
    }
    else
    {
        cout << "Ingrese hora v�lida (de 00 a 23):";
        cin >> horas;
        setHoras(horas);
    }

    cout << "Ingrese minutos (Formato - mm):";
    cin >> minutos;
    if(minutos >=0 && minutos <= 59)
    {
        setMinutos(minutos);
    }
    else
    {
        cout << "Ingrese minutos v�lidos (de 00 a 59):";
        cin >> minutos;
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

