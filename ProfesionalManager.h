#pragma once
#include "Profesional.h"
#include "ProfesionalArchivo.h"

class ProfesionalManager {

private:
    ProfesionalArchivo archiProf;

public:
    Profesional crear();
    void cargar(Profesional &registro);
    void mostrar(Profesional registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
};
