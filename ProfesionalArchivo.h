#pragma once
#include "Profesional.h"

class ProfesionalArchivo{
private:
    char nombre[30];
public:
    ProfesionalArchivo(const char *n="Profesionales.dat"){strcpy(nombre,n);}
    bool grabarRegistro(Profesional obj);
    bool listarRegistros();
    int buscarRegistro(int num);
    Profesional leerRegistro(int pos);
    int contarRegistros();
    void altaProfesional();
    void listarProfesionales();
    bool modificarRegistro(Profesional obj, int pos);
    void bajaLogicaProfesional();

};
