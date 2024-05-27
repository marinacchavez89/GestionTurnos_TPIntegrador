#pragma once
#include <string>

using namespace std;

class Especialidad
{
private:
    int IdEspecialidad;
    char Descripcion[30];
public:
    /// CONSTRUCTOR
    Especialidad();
    Especialidad(int idEspecialidad, string descripcion);

    /// GETTERS
    int getIdEspecialidad();
    string getDescripcion();

    /// SETTERS
    void setIdEspecialidad(int idEspecialidad);
    void setDescripcion(string descripcion);
};
