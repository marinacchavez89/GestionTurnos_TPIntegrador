#include <iostream>
using namespace std;
#include "TurnoArchivo.h"


bool TurnoArchivo::guardar(Turno reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("turnos.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (Turno), 1, pFile);

    fclose(pFile);

    return resultado;
}
bool TurnoArchivo::guardar(int index, Turno reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("turnos.dat", "rb+");

    if(pFile == nullptr)
    {

        return false;
    }

    fseek(pFile, sizeof(Turno) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (Turno), 1, pFile);

    fclose(pFile);

    return resultado;
}

Turno TurnoArchivo::leer(int index)
{
    Turno reg;
    FILE *pFile;

    pFile = fopen("turnos.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (Turno), SEEK_SET);

    fread(&reg, sizeof(Turno), 1, pFile);

    fclose(pFile);

    return reg;
}

void TurnoArchivo::leerTodos(Turno registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("turnos.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(Turno), cantidad, pFile);

    fclose(pFile);
}

int TurnoArchivo::buscarByID(int idTurno)
{
    Turno reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("turnos.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Turno), 1, pFile))
    {
        if(reg.getIdTurno() == idTurno && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}
int TurnoArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("turnos.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Turno);

    fclose(pFile);

    return tam;
}

