#include <iostream>
using namespace std;
#include "PacienteManager.h"

Paciente PacienteManager::crear(){

    int dni, edad, nroHistoriaClinica;
    string nombre, apellido, direccion, telefono, email;
    char genero;
    float porcCobertura;
    Fecha fecha;

    cout << "DNI: ";
    cin >> dni;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Apellido: ";
    getline(cin, apellido);

    cout << "Fecha de nacimiento: ";
    fecha.cargar();

    cout << "Edad: ";
    cin >> edad;

    cout << "Direccion: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Telefono: ";
    getline(cin, telefono);

    cout << "Genero: ";
    cin >> genero;

    cout << "Porcentaje de cobertura: ";
    cin >> porcCobertura;

    cout << "N�mero de historia cl�nica: ";
    cin >> nroHistoriaClinica;

    cout << "Email: ";
    cin.ignore();
    getline(cin, email);


    return Paciente(dni, nombre, apellido, fecha, edad, direccion, telefono, genero, true, ///TRUE HACE REFERENCIA AL ESTADO DE PERSONA
                       porcCobertura, nroHistoriaClinica, email);

}

void PacienteManager::cargar(Paciente &paciente) {
    int dni, edad, nroHistoriaClinica;
    string nombre, apellido, direccion, telefono, email;
    char genero;
    float porcCobertura;
    Fecha fecha;

    cout << "DNI: ";
    cin >> dni;
    paciente.setDni(dni);

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    paciente.setNombre(nombre);

    cout << "Apellido: ";
    getline(cin, apellido);
    paciente.setApellido(apellido);

    cout << "Fecha de nacimiento: ";
    fecha.cargar();
    paciente.setFechaNacimiento(fecha);

    cout << "Edad: ";
    cin >> edad;
    paciente.setEdad(edad);

    cout << "Direccion: ";
    cin.ignore();
    getline(cin, direccion);
    paciente.setDireccion(direccion);

    cout << "Telefono: ";
    getline(cin, telefono);
    paciente.setTelefono(telefono);

    cout << "Genero: ";
    cin >> genero;
    paciente.setGenero(genero);

    cout << "N�mero de historia cl�nica: ";
    cin >> nroHistoriaClinica;
    paciente.setNroHistoriaClinica(nroHistoriaClinica);

    cout << "Porcentaje de cobertura: ";
    cin >> porcCobertura;
    paciente.setPorcCobertura(porcCobertura);

    cout << "Email: ";
    cin.ignore();
    getline(cin, email);
    paciente.setEmail(email);

    paciente.setEstado(true);
}

void PacienteManager::mostrar(Paciente paciente)
{
    if (paciente.getEstado())
    {
        cout << "DNI: " << paciente.getDni() << endl;
        cout << "Nombre: " << paciente.getNombre() << endl;
        cout << "Apellido: " << paciente.getApellido() << endl;
        cout << "Fecha de nacimiento: " << paciente.getFechaNacimiento().toString() << endl;
        cout << "Edad: " << paciente.getEdad() << endl;
        cout << "Direccion: " << paciente.getDireccion() << endl;
        cout << "Telefono: " << paciente.getTelefono() << endl;
        cout << "Genero: " << paciente.getGenero() << endl;
        cout << "Nro de historia clinica: " << paciente.getNroHistoriaClinica() << endl;
        cout << "Porcentaje de cobertura: " << paciente.getPorcCobertura() << endl;
        cout << "Email: " << paciente.getEmail() << endl;
    }
}

void PacienteManager::agregar()
{
    if(archiPacientes.guardar(crear()))
    {
        cout << "�El paciente fue guardado con �xito!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el paciente." << endl;
    }
}

void PacienteManager::listar()
{
    int cantidad = archiPacientes.getCantidadRegistros();
    Paciente *pacientes;

    pacientes = new Paciente[cantidad];

    if(pacientes == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiPacientes.leerTodos(pacientes, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(pacientes[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrar(pacientes[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] pacientes;
}

void PacienteManager::modificar()
{
    int dni, index;
    Paciente paciente;

    cout << "Ingrese el n�mero de DNI a modificar: ";
    cin >> dni;

    index = archiPacientes.buscarByDni(dni);

    if(index != -1)
    {
        paciente = archiPacientes.leer(index);
        mostrar(paciente);
        cargar(paciente);
        if(archiPacientes.guardar(index, paciente))
        {
            cout << "�Paciente modificado con �xito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el paciente." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el paciente con el n�mero de DNI ingresado." << endl;
    }
}

void PacienteManager::eliminar()
{
    int dni, index;
    Paciente paciente;
    char eliminar;

    cout << "Ingrese el DNI del paciente a eliminar: ";
    cin >> dni;

    index = archiPacientes.buscarByDni(dni);

    if(index != -1)
    {
        paciente = archiPacientes.leer(index);

        mostrar(paciente);

        cout << "Esta seguro de eliminar al paciente? S/N ";
        cin >> eliminar;

        if(eliminar == 'S' || eliminar == 's')
        {
            paciente.setEstado(false);

            if(archiPacientes.guardar(index, paciente))
            {
                cout << "�Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el paciente." << endl;
            }
        }
        else
        {
            cout << "El paciente no fue eliminado." << endl;

        }
    }
    else
    {
        cout << "No se encuentra el paciente con el DNI ingresado." << endl;
    }
}