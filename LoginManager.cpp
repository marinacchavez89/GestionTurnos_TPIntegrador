#include <iostream>
using namespace std;
#include "LoginManager.h"

Login LoginManager::crear(){
    int legajo, user, pass;

    cout << "Legajo: ";
    cin >> legajo;

    cout << "User que tendr� el usuario (1: Admin - 2: User): ";
    cin >> user;

    cout << "Contrase�a (Solo n�meros): ";
    cin >> pass;

    return Login(legajo, user, pass, true);

}

void LoginManager::cargar(Login &login) {
    int legajo, user, pass;

    cout << "Legajo: ";
    cin >> legajo;
    login.setLegajo(legajo);

    cout << "User que tendr� el usuario (1: Admin - 2: User): ";
    cin >> user;
    login.setUser(user);

    cout << "Contrase�a (Solo n�meros): ";
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
        cout << "Constrase�a: " << login.getPass() << endl;
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
        cout << "�El usuario fue dado de alta con �xito!" << endl;
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

    for(int i=0; i<cantidad; i++)
    {
        if(logines[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrar(logines[i]);
            cout << "--------------------------" << endl;
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
    int user, index;
    Login login;

    cout << "Ingrese el n�mero de usuario: ";
    cin >> user;

    index = archiLogin.buscarByLegajo(user);

    if(index != -1)
    {
        login = archiLogin.leer(index);
        mostrar(login);
        cargar(login);
        if(archiLogin.guardar(index, login))
        {
            cout << "�Usuario modificado con �xito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el usuario." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el Usuario ingresado." << endl;
    }
}

void LoginManager::eliminar()
{
    int user, index;
    Login login;
    char eliminar;

    cout << "Ingrese el n�mero de usuario a eliminar: ";
    cin >> user;

    index = archiLogin.buscarByLegajo(user);

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
                cout << "�Se elimin� el usuario con �xito!" << endl;
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
        cout << "No se encuentra el n�mero de usuario ingresado." << endl;
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
