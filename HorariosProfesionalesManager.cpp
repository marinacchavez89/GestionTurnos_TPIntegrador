#include <iostream>
#include <cstdlib>
using namespace std;
#include "HorariosProfesionalesManager.h"
#include "Utils.h"

HorariosProfesionales HorariosProfesionalesManager::crear()
{
    int matricula;
    int diaAtencion;
    Hora horaInicio, horaFin;
    int duracionTurno;

    cout << "Matricula del Profesional: "<< endl;
    cin >> matricula;
    while(!validarIngresoNros(matricula)){
        cout << "Matricula del Profesional (Solo n�meros): ";
        cin >> matricula;
    }


    cout << "D�a de atenci�n (1-7 para Lunes-Domingo): " << endl;
    cin >> diaAtencion;
    while(!validarIngresoNros(diaAtencion)){
        cout << "Dia de atenci�n (1-7 para Lunes-Domingo) - Solo n�meros: ";
        cin >> diaAtencion;
    }

    cout << "Hora de Inicio (hh:mm): " << endl;
    horaInicio.cargar();

    cout << "Hora de Fin (hh:mm): " << endl;
    horaFin.cargar();

    cout << "Duracion del Turno (minutos): " << endl;
    cin >> duracionTurno;
    while(!validarIngresoNros(duracionTurno)){
        cout << "Duracion del Turno (minutos) - Solo n�meros: ";
        cin >> duracionTurno;
    }


    return HorariosProfesionales(matricula, diaAtencion, horaInicio, horaFin, duracionTurno, true);

}

void HorariosProfesionalesManager::cargar(HorariosProfesionales &horario)
{
    int matricula;
    int diaAtencion;
    Hora horaInicio, horaFin;
    int duracionTurno;

    cout << "Matr�cula del Profesional: ";
    cin >> matricula;
    horario.setMatricula(matricula);

    cout << "D�a de Atenci�n (1-7 para Lunes-Domingo): ";
    cin >> diaAtencion;
    horario.setDiaAtencion(diaAtencion);

    cout << "Hora de Inicio (hh:mm): ";
    horaInicio.cargar();
    horario.setHoraInicio(horaInicio);

    cout << "Hora de Fin (hh:mm): ";
    horaFin.cargar();
    horario.setHoraFin(horaFin);

    cout << "Duraci�n del Turno (minutos): ";
    cin >> duracionTurno;
    horario.setDuracionTurno(duracionTurno);

    horario.setEstado(true);
}

void HorariosProfesionalesManager::mostrar(HorariosProfesionales horario)
{
    if (horario.getEstado())
    {
        cout << "Matricula del profesional: " << horario.getMatricula() << endl;
        cout << "D�a de atenci�n: " << horario.getDiaAtencion() << endl;
        cout << "Hora de inicio: " << horario.getHoraInicio().toString() << endl;
        cout << "Hora de fin: " << horario.getHoraFin().toString() << endl;
        cout << "Duraci�n del turno: " << horario.getDuracionTurno() << " minutos." << endl;
    }
}

void HorariosProfesionalesManager::agregar()
{

    HorariosProfesionales nuevoHorarioProfesional = crear();

    int indexProf = archiHorarios.buscarByMatricula(nuevoHorarioProfesional.getMatricula());
    HorariosProfesionales regProf = archiHorarios.leer(indexProf);

    if (regProf.getMatricula() == nuevoHorarioProfesional.getMatricula() &&
        regProf.getHoraInicio() == nuevoHorarioProfesional.getHoraInicio() &&
        regProf.getHoraFin() == nuevoHorarioProfesional.getHoraFin() &&
        regProf.getDiaAtencion() == nuevoHorarioProfesional.getDiaAtencion() && regProf.getEstado()) {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiHorarios.guardar(nuevoHorarioProfesional)) {
        cout << "�El horario del profesional fue guardado con �xito!" << endl;
    } else {
        cout << "No se pudo guardar el horario del profesional." << endl;
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
    system("cls");
    cout << "********************************************************************************" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                               LISTADO HORARIOS                               |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "********************************************************************************" << endl;

    for (int i = 0; i < cantidad; i++)
    {
        if(horarios[i].getEstado())
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            mostrar(horarios[i]);
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
    while(!validarIngresoNros(matricula)){
        cout << "Ingrese la matricula del profesional (Solo n�meros): ";
        cin >> matricula;
    }

    index = archiHorarios.buscarByMatricula(matricula);

    if(index != -1)
    {
        horario = archiHorarios.leer(index);
        mostrar(horario);
        cargar(horario);
        if(archiHorarios.guardar(index, horario))
        {
            cout << "�Horario del profesional modificado con �xito!" << endl;
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
    while(!validarIngresoNros(matricula)){
        cout << "Ingrese la matricula del profesional (Solo n�meros): ";
        cin >> matricula;
    }

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
                cout << "�Se elimin� con �xito!" << endl;
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
