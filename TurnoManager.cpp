#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>
using namespace std;
#include "TurnoManager.h"
#include "HorariosProfesionalesArchivo.h"
#include "EspecialidadArchivo.h"
#include "PacienteArchivo.h"
#include "ProfesionalArchivo.h"
#include "Utils.h"

Turno TurnoManager::crear()
{
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

    cout << "Ingrese el ID del estado del turno" << endl;
    cout << "(0: Libre - 1: otorgado - 2: En Curso - 3: Finalizado - 4: Cancelado): ";
    cin >> idEstadoTurno;

    return Turno(idTurno, fechaTurno, matricula, dni, idEspecialidad, consultorio, horaTurno, idEstadoTurno, true);
}

void TurnoManager::cargar(Turno &turno)
{
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

    cout << "Ingrese el ID del estado del turno" << endl;
    cout << "(0: Libre - 1: otorgado - 2: En Curso - 3: Finalizado - 4: Cancelado): ";
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
        cout << "Matricula del profesional: " << turno.getMatricula() << endl;
        cout << "Dni del paciente: " << turno.getDni() << endl;
        cout << "Id especialidad a atenderse: " << turno.getIdEspecialidad() << endl;
        cout << "Consultorio de atención: " << turno.getConsultorio() << endl;
        cout << "Hora del turno: " << turno.getHoraTurno().toString() << endl;
        cout << "Estado del turno: " << descripEstadoTurno(turno.getIdEstadoTurno()) << endl;
    }
}

void TurnoManager::agregar()
{
    Turno nuevoTurno = crear();

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    Fecha fechaActual(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    Hora horaActual(now->tm_hour, now->tm_min);


    if (nuevoTurno.getFechaTurno() < fechaActual ||
            (nuevoTurno.getFechaTurno() == fechaActual && nuevoTurno.getHoraTurno() < horaActual))
    {
        cout << "La fecha elegida, es una fecha caducada." << endl;
        return;
    }

    HorariosProfesionalesArchivo horariosProfesionalArchivo;
    int index = horariosProfesionalArchivo.buscarByMatricula(nuevoTurno.getMatricula());
    if (index == -1)
    {
        cout << "No se encontró el horario del profesional." << endl;
        return;
    }

    HorariosProfesionales horarioProfesional = horariosProfesionalArchivo.leer(index);
    int dia = nuevoTurno.getFechaTurno().getDia();
    int mes = nuevoTurno.getFechaTurno().getMes();
    int anio = nuevoTurno.getFechaTurno().getAnio();
    int diaAValidar = obtenerDiaSemana(dia, mes, anio);
    if (horarioProfesional.getDiaAtencion() != diaAValidar ||
            !(horarioProfesional.getHoraInicio() <= nuevoTurno.getHoraTurno() && nuevoTurno.getHoraTurno() <= horarioProfesional.getHoraFin()))
    {
        cout << "El profesional no atiende en el horario seleccionado." << endl;
        return;
    }

    PacienteArchivo pacienteArchivo;
    int indexPaciente = pacienteArchivo.buscarByDni(nuevoTurno.getDni());
    if (indexPaciente == -1)
    {
        cout << "No se encontró el paciente. Darlo de alta de ser necesario." << endl;
        return;
    }

    if (archiTurno.buscarByID(nuevoTurno.getIdTurno()) != -1)
    {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if(turnoAsignado(nuevoTurno))
    {
        cout << "Turno ya asignado." << endl;
        return;
    }

    if (archiTurno.buscarByID(nuevoTurno.getIdTurno()) != -1)
    {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiTurno.guardar(nuevoTurno))
    {
        cout << "¡El turno fue agendado con éxito!" << endl;
    }
    else
    {
        cout << "No se pudo agendar el turno. Turno ya asignado." << endl;
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

bool TurnoManager::turnoAsignado(Turno turnoAEvaluar)
{
    int cantidad = archiTurno.getCantidadRegistros();
    Turno *turnos;

    turnos = new Turno[cantidad];

    if(turnos == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return false;
    }

    archiTurno.leerTodos(turnos, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(turnos[i].getIdEstadoTurno()==1 && turnos[i].getEstado())
        {
            if(turnos[i].getFechaTurno() == turnoAEvaluar.getFechaTurno() &&
                    turnos[i].getMatricula() == turnoAEvaluar.getMatricula() &&
                    turnos[i].getHoraTurno() == turnoAEvaluar.getHoraTurno())
            {
                delete [] turnos;
                return true;
            }
        }

    }

    delete [] turnos;
    return false;
}

string TurnoManager::descripEstadoTurno(int idEstadoTurno)
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

bool TurnoManager::esFechaHoraPasada(Fecha fechaTurno, Hora horaTurno)
{
    time_t t = time(0);
    tm* now = localtime(&t);

    Fecha fechaActual(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    Hora horaActual(now->tm_hour, now->tm_min);

    if (fechaTurno < fechaActual)
    {
        return true;
    }
    else if (fechaTurno == fechaActual && horaTurno < horaActual)
    {
        return true;
    }
    return false;
}

bool TurnoManager::esHorarioValido(int matricula, Fecha fechaTurno, Hora horaTurno)
{
    HorariosProfesionalesArchivo horariosArchivo;
    int cantidadHorarios = horariosArchivo.getCantidadRegistros();
    HorariosProfesionales* horarios = new HorariosProfesionales[cantidadHorarios];
    horariosArchivo.leerTodos(horarios, cantidadHorarios);

    for (int i = 0; i < cantidadHorarios; i++)
    {
        if (horarios[i].getMatricula() == matricula && horarios[i].getDiaAtencion() == fechaTurno.getDia())
        {
            if (horaTurno >= horarios[i].getHoraInicio() && horaTurno <= horarios[i].getHoraFin())
            {
                delete[] horarios;
                return true;
            }
        }
    }

    delete[] horarios;
    return false;
}

int TurnoManager::obtenerDiaSemana(int dia, int mes, int anio)
{
    struct tm date = {};
    date.tm_year = anio - 1900;
    date.tm_mon = mes - 1;
    date.tm_mday = dia;
    date.tm_isdst = -1;

    if (mktime(&date) == -1)
    {
        std::cerr << "Error al convertir la fecha." << std::endl;
        return -1;
    }

    int diaSemana = date.tm_wday;

    // Convertir diaSemana de 0-6 a 1-7
    if (diaSemana == 0)
    {
        diaSemana = 7;
    }

    return diaSemana;
}

string TurnoManager::descripMes(int mesNro)
{

    string descripMes = "";
    switch(mesNro)
    {

    case 1:
        descripMes = "Enero";
        break;
    case 2:
        descripMes = "Febrero";
        break;
    case 3:
        descripMes = "Marzo";
        break;
    case 4:
        descripMes = "Abril";
        break;
    case 5:
        descripMes = "Mayo";
        break;
    case 6:
        descripMes = "Junio";
        break;
    case 7:
        descripMes = "Julio";
        break;
    case 8:
        descripMes = "Agosto";
        break;
    case 9:
        descripMes = "Septiembre";
        break;
    case 10:
        descripMes = "Octubre";
        break;
    case 11:
        descripMes = "Noviembre";
        break;
    case 12:
        descripMes = "Diciembre";
        break;
    }

    return descripMes;

}

void TurnoManager::recaudacionAnual(int anio)
{
    TurnoArchivo archiTurnos;
    Turno regTurno;
    int cantRegTurnos = archiTurnos.getCantidadRegistros();

    ProfesionalArchivo archiProf;
    Profesional regProfesional;
    int cantRegProfesionales = archiProf.getCantidadRegistros();

    float acuRecaudacionMeses[12] = {};
    float acuRecTotal = 0;

    for(int i = 0; i < cantRegTurnos ; i++)
    {
        regTurno = archiTurnos.leer(i);

        if(regTurno.getFechaTurno().getAnio() == anio && regTurno.getIdEstadoTurno() == 3)
        {

            for(int j = 0; j < cantRegProfesionales; j++)
            {
                regProfesional = archiProf.leer(j);

                if(regTurno.getMatricula() == regProfesional.getMatricula() && regProfesional.getEstado())
                {

                    if(regTurno.getEstado())
                    {
                        acuRecaudacionMeses[regTurno.getFechaTurno().getMes() - 1] += regProfesional.getHonorario();
                        acuRecTotal+=regProfesional.getHonorario();
                    }
                }
            }
        }
    }
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "*******************************************************************************" << endl;
    cout << endl;
    cout << setw(50) << right << " RECAUDACION ANUAL - AÑO " << anio << endl;
    cout << endl;
    cout << "*******************************************************************************" << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "MES" << setw(40) << right << "RECAUDACIÓN" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < 12; i++)
    {
        cout << setw(10) << left << descripMes(i+1) << setw(30) << right << "$" << acuRecaudacionMeses[i] << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "TOTAL" << setw(30) << right << "$" << acuRecTotal << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void TurnoManager::cantidadTurnosAsignados()
{
    TurnoArchivo archiTurnos;
    Turno regTurno;
    int cantRegTurnos = archiTurnos.getCantidadRegistros();

    int contadorEstadoTurnos[5] = {};
    int totalDeTurnos = 0;

    for(int i = 0; i < cantRegTurnos; i++)
    {
        regTurno = archiTurnos.leer(i);

        if(regTurno.getEstado())
        {
            contadorEstadoTurnos[regTurno.getIdEstadoTurno()]++;
            totalDeTurnos++;
        }
    }
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "*******************************************************************************" << endl;
    cout << endl;
    cout << setw(55) << right << " CANTIDAD TOTAL DE TURNOS OTORGADOS"<< endl;
    cout << endl;
    cout << "*******************************************************************************" << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "ESTADO DE TURNO" << setw(32) << right << "CANTIDAD" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << setw(10) << left << descripEstadoTurno(i) << setw(30) << right << contadorEstadoTurnos[i] << endl;
    }

    cout << "------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "TOTAL" << setw(30) << right << totalDeTurnos << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void TurnoManager::recaudacionPorProfesional(int matricula)
{
    TurnoArchivo archiTurnos;
    Turno regTurno;
    int cantRegTurnos = archiTurnos.getCantidadRegistros();

    ProfesionalArchivo archiProf;
    Profesional regProfesional;
    int cantRegProfesionales = archiProf.getCantidadRegistros();

    float acuRecaudacionMeses[12] = {};
    float acuRecTotal = 0;

    string nombreProfesional = "";

    for(int i = 0; i < cantRegTurnos ; i++)
    {
        regTurno = archiTurnos.leer(i);

        if(regTurno.getIdEstadoTurno() == 3)
        {

            for(int j = 0; j < cantRegProfesionales; j++)
            {
                regProfesional = archiProf.leer(j);

                if(regTurno.getMatricula() == regProfesional.getMatricula() && regProfesional.getMatricula()== matricula && regProfesional.getEstado())
                {

                    if(regTurno.getEstado())
                    {
                        acuRecaudacionMeses[regTurno.getFechaTurno().getMes() - 1] += regProfesional.getHonorario();
                        acuRecTotal+=regProfesional.getHonorario();
                        nombreProfesional = regProfesional.getNombre() + " " + regProfesional.getApellido();
                    }
                }
            }
        }
    }
    int indexProf = archiProf.buscarByMatricula(matricula);
    if(indexProf == -1)
    {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Error en el cálculo de recaudaciones. Verifique número de matricula." << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
        return;
    }
    else if(acuRecTotal != 0)
    {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "*******************************************************************************" << endl;
        cout << endl;
        cout << setw(40) << right << "Profesional: " << nombreProfesional << endl;
        cout << endl;
        cout << "*******************************************************************************" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << setw(10) << left << "MES" << setw(40) << right << "RECAUDACIÓN" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        for(int i = 0; i < 12; i++)
        {
            cout << setw(10) << left << descripMes(i+1) << setw(30) << right << "$" << acuRecaudacionMeses[i] << endl;
        }

        cout << "-------------------------------------------------------------------------------" << endl;
        cout << setw(10) << left << "TOTAL" << setw(30) << right << "$" << acuRecTotal << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    else if(acuRecTotal==0)
    {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "El profesional no posee recaudación." << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
    }
}

string TurnoManager::descripEspecialidad(int especialidad)
{

    EspecialidadArchivo archiEspecialidad;
    int index = archiEspecialidad.buscarByID(especialidad);

    if (index != -1)
    {
        Especialidad idEspecialidad = archiEspecialidad.leer(index);
        return idEspecialidad.getDescripcion();
    }
    else
    {
        return "Especialidad no encontrada";
    }
}

void TurnoManager::recaudacionPorEspecialidad(int idEspecialidad)
{
    TurnoArchivo archiTurnos;
    Turno regTurno;
    int cantRegTurnos = archiTurnos.getCantidadRegistros();

    ProfesionalArchivo archiProf;
    Profesional regProfesional;
    int cantRegProfesionales = archiProf.getCantidadRegistros();

    float acuRecaudacionMeses[12] = {};
    float acuRecTotal = 0;

    string nombreEspecialidad = descripEspecialidad(idEspecialidad);

    for(int i = 0; i < cantRegTurnos ; i++)
    {
        regTurno = archiTurnos.leer(i);

        if(regTurno.getIdEstadoTurno() == 3 && regTurno.getIdEspecialidad() == idEspecialidad)
        {

            for(int j = 0; j < cantRegProfesionales; j++)
            {
                regProfesional = archiProf.leer(j);

                if(regTurno.getMatricula() == regProfesional.getMatricula() && regProfesional.getEstado())
                {

                    if(regTurno.getEstado())
                    {
                        acuRecaudacionMeses[regTurno.getFechaTurno().getMes() - 1] += regProfesional.getHonorario();
                        acuRecTotal += regProfesional.getHonorario();
                    }
                }
            }
        }
    }
    if(nombreEspecialidad == "Especialidad no encontrada")
    {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Error en el cálculo de recaudaciones. Verifique número de especialidad." << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
        return;
    }
    else if(acuRecTotal != 0)
    {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "*******************************************************************************" << endl;
        cout << endl;
        cout << setw(40) << right << "Especialidad: " << nombreEspecialidad << endl;
        cout << endl;
        cout << "*******************************************************************************" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << setw(10) << left << "MES" << setw(40) << right << "RECAUDACIÓN" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        for(int i = 0; i < 12; i++)
        {
            cout << setw(10) << left << descripMes(i+1) << setw(30) << right << "$" << acuRecaudacionMeses[i] << endl;
        }

        cout << "-------------------------------------------------------------------------------" << endl;
        cout << setw(10) << left << "TOTAL" << setw(30) << right << "$" << acuRecTotal << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    else if(acuRecTotal == 0)
    {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "La especialidad no posee recaudación." << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << endl;
    }
}
