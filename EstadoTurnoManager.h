#pragma once
#include "EstadoTurno.h"
#include "EstadoTurnoArchivo.h"

class EstadoTurnoManager {

private:
    EstadoTurnoArchivo archiEstadoTurno;

public:
    EstadoTurno crear();
    void cargar(EstadoTurno &registro);
    void mostrar(EstadoTurno registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
};
