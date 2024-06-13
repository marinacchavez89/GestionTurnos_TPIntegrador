#pragma once
#include "Especialidad.h"
#include "EspecialidadArchivo.h"

class EspecialidadManager {

private:
    EspecialidadArchivo archiEspe;

public:
    Especialidad crear();
    void cargar(Especialidad &registro);
    void mostrar(Especialidad registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
};
