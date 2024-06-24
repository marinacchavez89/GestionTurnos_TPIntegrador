#pragma once
#include "HorariosProfesionales.h"
#include "HorariosProfesionalesArchivo.h"

class HorariosProfesionalesManager {

private:
    HorariosProfesionalesArchivo archiHorarios;

public:
    HorariosProfesionales crear();
    void cargar(HorariosProfesionales &registro);
    void mostrar(HorariosProfesionales registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
};
