#include <iostream>
#include <cstdlib>
using namespace std;
#include "HorariosProfesionalesManager.h"

HorariosProfesionales HorariosProfesionalesManager::crear()
{
    int matricula;
    int diaAtencion;
    Hora horaInicio, horaFin;
    int duracionTurno;

    cout << "Matricula del Profesional: "<< endl;
    cin >> matricula;

    cout << "Dia de atencion (1-7 para Lunes-Domingo): " << endl;
    cin >> diaAtencion;

    cout << "Hora de Inicio (hh:mm): " << endl;
    horaInicio.cargar();

    cout << "Hora de Fin (hh:mm): " << endl;
    horaFin.cargar();

    cout << "Duracion del Turno (minutos): " << endl;
    cin >> duracionTurno;

    return HorariosProfesionales(matricula, diaAtencion, horaInicio, horaFin, duracionTurno, true);

}

void HorariosProfesionalesManager::cargar(HorariosProfesionales &horario)
{
    int matricula;
    int diaAtencion;
    Hora horaInicio, horaFin;
    int duracionTurno;

    cout << "Matrícula del Profesional: ";
    cin >> matricula;
    horario.setMatricula(matricula);

    cout << "Día de Atención (1-7 para Lunes-Domingo): ";
    cin >> diaAtencion;
    horario.setDiaAtencion(diaAtencion);

    cout << "Hora de Inicio (hh:mm): ";
    horaInicio.cargar();
    horario.setHoraInicio(horaInicio);

    cout << "Hora de Fin (hh:mm): ";
    horaFin.cargar();
    horario.setHoraFin(horaFin);

    cout << "Duración del Turno (minutos): ";
    cin >> duracionTurno;
    horario.setDuracionTurno(duracionTurno);

    horario.setEstado(true);
}

void HorariosProfesionalesManager::mostrar(HorariosProfesionales horario)
{
    if (horario.getEstado())
    {
        cout << "Matricula del profesional: " << horario.getMatricula() << endl;
        cout << "Día de atención: " << horario.getDiaAtencion() << endl;
        cout << "Hora de inicio: " << horario.getHoraInicio().toString() << endl;
        cout << "Hora de fin: " << horario.getHoraFin().toString() << endl;
        cout << "Duración del turno: " << horario.getDuracionTurno() << " minutos." << endl;
    }
}

void HorariosProfesionalesManager::agregar()
{
    if(archiHorarios.guardar(crear()))
    {
        cout << "¡El horario del profesional fue guardado con éxito!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el horario del profesional. "<< endl;
    }
}

void HorariosProfesionalesManager::listar()
{
    int cantidad = archiHorarios.getCantidadRegistros();
    HorariosProfesionales *horarios;

    horarios = new HorariosProfesionales[cantidad];

    if(horarios == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiHorarios.leerTodos(horarios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if(horarios[i].getEstado())
        {
            cout << "---------------------" << endl;
            mostrar(horarios[i]);
            cout << "---------------------" << endl;
        }
    }

    delete[] horarios;
}

void HorariosProfesionalesManager::modificar()
{
    int matricula, index;
    HorariosProfesionales horario;

    cout << "Ingrese la matricula del prefesional del horario a modificar: " << endl;
    cin >> matricula;

    index = archiHorarios.buscarByMatricula(matricula);

    if(index != -1)
    {
        horario = archiHorarios.leer(index);
        mostrar(horario);
        cargar(horario);
        if(archiHorarios.guardar(index, horario))
        {
            cout << "¡Horario del profesional modificado con éxito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el horario del profesional." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el horario del profesioanl ingresado. " << endl;
    }

}

void HorariosProfesionalesManager::eliminar()
{
    int matricula, index;
    HorariosProfesionales horario;
    char eliminar;
    cout << "Ingrese la matricula del profesional del horario a eliminar: " << endl;
    cin >> matricula;

    index = archiHorarios.buscarByMatricula(matricula);
    if(index != -1)
    {
        horario = archiHorarios.leer(index);
        mostrar(horario);

        cout << "Esta seguro de eliminar el horario del profesional? S/N " << endl;
        cin >> eliminar;
        if(eliminar == 'S' || eliminar =='s')
        {
            horario.setEstado(false);
            if(archiHorarios.guardar(index,horario))
            {
                cout << "¡Se eliminó con éxito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el horario del profesional. " << endl;
            }
        }
        else
        {
            cout << "El horario del profesional no fue eliminado. " << endl;
        }
    }
    else
    {
        cout << "No se encuentra la matricula del profesional ingresada." << endl;
    }
}
