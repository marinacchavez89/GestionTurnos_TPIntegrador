#pragma once
#include "HorariosProfesionales.h"

class HorariosProfesionalesArchivo {
public:
    bool guardar(HorariosProfesionales registro);
    bool guardar(int index, HorariosProfesionales registro);
    HorariosProfesionales leer(int index);
    void leerTodos(HorariosProfesionales registros[], int cantidad);
    int buscarByMatricula(int matricula);
    int getCantidadRegistros();
    HorariosProfesionales* buscarTodosByMatricula(int matricula, int &cantidad);
};
