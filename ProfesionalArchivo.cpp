#include <iostream>
#include <cstring>
#include "ProfesionalArchivo.h"
#include "Profesional.h"

using namespace std;

bool ProfesionalArchivo::grabarRegistro(Profesional obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ProfesionalArchivo::listarRegistros(){
    FILE *p;
    Profesional obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
            obj.mostrar();
            cout<<endl;
    }
    fclose(p);
    return true;
}

int ProfesionalArchivo::buscarRegistro(int num){
    FILE *p;
    Profesional obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getMatricula()==num){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

Profesional ProfesionalArchivo::leerRegistro(int pos){
    FILE *p;
    Profesional obj;
    p=fopen(nombre, "rb");
    obj.setMatricula(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ProfesionalArchivo::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Profesional);
}

void ProfesionalArchivo::altaProfesional(){
    Profesional reg;
    ProfesionalArchivo archiProf("Profesionales.dat");
    reg.cargar();
    archiProf.grabarRegistro(reg);
}

void ProfesionalArchivo::listarProfesionales(){
    ProfesionalArchivo archiProf("Profesionales.dat");
    archiProf.listarRegistros();

}

bool ProfesionalArchivo::modificarRegistro(Profesional obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

void ProfesionalArchivo::bajaLogicaProfesional(){
    Profesional reg;
    ProfesionalArchivo archiProf("Profesionales.dat");
    cout<<"Ingrese el nro de matricula a eliminar: ";
    int num;
    cin>>num;
    int pos=archiProf.buscarRegistro(num);
    if(pos<0){
        cout<<"No se encontró el registro."<<endl;
        return;
    }
    reg=archiProf.leerRegistro(pos);
    reg.mostrar();
    cout<<"¿ESTA SEGURO DE ELIMINAR EL REGISTRO? (S/N) ";
    char respuesta;
    cin>>respuesta;
    if(respuesta=='S' || respuesta =='s'){
        reg.setEstado(false);
        if(archiProf.modificarRegistro(reg,pos)){
            cout<<"REGISTRO ELIMINADO";
        }
        else{
            cout<<"NO SE PUDO ELIMINAR EL REGISTRO";
        }
        cout<<endl;
    }
}

