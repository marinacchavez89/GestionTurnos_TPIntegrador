#pragma once
#include "Paciente.h"
#include "PacienteArchivo.h"

class PacienteManager {

private:
    PacienteArchivo archiPacientes;

public:
    Paciente crear();
    void cargar(Paciente &registro);
    void mostrar(Paciente registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
};
