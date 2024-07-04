#include <iostream>
using namespace std;
#include "HorariosProfesionalesArchivo.h"

bool HorariosProfesionalesArchivo::guardar(HorariosProfesionales reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("horariosProfesionales.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (HorariosProfesionales), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool HorariosProfesionalesArchivo::guardar(int index, HorariosProfesionales reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("horariosProfesionales.dat", "rb+");

    if(pFile == nullptr)
    {

        return false;
    }

    fseek(pFile, sizeof(HorariosProfesionales) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (HorariosProfesionales), 1, pFile);

    fclose(pFile);

    return resultado;
}

HorariosProfesionales HorariosProfesionalesArchivo::leer(int index)
{
    HorariosProfesionales reg;
    FILE *pFile;

    pFile = fopen("horariosProfesionales.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (HorariosProfesionales), SEEK_SET);

    fread(&reg, sizeof(HorariosProfesionales), 1, pFile);

    fclose(pFile);

    return reg;
}

void HorariosProfesionalesArchivo::leerTodos(HorariosProfesionales registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("horariosProfesionales.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(HorariosProfesionales), cantidad, pFile);

    fclose(pFile);
}

int HorariosProfesionalesArchivo::buscarByMatricula(int matricula)
{
    HorariosProfesionales reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("horariosProfesionales.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(HorariosProfesionales), 1, pFile))
    {
        if(reg.getMatricula() == matricula && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int HorariosProfesionalesArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("horariosProfesionales.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (HorariosProfesionales);

    fclose(pFile);

    return tam;
}

HorariosProfesionales* HorariosProfesionalesArchivo::buscarTodosByMatricula(int matricula, int &cantidad)
{
    cantidad = 0;
    HorariosProfesionales reg;
    FILE *pFile;

    pFile = fopen("horariosProfesionales.dat", "rb");
    if(pFile == nullptr)
    {
        return nullptr;
    }

    while(fread(&reg, sizeof(HorariosProfesionales), 1, pFile))
    {
        if(reg.getMatricula() == matricula && reg.getEstado())
        {
            cantidad++;
        }
    }

    if(cantidad == 0)
    {
        fclose(pFile);
        return nullptr;
    }

    HorariosProfesionales* horariosProf = new HorariosProfesionales[cantidad];
    int index = 0;

    fseek(pFile, 0, SEEK_SET);

    while(fread(&reg, sizeof(HorariosProfesionales), 1, pFile))
    {
        if(reg.getMatricula() == matricula && reg.getEstado())
        {
            horariosProf[index++] = reg;
        }
    }

    fclose(pFile);
    return horariosProf;
}
