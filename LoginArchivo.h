#pragma once
#include "Login.h"

class LoginArchivo {

private:

public:
    bool guardar(Login registro);
    bool guardar(int index, Login registro);
    Login leer(int index);
    void leerTodos(Login registros[], int cantidad);
    int buscarByLegajo(int legajo);
    int getCantidadRegistros();
};

