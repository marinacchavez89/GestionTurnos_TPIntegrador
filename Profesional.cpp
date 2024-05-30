#include <iostream>
#include <cstring>
#include "Profesional.h"
#include <string>

using namespace std;

/// CONSTRUCTOR VACIO
Profesional::Profesional()
    : IdEspecialidad(0), Matricula(0), Consultorio(0), Honorario(0.00), DuracionTurno(0) { }

///CONSTRUCTOR CON SUS PARAMETROS
Profesional::Profesional(int dni, string nombre, string apellido, Fecha fechaNacimiento, int edad, string direccion, string telefono, char genero, bool estado,
                         int idEspecialidad, int matricula, int consultorio, float honorario,int duracionTurno)
    : Persona(dni, nombre, apellido, fechaNacimiento, edad, direccion, telefono, genero, estado),
      IdEspecialidad(idEspecialidad), Matricula(matricula), Consultorio(consultorio),
      Honorario(honorario), DuracionTurno(duracionTurno) { }

///GETTERS
int Profesional::getIdEspecialidad()
{
    return IdEspecialidad;
}
int Profesional::getMatricula()
{
    return Matricula;
}
int Profesional::getConsultorio()
{
    return Consultorio;
}
float Profesional::getHonorario()
{
    return Honorario;
}
int Profesional::getDuracionTurno()
{
    return DuracionTurno;
}

///SETTERS
void Profesional::setIdEspecialidad(int idEspecialidad)
{
    IdEspecialidad = idEspecialidad;
}
void Profesional::setMatricula(int matricula)
{
    Matricula = matricula;
}
void Profesional::setConsultorio(int consultorio)
{
    Consultorio = consultorio;
}
void Profesional::setHonorario(float honorario)
{
    Honorario = honorario;
}
void Profesional::setDuracionTurno(int duracionTurno)
{
    DuracionTurno = duracionTurno;
}

///MÉTODOS
void Profesional::cargar()
{
    int dni, edad, matricula, idEspecialidad, consultorio, duracionTurno;
    string nombre, apellido, direccion, telefono;
    char genero;
    float honorario;
    Fecha fecha;

    cout << "DNI: ";
    cin >> dni;
    setDni(dni);
    if (dni < 1)
    {
        return;
    }
    cout << endl;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    setNombre(nombre);

    cout << endl;
    cout << "Apellido: ";
    getline(cin, apellido);
    setApellido(apellido);

    cout << endl;
    cout << "Fecha de nacimiento: ";
    fecha.cargar();
    setFechaNacimiento(fecha);

    cout << endl;
    cout << "Edad: ";
    cin >> edad;
    setEdad(edad);

    cout << endl;
    cout << "Direccion: ";
    cin.ignore();
    getline(cin, direccion);
    setDireccion(direccion);

    cout << endl;
    cout << "Telefono: ";
    getline(cin, telefono);
    setTelefono(telefono);

    cout << endl;
    cout << "Genero: ";
    cin >> genero;
    setGenero(genero);

    cout << endl;
    cout << "Matricula: ";
    cin >> matricula;
    setMatricula(matricula);

    cout << endl;
    cout << "Nro de especialidad: ";
    cin >> idEspecialidad;
    setIdEspecialidad(idEspecialidad);

    cout << endl;
    cout << "Consultorio: ";
    cin >> consultorio;
    setConsultorio(consultorio);

    cout << endl;
    cout << "Honorario: ";
    cin >> honorario;
    setHonorario(honorario);

    cout << endl;
    cout << "Duracion de turnos: ";
    cin >> duracionTurno;
    setDuracionTurno(duracionTurno);

    cout << endl;
    setEstado(true);
}

void Profesional::mostrar()
{
    if (getEstado())
    {
        cout << "DNI: " << getDni() << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Apellido: " << getApellido() << endl;
        cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << endl;
        cout << "Edad: " << getEdad() << endl;
        cout << "Direccion: " << getDireccion() << endl;
        cout << "Telefono: " << getTelefono() << endl;
        cout << "Genero: " << getGenero() << endl;
        cout << "Matricula: " << getMatricula() << endl;
        cout << "Nro de especialidad: " << getIdEspecialidad() << endl;
        cout << "Consultorio: " << getConsultorio() << endl;
        cout << "Honorario: " << getHonorario() << endl;
        cout << "Duracion de turnos: " << getDuracionTurno() << endl;
    }
}

