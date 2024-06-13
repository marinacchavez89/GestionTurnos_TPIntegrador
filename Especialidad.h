#pragma once
#include <string>

using namespace std;

class Especialidad
{
private:
    int IdEspecialidad;
    char Descripcion[30];
    bool Estado;
public:
    /// CONSTRUCTOR
    Especialidad();
    Especialidad(int idEspecialidad, string descripcion, bool estado);

    /// GETTERS
    int getIdEspecialidad();
    string getDescripcion();
    bool getEstado();

    /// SETTERS
    void setIdEspecialidad(int idEspecialidad);
    void setDescripcion(string descripcion);
    void setEstado(bool estado);
};
