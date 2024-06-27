#pragma once
#include <string>
using namespace std;
class Hora
{
private:
    int Horas;
    int Minutos;
public:
    ///CONSTRUCTOR VACIO
    Hora();
    ///CONSTRUCTOR CON PARAMETROS
    Hora(int horas, int minutos);
    ///GETTERS
    int getHoras();
    int getMinutos();
    ///SETTERS
    void setHoras(int horas);
    void setMinutos(int minutos);

    /// METODOS
    void cargar();
    string toString();
    bool operator<(Hora otra);
    bool operator>(Hora otra);
    bool operator<=(Hora otra);
    bool operator>=(Hora otra);
    bool operator==(Hora otra);

};
