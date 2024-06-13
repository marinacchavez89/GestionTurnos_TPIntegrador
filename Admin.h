#pragma once

class Admin
{
private:
    int Dni;
    int Rol;
    bool Estado;
public:
    ///CONSTRUCTOR VACIO
    Admin();
    ///CONSTRUCTOR CON PARAMETROS
    Admin(int dni, int rol, bool estado);
    ///GETTERS
    int getDni();
    int getRol();
    bool getEstado();
    ///SETTERS
    void setDni(int dni);
    void setRol(int rol);
    void setEstado(bool estado);
};
