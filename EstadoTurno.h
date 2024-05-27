#pragma once
#include <string>

using namespace std;

class EstadoTurno
{
private:
    int IdEstadoTurno;
    char Descripcion[30];
public:
    /// CONSTRUCTOR
    EstadoTurno();
    EstadoTurno(int IdEstadoTurno, string descripcion);

    /// GETTERS
    int getIdEstadoTurno();
    string getDescripcion();

    /// SETTERS
    void setIdEstadoTurno(int idEstadoTurno);
    void setDescripcion(string descripcion);
};
