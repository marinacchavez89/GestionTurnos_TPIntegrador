#pragma once

class Login
{
private:
    int Legajo;
    int User; //1 admin / 2 - user
    int Pass;
    bool Estado;
public:
    ///CONSTRUCTOR VACIO
    Login();
    ///CONSTRUCTOR CON PARAMETROS
    Login(int legajo, int user, int pass, bool estado);
    ///GETTERS
    int getLegajo();
    int getUser();
    int getPass();
    bool getEstado();
    ///SETTERS
    void setLegajo(int legajo);
    void setUser(int user);
    void setPass(int pass);
    void setEstado(bool estado);
};
