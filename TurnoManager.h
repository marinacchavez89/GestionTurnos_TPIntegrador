#pragma once
#include "Turno.h"
#include "TurnoArchivo.h"

class TurnoManager {

private:
    TurnoArchivo archiTurno;

public:
    Turno crear();
    void cargar(Turno &registro);
    void mostrar(Turno registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
    string estadoTurnoToString(int idEstadoTurno);
};