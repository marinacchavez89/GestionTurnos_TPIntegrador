#include "AppManager.h"
#include "Utils.h"

int AppManager::menuLogin()
{

    int legajo, pass;
    int esAdmin;
    LoginArchivo loginArchi;

    system("cls");
    dibujarEncabezado();
    cout << "********************************************************************************" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                                   LOGIN                                       |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Ingrese Legajo (Solo n�meros)" << endl;
    cin >> legajo;
    cout << "Ingrese contrase�a" << endl;
    cin >> pass;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "********************************************************************************" << endl;

    if(loginArchi.buscarByLegajo(legajo) == -1){
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "********************************************************************************" << endl;
        cout << "                 Legajo inexistente. Intente logearse nuevamente.               " << endl;
        cout << "********************************************************************************" << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        system("pause");
        esAdmin = menuLogin();
    }

    Login evaluarUser = managerLogin.listar(legajo);

    if (evaluarUser.getLegajo() == legajo && evaluarUser.getPass() == pass)
    {
        if (evaluarUser.getUser() == 1)
        {
            esAdmin = 1;
        }
        else if (evaluarUser.getUser() == 2)
        {
            esAdmin = 2;
        }
        else
        {
            esAdmin = 3;
        }
    }

    return esAdmin;

}
void AppManager::configurarConsola()
{
    // Cambiar el tama�o de la ventana de la consola
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 79, 40};
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    // Cambiar el tama�o del buffer de la consola
    COORD bufferSize = {70, 20};
    SetConsoleScreenBufferSize(hOut, bufferSize);

    // Cambiar los colores de la consola
    SetConsoleTextAttribute(hOut, 15 | BACKGROUND_RED | BACKGROUND_BLUE);

    // Cambiar la fuente de la consola
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Ancho del car�cter
    cfi.dwFontSize.Y = 18;                  // Altura del car�cter
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Verdanas");      // Fuente a usar
    SetCurrentConsoleFontEx(hOut, FALSE, &cfi);
}
void AppManager::dibujarEncabezado()
{

    system("cls");

    // Dibuja un borde
    for(int i = 0; i < 80; ++i)
        std::cout << "-";
    std::cout << std::endl;

    // Dibuja el contenido
    std::cout << "|                              GESTI�N DE TURNOS                               |" << std::endl;

    // Dibuja un borde
    for(int i = 0; i < 80; ++i)
        std::cout << "-";
    std::cout << std::endl;
}
void AppManager::dibujarAdios()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "********************************************************************************" << endl;
    cout << "|                                   �ADIOS!                                    |" << endl;
    cout << "********************************************************************************" << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
}
void AppManager::errorOpcion()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "*******************************************************************************" << endl;
    cout << endl;
    cout<<  "                    Ingrese una opci�n correcta del menu.                      " <<endl;
    cout << endl;
    cout << "*******************************************************************************" << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    system("pause");
}
void AppManager::menuABMUsuarios()
{
    int opcionUsuarios;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                 MENU USUARIOS                                 |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta usuario" << endl;
        cout << "2  - Modificar usuario" << endl;
        cout << "3  - Eliminar usuario" << endl;
        cout << "4  - Listar usuario" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionUsuarios;

        switch(opcionUsuarios)
        {
        case 1:
            managerLogin.agregar();
            system("pause");
            break;
        case 2:
            managerLogin.modificar();
            system("pause");
            break;
        case 3:
            managerLogin.eliminar();
            system("pause");
            break;
        case 4:
            managerLogin.listar();
            system("pause");
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionUsuarios >= 0 || opcionUsuarios <= 4);

}
void AppManager::menuABMTurnos()
{
    int opcionTurnos;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                                 MENU TURNOS                                  |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta turno" << endl;
        cout << "2  - Modificar turno" << endl;
        cout << "3  - Eliminar turno" << endl;
        cout << "4  - Listar turnos" << endl;
        cout << "5  - Alta estado del turno" << endl;
        cout << "6  - Modificar estado del turno" << endl;
        cout << "7  - Eliminar estado del turno" << endl;
        cout << "8  - Listar estado de los turnos" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionTurnos;

        switch(opcionTurnos)
        {
        case 1:
            managerTurno.agregar();
            system("pause");
            break;
        case 2:
            managerTurno.modificar();
            system("pause");
            break;
        case 3:
            managerTurno.eliminar();
            system("pause");
            break;
        case 4:
            managerTurno.listar();
            system("pause");
            break;
        case 5:
            managerEstadoTurnos.agregar();
            system("pause");
            break;
        case 6:
            managerEstadoTurnos.modificar();
            system("pause");
            break;
        case 7:
            managerEstadoTurnos.eliminar();
            system("pause");
            break;
        case 8:
            managerEstadoTurnos.listar();
            system("pause");
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionTurnos >= 0 || opcionTurnos <= 8);

}
void AppManager::menuABMProfesionales()
{
    int opcionProfesionales;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                             MENU PROFESIONALES                                |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta profesional" << endl;
        cout << "2  - Modificar profesional" << endl;
        cout << "3  - Eliminar profesional" << endl;
        cout << "4  - Listar profesionales" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionProfesionales;

        switch(opcionProfesionales)
        {
        case 1:
            managerProfesional.agregar();
            system("pause");
            break;
        case 2:
            managerProfesional.modificar();
            system("pause");
            break;
        case 3:
            managerProfesional.eliminar();
            system("pause");
            break;
        case 4:
            managerProfesional.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionProfesionales >= 0 || opcionProfesionales <= 5);

}
void AppManager::menuABMPacientes()
{
    int opcionPacientes;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                               MENU PACIENTES                                  |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta paciente" << endl;
        cout << "2  - Modificar paciente" << endl;
        cout << "3  - Eliminar paciente" << endl;
        cout << "4  - Listar paciente" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionPacientes;

        switch(opcionPacientes)
        {
        case 1:
            managerPaciente.agregar();
            system("pause");
            break;
        case 2:
            managerPaciente.modificar();
            system("pause");
            break;
        case 3:
            managerPaciente.eliminar();
            system("pause");
            break;
        case 4:
            managerPaciente.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionPacientes >= 0 || opcionPacientes <= 5);

}
void AppManager::menuABMEspecialidades()
{
    int opcionEspecialidades;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                             MENU ESPECIALIDADES                               |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta especialidad" << endl;
        cout << "2  - Modificar especialidad" << endl;
        cout << "3  - Eliminar especialidad" << endl;
        cout << "4  - Listar especialidades" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionEspecialidades;

        switch(opcionEspecialidades)
        {
        case 1:
            managerEspecialidad.agregar();
            system("pause");
            break;
        case 2:
            managerEspecialidad.modificar();
            system("pause");
            break;
        case 3:
            managerEspecialidad.eliminar();
            system("pause");
            break;
        case 4:
            managerEspecialidad.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            system("pause");
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionEspecialidades >= 0 || opcionEspecialidades <= 5);

}
void AppManager::menuABMAgendaProfesionales()
{

    int opcionAgenda;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                          MENU AGENDA PROFESIONALES                            |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Alta horario" << endl;
        cout << "2  - Modificar horario" << endl;
        cout << "3  - Eliminar horario" << endl;
        cout << "4  - Listar horarios" << endl;
        cout << "5  - xxxxxxxxxxxxxx" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionAgenda;

        switch(opcionAgenda)
        {
        case 1:
            managerHorariosProf.agregar();
            system("pause");
            break;
        case 2:
            managerHorariosProf.modificar();
            system("pause");
            break;
        case 3:
            managerHorariosProf.eliminar();
            system("pause");
            break;
        case 4:
            managerHorariosProf.listar();
            system("pause");
            break;
        case 5:
            //Llamar a la funcion correspondiente.
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionAgenda >= 0 || opcionAgenda <= 5);

}
void AppManager::menuConsultasPacientes()
{
    int opcionPacientesConsultas;
    do
    {
        dibujarEncabezado();
        cout << "********************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "|                          MENU CONSULTAS PACIENTES                             |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1  - Buscar paciente por DNI" << endl;
        cout << "2  - Buscar paciente por apellido" << endl;
        cout << "3  - Buscar paciente por porcentaje de cobertura" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "********************************************************************************" << endl;
        cout << "0  - VOLVER MENU PRINCIPAL" << endl;
        cout << "Opcion: "<< endl;
        cin >> opcionPacientesConsultas;

        switch(opcionPacientesConsultas)
        {
        case 1:
            {
                system("cls");
                int dni;
                cout << "Ingrese el DNI del paciente." << endl;
                cin >> dni;
                managerPaciente.buscarByDni(dni);
                cout << endl;
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                cin.ignore();
                string apellido;
                cout << "Ingrese el apellido del paciente." << endl;
                getline(cin, apellido);
                string apellidoMayus = toUpperCase(apellido);
                managerPaciente.buscarPorApellido(apellidoMayus);
                cout << endl;
                system("pause");
                break;
            }
            system("pause");
            break;
        case 3:
            {
                system("cls");
                int cobertura;
                cout << "Ingrese la cobertura que desea buscar." << endl;
                cin >> cobertura;
                managerPaciente.buscarPorCobertura(cobertura);
                cout << endl;
                system("pause");
                break;
            }
            system("pause");
            break;
        case 0:
            return;
        default:
            errorOpcion();
            break;
        }
    }
    while(opcionPacientesConsultas >= 0 || opcionPacientesConsultas <= 3);
}
void AppManager::menuConsultasProfesionales()
{

}
void AppManager::menuConsultasTurnos()
{

}
void AppManager::menuPrincipal()
{
    bool estaLogueado = false;
    int esAdmin;
    while (!estaLogueado)
    {
        esAdmin = menuLogin();
        if (esAdmin == 1 || esAdmin == 2)
        {
            estaLogueado = true;
        }
        else
        {
            cout << endl;
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "********************************************************************************" << endl;
            cout << "|                       �USUARIO O CONTRASE�A INCORRECTA!                      |" << endl;
            cout << "********************************************************************************" << endl;
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << endl;
            system("pause");
        }
    }

    int opcion;
    do
    {
        system("cls");
        dibujarEncabezado();
        if(esAdmin==1)
        {
            cout << "********************************************************************************" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "|                             MENU ADMINISTRATIVO                               |" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "1  - Administrar turnos" << endl;
            cout << "2  - Administrar profesionales" << endl;
            cout << "3  - Administrar pacientes" << endl;
            cout << "4  - Administrar especialidades" << endl;
            cout << "5  - Administrar agenda profesionales" << endl;
            cout << "6  - Administrar usuarios" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
        }
        if(esAdmin==1 || esAdmin ==2)
        {
            cout << "********************************************************************************" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "|                                MENU REPORTES                                 |" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "7  - Recaudaci�n anual" << endl;
            cout << "8  - Recaudaci�n por profesional" << endl;
            cout << "9  - Recaudaci�n por especialidad" << endl;
            cout << "10 - Cantidad de turnos asignados" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "********************************************************************************" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "|                                MENU CONSULTAS                                |" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "11 - Consulta de pacientes" << endl;
            cout << "12 - Consulta de Profesionales" << endl;
            cout << "13 - Consulta de turnos" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "********************************************************************************" << endl;
            cout << "0  - SALIR" << endl;
            cout << "Opcion: "<< endl;
            cin >> opcion;
        }

        if(esAdmin==1)
        {
            switch(opcion)
            {
            case 1:
                menuABMTurnos();
                break;
            case 2:
                menuABMProfesionales();
                break;
            case 3:
                menuABMPacientes();
                break;
            case 4:
                menuABMEspecialidades();
                break;
            case 5:
                menuABMAgendaProfesionales();
                break;
            case 6:
                menuABMUsuarios();
                break;
            case 0:
                break;
            }
        }

        if(esAdmin == 1 || esAdmin==2)
        {
            switch(opcion)
            {
            case 7:
                system("cls");
                int anio;
                cout << "Ingrese el a�o que desea consultar su recaudaci�n anual: " << endl;
                cin >> anio;
                system("cls");
                managerTurno.recaudacionAnual(anio);
                system("pause");
                break;
            case 8:
                system("cls");
                int matricula;
                cout << "Ingrese la matricula del profesional que desea consultar la recaudaci�n: " << endl;
                cin >> matricula;
                system("cls");
                managerTurno.recaudacionPorProfesional(matricula);
                system("pause");
                break;
            case 9:
                system("cls");
                int idEspecialidad;
                cout << "Ingrese el ID de la especialidad que desea consultar la recaudaci�n: " << endl;
                cin >> idEspecialidad;
                system("cls");
                managerTurno.recaudacionPorEspecialidad(idEspecialidad);
                system("pause");
                break;
            case 10:
                system("cls");
                managerTurno.cantidadTurnosAsignados();
                system("pause");
                break;
            case 11:
                menuConsultasPacientes();
                break;
            case 12:
                menuConsultasProfesionales();
                break;
            case 13:
                menuConsultasTurnos();
                break;
            case 0:
                system("cls");
                dibujarAdios();
                break;
            }
            if((opcion < 1 || opcion > 13) && opcion !=0) {
                system("cls");
                errorOpcion();
            }
        }
    }
    while(opcion != 0);
}
