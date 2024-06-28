#include <iostream>
using namespace std;
#include "ProfesionalArchivo.h"

bool ProfesionalArchivo::guardar(Profesional reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("profesionales.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (Profesional), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool ProfesionalArchivo::guardar(int index, Profesional reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("profesionales.dat", "rb+");

    if(pFile == nullptr)
    {

        return false;
    }

    fseek(pFile, sizeof(Profesional) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (Profesional), 1, pFile);

    fclose(pFile);

    return resultado;
}

Profesional ProfesionalArchivo::leer(int index)
{
    Profesional reg;
    FILE *pFile;

    pFile = fopen("profesionales.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (Profesional), SEEK_SET);

    fread(&reg, sizeof(Profesional), 1, pFile);

    fclose(pFile);

    return reg;
}

void ProfesionalArchivo::leerTodos(Profesional registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("profesionales.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(Profesional), cantidad, pFile);

    fclose(pFile);
}

int ProfesionalArchivo::buscarByMatricula(int mat)
{
    Profesional reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("profesionales.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Profesional), 1, pFile))
    {
        if(reg.getMatricula() == mat && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int ProfesionalArchivo::buscarByDni(int dni)
{
    Profesional reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("profesionales.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Profesional), 1, pFile))
    {
        if(reg.getDni() == dni)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int ProfesionalArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("profesionales.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Profesional);

    fclose(pFile);

    return tam;
}
