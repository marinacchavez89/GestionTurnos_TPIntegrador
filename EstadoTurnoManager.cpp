#include <iostream>
using namespace std;
#include "EstadoTurnoManager.h"

EstadoTurno EstadoTurnoManager::crear(){
    int idEstadoTurno;
    string descripcion;

    cout << "ID estado del turno: ";
    cin >> idEstadoTurno;

    cout << "Descripci�n: ";
    cin.ignore();
    getline(cin, descripcion);

    return EstadoTurno(idEstadoTurno, descripcion, true);
}

void EstadoTurnoManager::cargar(EstadoTurno &estadoTurno) {
    int idEstadoTurno;
    string descripcion;

    cout << "ID estado del turno: ";
    cin >> idEstadoTurno;
    estadoTurno.setIdEstadoTurno(idEstadoTurno);

    cout << "Descripci�n: ";
    cin.ignore();
    getline(cin, descripcion);
    estadoTurno.setDescripcion(descripcion);

    estadoTurno.setEstado(true);

}

void EstadoTurnoManager::mostrar(EstadoTurno estadoTurno)
{
    if (estadoTurno.getEstado())
    {
        cout << "ID estado del turno: " << estadoTurno.getIdEstadoTurno() << endl;
        cout << "Descripci�n: " << estadoTurno.getDescripcion() << endl;
    }
}

void EstadoTurnoManager::agregar()
{
    EstadoTurno nuevoEstadoTurno = crear();

    if (archiEstadoTurno.buscarByID(nuevoEstadoTurno.getIdEstadoTurno()) != -1) {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiEstadoTurno.guardar(nuevoEstadoTurno)) {
        cout << "�El estado del turno fue guardado con �xito!" << endl;
    } else {
        cout << "No se pudo guardar el estado del turno." << endl;
    }
}

void EstadoTurnoManager::listar()
{
    int cantidad = archiEstadoTurno.getCantidadRegistros();
    EstadoTurno *estadoTurnos;

    estadoTurnos = new EstadoTurno[cantidad];

    if(estadoTurnos == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiEstadoTurno.leerTodos(estadoTurnos, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(estadoTurnos[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrar(estadoTurnos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] estadoTurnos;
}
void EstadoTurnoManager::modificar()
{
    int idEstadoTurno, index;
    EstadoTurno estadoTurno;

    cout << "Ingrese el n�mero de ID a modificar: ";
    cin >> idEstadoTurno;

    index = archiEstadoTurno.buscarByID(idEstadoTurno);

    if(index != -1)
    {
        estadoTurno = archiEstadoTurno.leer(index);
        mostrar(estadoTurno);
        cargar(estadoTurno);
        if(archiEstadoTurno.guardar(index, estadoTurno))
        {
            cout << "�Estado de turno modificado con �xito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el estado del turno." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el ID del estado del turno ingresado." << endl;
    }
}

void EstadoTurnoManager::eliminar()
{
    int idEstadoTurno, index;
    EstadoTurno estadoTurno;
    char eliminar;

    cout << "Ingrese el ID del estado del turno a eliminar: ";
    cin >> idEstadoTurno;

    index = archiEstadoTurno.buscarByID(idEstadoTurno);

    if(index != -1)
    {
        estadoTurno = archiEstadoTurno.leer(index);

        mostrar(estadoTurno);

        cout << "Esta seguro de eliminar el estado del turno? S/N ";
        cin >> eliminar;

        if(eliminar == 'S' || eliminar == 's')
        {
            estadoTurno.setEstado(false);

            if(archiEstadoTurno.guardar(index, estadoTurno))
            {
                cout << "�Se elimin� con �xito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el estado del turno." << endl;
            }
        }
        else
        {
            cout << "El estado del turno no fue eliminado." << endl;

        }
    }
    else
    {
        cout << "No se encuentra el ID del estado del turno ingresado." << endl;
    }
}
