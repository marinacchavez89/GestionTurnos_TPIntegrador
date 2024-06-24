#pragma once
#include "EstadoTurno.h"

class EstadoTurnoArchivo {

private:

public:
    bool guardar(EstadoTurno registro);
    bool guardar(int index, EstadoTurno registro);
    EstadoTurno leer(int index);
    void leerTodos(EstadoTurno registros[], int cantidad);
    int buscarByID(int idEstadoTurno);
    int getCantidadRegistros();
};
