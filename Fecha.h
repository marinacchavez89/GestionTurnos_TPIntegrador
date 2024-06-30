#pragma once
#include <string>

using namespace std;

class Fecha
{
private:
    int Dia, Mes, Anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    string toString();
    void cargar();

    bool operator<(Fecha otra);
    bool operator<=(Fecha otra);
    bool operator>(Fecha otra);
    bool operator>=(Fecha otra);
    bool operator==(Fecha otra);
};
