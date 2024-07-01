#include <iostream>
using namespace std;
#include "ProfesionalManager.h"

Profesional ProfesionalManager::crear(){

    int dni, edad, matricula, idEspecialidad, consultorio, duracionTurno;
    string nombre, apellido, direccion, telefono;
    char genero;
    float honorario;
    Fecha fecha;

    cout << "DNI: ";
    cin >> dni;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Apellido: ";
    getline(cin, apellido);

    cout << "Fecha de nacimiento: ";
    fecha.cargar();

    cout << "Edad: ";
    cin >> edad;

    cout << "Direccion: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Telefono: ";
    getline(cin, telefono);

    cout << "Genero: ";
    cin >> genero;

    cout << "Nro de especialidad: ";
    cin >> idEspecialidad;

    cout << "Matricula: ";
    cin >> matricula;

    cout << "Consultorio: ";
    cin >> consultorio;


    cout << "Honorario: ";
    cin >> honorario;


    cout << "Duracion de turnos: ";
    cin >> duracionTurno;


    return Profesional(dni, nombre, apellido, fecha, edad, direccion, telefono, genero, true,
                       idEspecialidad, matricula, consultorio, honorario, duracionTurno);

}

void ProfesionalManager::cargar(Profesional &prof) {
    int dni, edad, matricula, idEspecialidad, consultorio, duracionTurno;
    string nombre, apellido, direccion, telefono;
    char genero;
    float honorario;
    Fecha fecha;

    cout << "DNI: ";
    cin >> dni;
    prof.setDni(dni);

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    prof.setNombre(nombre);

    cout << "Apellido: ";
    getline(cin, apellido);
    prof.setApellido(apellido);

    cout << "Fecha de nacimiento: ";
    fecha.cargar();
    prof.setFechaNacimiento(fecha);

    cout << "Edad: ";
    cin >> edad;
    prof.setEdad(edad);

    cout << "Direccion: ";
    cin.ignore();
    getline(cin, direccion);
    prof.setDireccion(direccion);

    cout << "Telefono: ";
    getline(cin, telefono);
    prof.setTelefono(telefono);

    cout << "Genero: ";
    cin >> genero;
    prof.setGenero(genero);

    cout << "Matricula: ";
    cin >> matricula;
    prof.setMatricula(matricula);

    cout << "Nro de especialidad: ";
    cin >> idEspecialidad;
    prof.setIdEspecialidad(idEspecialidad);

    cout << "Consultorio: ";
    cin >> consultorio;
    prof.setConsultorio(consultorio);

    cout << "Honorario: ";
    cin >> honorario;
    prof.setHonorario(honorario);

    cout << "Duracion de turnos: ";
    cin >> duracionTurno;
    prof.setDuracionTurno(duracionTurno);

    prof.setEstado(true);
}

void ProfesionalManager::mostrar(Profesional prof)
{
    if (prof.getEstado())
    {
        cout << "DNI: " << prof.getDni() << endl;
        cout << "Nombre: " << prof.getNombre() << endl;
        cout << "Apellido: " << prof.getApellido() << endl;
        cout << "Fecha de nacimiento: " << prof.getFechaNacimiento().toString() << endl;
        cout << "Edad: " << prof.getEdad() << endl;
        cout << "Direccion: " << prof.getDireccion() << endl;
        cout << "Telefono: " << prof.getTelefono() << endl;
        cout << "Genero: " << prof.getGenero() << endl;
        cout << "Matricula: " << prof.getMatricula() << endl;
        cout << "Nro de especialidad: " << prof.getIdEspecialidad() << endl;
        cout << "Consultorio: " << prof.getConsultorio() << endl;
        cout << "Honorario: " << prof.getHonorario() << endl;
        cout << "Duracion de turnos: " << prof.getDuracionTurno() << endl;
    }
}

void ProfesionalManager::agregar()
{
    Profesional nuevoProfesional = crear();

    if (archiProf.buscarByMatricula(nuevoProfesional.getMatricula()) != -1) {
        cout << "Ya existe el registro. No se puede duplicar." << endl;
        return;
    }

    if (archiProf.guardar(nuevoProfesional)) {
        cout << "¡El profesional fue guardado con éxito!" << endl;
    } else {
        cout << "No se pudo guardar el profesional." << endl;
    }
}

void ProfesionalManager::listar()
{
    system("cls");
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                            LISTADO PROFESIONALES                             |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
    int cantidad = archiProf.getCantidadRegistros();
    Profesional *profesionales;

    profesionales = new Profesional[cantidad];

    if(profesionales == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiProf.leerTodos(profesionales, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(profesionales[i].getEstado())
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            mostrar(profesionales[i]);
        }
    }

    delete [] profesionales;
}

void ProfesionalManager::modificar()
{
    int matricula, index;
    Profesional profesional;

    cout << "Ingrese el número de matricula a modificar: ";
    cin >> matricula;

    index = archiProf.buscarByMatricula(matricula);

    if(index != -1)
    {
        profesional = archiProf.leer(index);
        mostrar(profesional);
        cargar(profesional);
        if(archiProf.guardar(index, profesional))
        {
            cout << "¡Profesional modificado con éxito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el profesional." << endl;
        }
    }
    else
    {
        cout << "No se encuentra el profesional ingresado." << endl;
    }
}

void ProfesionalManager::eliminar()
{
    int matricula, index;
    Profesional profesional;
    char eliminar;

    cout << "Ingrese la matricula del profesional a eliminar: ";
    cin >> matricula;

    index = archiProf.buscarByMatricula(matricula);

    if(index != -1)
    {
        profesional = archiProf.leer(index);

        mostrar(profesional);

        cout << "Esta seguro de eliminar al profesional? S/N ";
        cin >> eliminar;

        if(eliminar == 'S' || eliminar == 's')
        {
            profesional.setEstado(false);

            if(archiProf.guardar(index, profesional))
            {
                cout << "¡Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el profesional." << endl;
            }
        }
        else
        {
            cout << "El profesional no fue eliminado." << endl;

        }
    }
    else
    {
        cout << "No se encuentra el profesional ingresado." << endl;
    }
}

void ProfesionalManager::buscarByMatricula(int matricula){

    int profesionalIndex = archiProf.buscarByMatricula(matricula);

    while(profesionalIndex == -1) {
        system("cls");
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                  PROFESIONAL INEXISTENTE. VERIFIQUE MATRICULA.                |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "Ingrese la matricula del profesional: ";
        cin >> matricula;
        profesionalIndex = archiProf.buscarByMatricula(matricula);
    }
    system("cls");
    Profesional profesional = archiProf.leer(profesionalIndex);
    cout << "********************************************************************************" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                          INFORMACION DEL PROFESIONAL                          |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "********************************************************************************" << endl;
    mostrar(profesional);
}

void ProfesionalManager::buscarPorApellido(string apellido){

    int cantidad = archiProf.getCantidadRegistros();
    Profesional *profesionales;

    profesionales = new Profesional[cantidad];

    if(profesionales == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiProf.leerTodos(profesionales, cantidad);
    bool encontrado = false;

    cout << "********************************************************************************" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                        INFORMACION DE LOS PROFESIONALES                       |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "********************************************************************************" << endl;
    for(int i=0; i<cantidad; i++)
    {
        string apeMayusReg = toUpperCase(profesionales[i].getApellido());
        string apeEvaluarMayus = toUpperCase(apellido);
        if(apeMayusReg == apeEvaluarMayus && profesionales[i].getEstado())
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            mostrar(profesionales[i]);
            cout << "--------------------------------------------------------------------------------"  << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                 SIN REGISTROS                                 |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
    }


    delete [] profesionales;
}

void ProfesionalManager::buscarPorEspecialidad(int idEspecialidad){

    int cantidad = archiProf.getCantidadRegistros();
    Profesional *profesionales;

    profesionales = new Profesional[cantidad];

    if(profesionales == nullptr)
    {
        cout << "No hay espacio en memoria." << endl;
        return;
    }

    archiProf.leerTodos(profesionales, cantidad);
    bool encontrado = false;

    cout << "********************************************************************************" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                        INFORMACION DE LOS PROFESIONALES                       |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "********************************************************************************" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(profesionales[i].getIdEspecialidad() == idEspecialidad && profesionales[i].getEstado())
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            mostrar(profesionales[i]);
            cout << "--------------------------------------------------------------------------------"  << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                 SIN REGISTROS                                 |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
    }

    delete [] profesionales;

}

