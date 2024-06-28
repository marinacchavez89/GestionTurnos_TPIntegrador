#include <iostream>
using namespace std;
#include "EspecialidadArchivo.h"

bool EspecialidadArchivo::guardar(Especialidad reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("especialidades.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (Especialidad), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool EspecialidadArchivo::guardar(int index, Especialidad reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("especialidades.dat", "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Especialidad) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (Especialidad), 1, pFile);

    fclose(pFile);

    return resultado;
}

Especialidad EspecialidadArchivo::leer(int index)
{
    Especialidad reg;
    FILE *pFile;

    pFile = fopen("especialidades.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (Especialidad), SEEK_SET);

    fread(&reg, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return reg;
}

void EspecialidadArchivo::leerTodos(Especialidad registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("especialidades.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(Especialidad), cantidad, pFile);

    fclose(pFile);
}

int EspecialidadArchivo::buscarByID(int idEspecialidad)
{
    Especialidad reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("especialidades.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Especialidad), 1, pFile))
    {
        if(reg.getIdEspecialidad() == idEspecialidad && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int EspecialidadArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("especialidades.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Especialidad);

    fclose(pFile);

    return tam;
}
