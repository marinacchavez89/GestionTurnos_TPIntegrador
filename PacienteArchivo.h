#pragma once
#include "Paciente.h"

class PacienteArchivo{
    private:

    public:
        bool guardar(Paciente registro);
        bool guardar(int index, Paciente registro);
        Paciente leer(int index);
        void leerTodos(Paciente registros[], int cantidad);
        int buscarByDni(int dni);
        int getCantidadRegistros();
};
