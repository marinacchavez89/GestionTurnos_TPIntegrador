#pragma once
#include "Turno.h"
#include "TurnoArchivo.h"

class TurnoManager {

private:
    TurnoArchivo archiTurno;

public:
    Turno crear();
    void cargar(Turno &registro);
    void mostrar(Turno registro);
    void agregar();
    void listar();
    void modificar();
    void eliminar();
    bool turnoAsignado(Turno turnoAEvaluar);
    string estadoTurnoToString(int idEstadoTurno);
    bool esFechaHoraPasada(Fecha fechaTurno, Hora horaTurno);
    bool esHorarioValido(int matricula, Fecha fechaTurno, Hora horaTurno);
    int obtenerDiaSemana(int dia, int mes, int anio);
};
