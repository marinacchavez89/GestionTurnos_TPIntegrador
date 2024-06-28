#include <iostream>
using namespace std;
#include "EstadoTurnoArchivo.h"


bool EstadoTurnoArchivo::guardar(EstadoTurno reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("estadoTurnos.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (EstadoTurno), 1, pFile);

    fclose(pFile);

    return resultado;
}
bool EstadoTurnoArchivo::guardar(int index, EstadoTurno reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("estadoTurnos.dat", "rb+");

    if(pFile == nullptr)
    {

        return false;
    }

    fseek(pFile, sizeof(EstadoTurno) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (EstadoTurno), 1, pFile);

    fclose(pFile);

    return resultado;
}

EstadoTurno EstadoTurnoArchivo::leer(int index)
{
    EstadoTurno reg;
    FILE *pFile;

    pFile = fopen("estadoTurnos.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (EstadoTurno), SEEK_SET);

    fread(&reg, sizeof(EstadoTurno), 1, pFile);

    fclose(pFile);

    return reg;
}

void EstadoTurnoArchivo::leerTodos(EstadoTurno registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("estadoTurnos.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(EstadoTurno), cantidad, pFile);

    fclose(pFile);
}

int EstadoTurnoArchivo::buscarByID(int idEstadoTurno)
{
    EstadoTurno reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("estadoTurnos.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(EstadoTurno), 1, pFile))
    {
        if(reg.getIdEstadoTurno() == idEstadoTurno && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}
int EstadoTurnoArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("estadoTurnos.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (EstadoTurno);

    fclose(pFile);

    return tam;
}

