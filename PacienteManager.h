#pragma once
#include "Paciente.h"
#include "PacienteArchivo.h"
#include "Utils.h"

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
    void buscarByDni(int dni);
    void buscarPorApellido(string apellido);
    void buscarPorCobertura(float cobertura);
};
