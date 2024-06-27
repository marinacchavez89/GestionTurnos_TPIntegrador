#include <iostream>
using namespace std;
#include "TurnoManager.h"

Turno TurnoManager::crear(){
    int idTurno, matricula, dni, idEspecialidad, consultorio, idEstadoTurno;
    Fecha fechaTurno;
    Hora horaTurno;

    cout << "ID del turno: ";
    cin >> idTurno;

    cout << "Fecha del turno: ";
    fechaTurno.cargar();

    cout << "Matricula del profesional: ";
    cin >> matricula;

    cout << "Dni del paciente: ";
    cin >> dni;

    cout << "Id especialidad a atenderse: ";
    cin >> idEspecialidad;

    cout << "Consultorio de atención: ";
    cin >> consultorio;

    cout << "Ingrese la hora del turno: ";
    horaTurno.cargar();

    cout << "Ingrese el ID del estado del turno (0: Libre - 1: otorgado - 2: En Curso - 3: Finalizado - 4: Cancelado)";
    cin >> idEstadoTurno;

    return Turno(idTurno, fechaTurno, matricula, dni, idEspecialidad, consultorio, horaTurno, idEstadoTurno, true);
}

void TurnoManager::cargar(Turno &turno) {
    int idTurno, matricula, dni, idEspecialiad, consultorio, idEstadoTurno;
    Fecha fechaTurno;
    Hora horaTurno;

    cout << "ID del turno: ";
    cin >> idTurno;
    turno.setIdTurno(idTurno);

    cout << "Fecha del turno: ";
    fechaTurno.cargar();
    turno.setFechaTurno(fechaTurno);

    cout << "Matricula del profesional: ";
    cin >> matricula;
    turno.setMatricula(matricula);

    cout << "Dni del paciente: ";
    cin >> dni;
    turno.setDni(dni);

    cout << "Id especialidad a atenderse: ";
    cin >> idEspecialiad;
    turno.setIdEspecialidad(idEspecialiad);

    cout << "Consultorio de atención: ";
    cin >> consultorio;
    turno.setConsultorio(consultorio);

    cout << "Ingrese la hora del turno: ";
    horaTurno.cargar();
    turno.setHoraTurno(horaTurno);

    cout << "Ingrese el ID del estado del turno (0: Libre - 1: otorgado - 2: En Curso - 3: Finalizado - 4: Cancelado): ";
    cin >> idEstadoTurno;
    turno.setIdEstadoTurno(idEstadoTurno);

    turno.setEstado(true);

}

void TurnoManager::mostrar(Turno turno)
{
    if (turno.getEstado())
    {
        cout << "ID del turno: " << turno.getIdTurno() << endl;
        cout << "Fecha del turno: " << turno.getFechaTurno().toString() << endl;
        cout << "Matricula del profesional: " << turno.getIdTurno() << endl;
        cout << "Dni del paciente: " << turno.getDni() << endl;
        cout << "Id especialidad a atenderse: " << turno.getIdEspecialidad() << endl;
        cout << "Consultorio de atención: " << turno.getConsultorio() << endl;
        cout << "Hora del turno: " << turno.getHoraTurno().toString() << endl;
        cout << "Estado del turno: " << estadoTurnoToString(turno.getIdEstadoTurno()) << endl;
    }
}

/// ACA FALTAN VALIDACIONES DE TURNOS
void TurnoManager::agregar()
{
    Turno nuevoTurno = crear();

    if (archiTurno.buscarByID(nuevoTurno.getIdTurno()) != -1) {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiTurno.guardar(nuevoTurno)) {
        cout << "¡El turno fue agendado con éxito!" << endl;
    } else {
        cout << "No se pudo agendar el turno." << endl;
    }
}

void TurnoManager::listar()
{
    int cantidad = archiTurno.getCantidadRegistros();
    Turno *turnos;

    turnos = new Turno[cantidad];

    if(turnos == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiTurno.leerTodos(turnos, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(turnos[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrar(turnos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] turnos;
}
void TurnoManager::modificar()
{
    int idTurno, index;
    Turno turno;

    cout << "Ingrese el número de ID del turno a modificar: ";
    cin >> idTurno;

    index = archiTurno.buscarByID(idTurno);

    if(index != -1)
    {
        turno = archiTurno.leer(index);
        mostrar(turno);
        cargar(turno);
        if(archiTurno.guardar(index, turno))
        {
            cout << "¡Turno modificado con éxito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el turno." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el ID del turno ingresado." << endl;
    }
}

void TurnoManager::eliminar()
{
    int idTurno, index;
    Turno turno;
    char eliminar;

    cout << "Ingrese el ID del turno a eliminar: ";
    cin >> idTurno;

    index = archiTurno.buscarByID(idTurno);

    if(index != -1)
    {
        turno = archiTurno.leer(index);

        mostrar(turno);

        cout << "Esta seguro de eliminar el turno? S/N ";
        cin >> eliminar;

        if(eliminar == 'S' || eliminar == 's')
        {
            turno.setEstado(false);

            if(archiTurno.guardar(index, turno))
            {
                cout << "¡Se eliminó con éxito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el turno." << endl;
            }
        }
        else
        {
            cout << "El turno no fue eliminado." << endl;

        }
    }
    else
    {
        cout << "No se encuentra el ID del turno ingresado." << endl;
    }
}

string TurnoManager::estadoTurnoToString(int idEstadoTurno)
{
    string descripEstadoTurno = "";
    if(idEstadoTurno==0)
    {
        descripEstadoTurno = "Libre";
    }
    if(idEstadoTurno==1)
    {
        descripEstadoTurno = "Otorgado";
    }
    if(idEstadoTurno==2)
    {
        descripEstadoTurno = "En curso";
    }
    if(idEstadoTurno==3)
    {
        descripEstadoTurno = "Finalizado";
    }
    if(idEstadoTurno==4)
    {
        descripEstadoTurno = "Cancelado";
    }

    return descripEstadoTurno;
}

