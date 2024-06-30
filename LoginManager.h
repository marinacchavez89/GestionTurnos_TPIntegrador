#pragma once
using namespace std;
#include <iostream>
#include <cstring>
#include "Login.h"
#include "LoginArchivo.h"

class LoginManager {

private:
    LoginArchivo archiLogin;

public:
    Login crear();
    void cargar(Login &registro);
    void mostrar(Login registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
    Login listar(int legajo);
    string descripcionTipoUsuario(int user);
};
