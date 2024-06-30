#include <iostream>
#include <cctype>

using namespace std;

#include "PacienteArchivo.h"


bool PacienteArchivo::guardar(Paciente reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("pacientes.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (Paciente), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool PacienteArchivo::guardar(int index, Paciente reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("pacientes.dat", "rb+");

    if(pFile == nullptr)
    {

        return false;
    }

    fseek(pFile, sizeof(Paciente) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (Paciente), 1, pFile);

    fclose(pFile);

    return resultado;
}

Paciente PacienteArchivo::leer(int index)
{
    Paciente reg;
    FILE *pFile;

    pFile = fopen("pacientes.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (Paciente), SEEK_SET);

    fread(&reg, sizeof(Paciente), 1, pFile);

    fclose(pFile);

    return reg;
}

void PacienteArchivo::leerTodos(Paciente registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("pacientes.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(Paciente), cantidad, pFile);

    fclose(pFile);
}

int PacienteArchivo::buscarByDni(int dni)
{
    Paciente reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("pacientes.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Paciente), 1, pFile))
    {
        if(reg.getDni() == dni && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int PacienteArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("pacientes.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Paciente);

    fclose(pFile);

    return tam;
}


