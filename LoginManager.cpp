#include <iostream>
using namespace std;
#include "LoginManager.h"
#include "Utils.h"

Login LoginManager::crear(){
    int legajo, user, pass;

    cout << "Legajo: ";
    cin >> legajo;
    while(!validarIngresoNros(legajo)){
        cout << "Legajo (solo números): ";
        cin >> legajo;
    }

    cout << "User que tendrá el usuario (1: Admin - 2: User): ";
    cin >> user;
    while(!validarIngresoNros(user) || (user != 1 && user != 2)){
        cout << "El usuario solo puede ser 1: Admin - 2: User. Ingrese nuevamente: ";
        cin >> user;
    }

    cout << "Contraseña: ";
    cin >> pass;
    while(!validarIngresoNros(pass)){
        cout << "Contraseña (solo números): ";
        cin >> pass;
    }

    return Login(legajo, user, pass, true);

}

void LoginManager::cargar(Login &login) {
    int legajo, user, pass;

    cout << "Legajo: ";
    cin >> legajo;
    login.setLegajo(legajo);

    cout << "User que tendrá el usuario (1: Admin - 2: User): ";
    cin >> user;
    login.setUser(user);

    cout << "Contraseña (Solo números): ";
    cin >> pass;
    login.setPass(pass);

    login.setEstado(true);

}

void LoginManager::mostrar(Login login)
{
    if (login.getEstado())
    {
        cout << "Legajo: " << login.getLegajo() << endl;
        cout << "Usuario: " << descripcionTipoUsuario(login.getUser()) << endl;
        cout << "Constraseña: " << login.getPass() << endl;
    }
}

void LoginManager::agregar()
{
    Login nuevoLogin= crear();

    if (archiLogin.buscarByLegajo(nuevoLogin.getLegajo()) != -1) {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiLogin.guardar(nuevoLogin)) {
        cout << "¡El usuario fue dado de alta con éxito!" << endl;
    } else {
        cout << "No se pudo dar de alta el usuario." << endl;
    }
}

void LoginManager::listar()
{
    int cantidad = archiLogin.getCantidadRegistros();
    Login *logines;

    logines = new Login[cantidad];

    if(logines == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiLogin.leerTodos(logines, cantidad);
    system("cls");
    cout << "********************************************************************************" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                              LISTADO USUARIOS                                |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "********************************************************************************" << endl;

    for(int i=0; i<cantidad; i++)
    {
        if(logines[i].getEstado())
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            mostrar(logines[i]);
        }
    }

    delete [] logines;
}

Login LoginManager::listar(int legajo)
{
    Login reg;
    int cantidad = archiLogin.getCantidadRegistros();
    Login *logines;

    logines = new Login[cantidad];

    if(logines == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return reg;
    }

    archiLogin.leerTodos(logines, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        reg = archiLogin.leer(i);
        if(logines[i].getEstado() && logines[i].getLegajo()==legajo)
        {
            reg = logines[i];
            delete [] logines;
            return reg;
        }
    }

    delete [] logines;
    reg.setUser(-1);
    return reg;
}

void LoginManager::modificar()
{
    int legajo, index;
    Login login;

    cout << "Ingrese el número de legajo del usuario a modificar: ";
    cin >> legajo;
    while(!validarIngresoNros(legajo)){
        cout << "Ingrese el número de usuario (solo números): ";
        cin >> legajo;
    }

    index = archiLogin.buscarByLegajo(legajo);

    if(index != -1)
    {
        login = archiLogin.leer(index);
        mostrar(login);
        cargar(login);
        if(archiLogin.guardar(index, login))
        {
            cout << "¡Usuario modificado con éxito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el usuario." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el usuario ingresado." << endl;
    }
}

void LoginManager::eliminar()
{
    int legajo, index;
    Login login;
    char eliminar;

    cout << "Ingrese el número de legajo del usuario a eliminar: ";
    cin >> legajo;
    while(!validarIngresoNros(legajo)){
        cout << "Legajo a eliminar (solo números): ";
        cin >> legajo;
    }

    index = archiLogin.buscarByLegajo(legajo);

    if(index != -1)
    {
        login = archiLogin.leer(index);

        mostrar(login);

        cout << "Esta seguro de eliminar la especialiad? S/N ";
        cin >> eliminar;

        if(eliminar == 'S' || eliminar == 's')
        {
            login.setEstado(false);

            if(archiLogin.guardar(index, login))
            {
                cout << "¡Se eliminó el usuario con éxito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el usuario." << endl;
            }
        }
        else
        {
            cout << "El usuario no fue eliminado." << endl;

        }
    }
    else
    {
        cout << "No se encuentra el número de usuario ingresado." << endl;
    }
}

string LoginManager::descripcionTipoUsuario(int user){

    string descTipoUser = "";
    if(user==1){
        descTipoUser = "Administrador.";
    }
    else if(user==2){
        descTipoUser = "Usuario sin permisos.";
    }

    return descTipoUser;
}
