#include <iostream>
#include "Login.h"

using namespace std;

/// CONSTRUCTOR VACIO
Login::Login() : Legajo(), User(), Pass(), Estado()
{

}

/// CONSTRUCTOR CON PARAMETROS
Login::Login(int legajo, int user, int pass, bool estado) : Legajo (legajo), User(user), Pass(pass), Estado(estado)
{

}
/// GETTERS
int Login::getLegajo()
{
    return Legajo;
}

int Login::getUser()
{
    return User;
}
int Login::getPass()
{
    return Pass;
}
bool Login::getEstado()
{
    return Estado;
}
///SETTERS
void Login:: setLegajo(int legajo)
{
    Legajo = legajo;
}
void Login:: setUser(int user)
{
    User = user;
}
void Login:: setPass(int pass)
{
    Pass = pass;
}

void Login::setEstado(bool estado)
{
    Estado = estado;
}

