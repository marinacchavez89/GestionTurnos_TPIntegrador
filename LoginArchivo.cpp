#include <iostream>
using namespace std;
#include "LoginArchivo.h"

bool LoginArchivo::guardar(Login reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("logines.dat", "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    resultado = fwrite(&reg, sizeof (Login), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool LoginArchivo::guardar(int index, Login reg)
{
    bool resultado;
    FILE *pFile;

    pFile = fopen("logines.dat", "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Login) * index, SEEK_SET);

    resultado = fwrite(&reg, sizeof (Login), 1, pFile);

    fclose(pFile);

    return resultado;
}

Login LoginArchivo::leer(int index)
{
    Login reg;
    FILE *pFile;

    pFile = fopen("logines.dat", "rb");

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile, index * sizeof (Login), SEEK_SET);

    fread(&reg, sizeof(Login), 1, pFile);

    fclose(pFile);

    return reg;
}

void LoginArchivo::leerTodos(Login registros[], int cantidad)
{
    FILE *pFile;

    pFile = fopen("logines.dat", "rb");

    if(pFile == nullptr)
    {
        return;
    }

    fread(registros, sizeof(Login), cantidad, pFile);

    fclose(pFile);
}

int LoginArchivo::buscarByLegajo(int legajo)
{
    Login reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("logines.dat", "rb");
    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&reg, sizeof(Login), 1, pFile))
    {
        if(reg.getLegajo() == legajo && reg.getEstado())
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int LoginArchivo::getCantidadRegistros()
{
    FILE *pFile;
    int tam;

    pFile = fopen("logines.dat", "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Login);

    fclose(pFile);

    return tam;
}
