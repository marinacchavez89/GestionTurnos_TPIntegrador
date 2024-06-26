#include <iostream>
using namespace std;
#include "EspecialidadManager.h"

Especialidad EspecialidadManager::crear(){
    int idEspecialidad;
    string descripcion;

    cout << "ID Especialidad: ";
    cin >> idEspecialidad;

    cout << "Descripci�n: ";
    cin.ignore();
    getline(cin, descripcion);

    return Especialidad(idEspecialidad, descripcion, true);

}

void EspecialidadManager::cargar(Especialidad &espe) {
    int idEspecialidad;
    string descripcion;

    cout << "ID Especialidad: ";
    cin >> idEspecialidad;
    espe.setIdEspecialidad(idEspecialidad);

    cout << "Descripci�n: ";
    cin.ignore();
    getline(cin, descripcion);
    espe.setDescripcion(descripcion);

    espe.setEstado(true);

}

void EspecialidadManager::mostrar(Especialidad espe)
{
    if (espe.getEstado())
    {
        cout << "ID especialidad: " << espe.getIdEspecialidad() << endl;
        cout << "Descripci�n: " << espe.getDescripcion() << endl;
    }
}

void EspecialidadManager::agregar()
{
    Especialidad nuevaEspecialidad = crear();

    if (archiEspe.buscarByID(nuevaEspecialidad.getIdEspecialidad()) != -1) {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiEspe.guardar(nuevaEspecialidad)) {
        cout << "�La especialidad fue guardada con �xito!" << endl;
    } else {
        cout << "No se pudo guardar la especialidad." << endl;
    }
}

void EspecialidadManager::listar()
{
    int cantidad = archiEspe.getCantidadRegistros();
    Especialidad *especialidades;

    especialidades = new Especialidad[cantidad];

    if(especialidades == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiEspe.leerTodos(especialidades, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(especialidades[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrar(especialidades[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] especialidades;
}

void EspecialidadManager::modificar()
{
    int idEspecialidad, index;
    Especialidad especialidad;

    cout << "Ingrese el n�mero de ID a modificar: ";
    cin >> idEspecialidad;

    index = archiEspe.buscarByID(idEspecialidad);

    if(index != -1)
    {
        especialidad = archiEspe.leer(index);
        mostrar(especialidad);
        cargar(especialidad);
        if(archiEspe.guardar(index, especialidad))
        {
            cout << "�Especialidad modificada con �xito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar la especialidad." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el ID de la especialidad ingresada." << endl;
    }
}

void EspecialidadManager::eliminar()
{
    int idEspecialidad, index;
    Especialidad especialidad;
    char eliminar;

    cout << "Ingrese el ID de la especialidad a eliminar: ";
    cin >> idEspecialidad;

    index = archiEspe.buscarByID(idEspecialidad);

    if(index != -1)
    {
        especialidad = archiEspe.leer(index);

        mostrar(especialidad);

        cout << "Esta seguro de eliminar la especialiad? S/N ";
        cin >> eliminar;

        if(eliminar == 'S' || eliminar == 's')
        {
            especialidad.setEstado(false);

            if(archiEspe.guardar(index, especialidad))
            {
                cout << "�Se elimin� con �xito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar la especialidad." << endl;
            }
        }
        else
        {
            cout << "La especialidad no fue eliminada." << endl;

        }
    }
    else
    {
        cout << "No se encuentra el ID de la especialidad ingresado." << endl;
    }
}


