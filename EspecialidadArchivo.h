#pragma once
#include "Especialidad.h"

class EspecialidadArchivo {

private:

public:
    bool guardar(Especialidad registro);
    bool guardar(int index, Especialidad registro);
    Especialidad leer(int index);
    void leerTodos(Especialidad registros[], int cantidad);
    int buscarByID(int idEspecialidad);
    int getCantidadRegistros();
};
