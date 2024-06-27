#pragma once
#include "Turno.h"

class TurnoArchivo {

private:

public:
    bool guardar(Turno registro);
    bool guardar(int index, Turno registro);
    Turno leer(int index);
    void leerTodos(Turno registros[], int cantidad);
    int buscarByID(int idTurno);
    int getCantidadRegistros();
};
