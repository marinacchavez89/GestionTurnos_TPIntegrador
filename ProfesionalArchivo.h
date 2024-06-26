#pragma once
#include "Profesional.h"

class ProfesionalArchivo {

private:

public:
    bool guardar(Profesional registro);
    bool guardar(int index, Profesional registro);
    Profesional leer(int index);
    void leerTodos(Profesional registros[], int cantidad);
    int buscarByMatricula(int mat);
    int buscarByDni(int dni);
    int getCantidadRegistros();
};
