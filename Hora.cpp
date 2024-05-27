#include <iostream>
#include "Hora.h"
using namespace std;

///USAMOS EL CONSTRUCTOR DEFAULT
Hora::Hora() : Horas(0), Minutos(0)
{

}

/// CONSTRUCTOR CON PARAMETROS
Hora::Hora(int horas, int minutos) : Horas(horas), Minutos(minutos)
{

}
/// GETTERS

int Hora::getHoras()
{
    return Horas;
}
int Hora::getMinutos()
{
    return Minutos;
}
///SETTERS
void Hora:: setHoras(int horas)
{
    if(horas < 24 && horas >= 0)
    {
        Horas = horas;
    }
    else
    {
        Horas = 0; ///SI LLEGASE LA HORA A SER INVALIDA LE ASIGNAMOS 0
    }
}
void Hora:: setMinutos(int minutos)
{
    if(minutos < 60 && minutos >=0)
    {
        Minutos = minutos;
    }
    else
    {
        Minutos = 0; /// LE ASIGNAMOS MINUTOS EN 0 SI SE CARGA ERRONEAMENTE.
    }
}
