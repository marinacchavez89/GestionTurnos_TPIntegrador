#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <locale.h>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

int CALLBACK EnumFontFamExProc(ENUMLOGFONTEX *lpelfe, NEWTEXTMETRICEX *lpntme, DWORD FontType, LPARAM lParam);

///Esto es en main. Se usa para saber las fuentes disponibles.
/*HDC hdc = GetDC(NULL);

LOGFONT lf;
ZeroMemory(&lf, sizeof(LOGFONT));
lf.lfCharSet = DEFAULT_CHARSET;

std::cout << "Fuentes disponibles:" << std::endl;

EnumFontFamiliesEx(hdc, &lf, (FONTENUMPROC)EnumFontFamExProc, NULL, 0);

ReleaseDC(NULL, hdc);

system("pause");*/

int CALLBACK EnumFontFamExProc(ENUMLOGFONTEX *lpelfe, NEWTEXTMETRICEX *lpntme, DWORD FontType, LPARAM lParam)
{
    std::cout << "- " << lpelfe->elfFullName << std::endl;
    return 1;
}

#endif // FUNCIONES_H_INCLUDED
