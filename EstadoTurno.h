#pragma once
#include <string>

using namespace std;

class EstadoTurno
{
private:
    int IdEstadoTurno;
    char Descripcion[30];
    bool Estado;
public:
    /// CONSTRUCTOR
    EstadoTurno();
    EstadoTurno(int IdEstadoTurno, string descripcion, bool estado);

    /// GETTERS
    int getIdEstadoTurno();
    string getDescripcion();
    bool getEstado();

    /// SETTERS
    void setIdEstadoTurno(int idEstadoTurno);
    void setDescripcion(string descripcion);
    void setEstado(bool estado);
};
