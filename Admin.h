#pragma once

class Admin
{
private:
    int Dni;
    int Rol;
public:
    ///CONSTRUCTOR VACIO
    Admin();
    ///CONSTRUCTOR CON PARAMETROS
    Admin(int dni, int rol);
    ///GETTERS
    int getDni();
    int getRol();
    ///SETTERS
    void setDni(int dni);
    void setRol(int rol);
};
