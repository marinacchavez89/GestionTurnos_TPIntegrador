#include "Utils.h"

string toUpperCase(string palabra) {
    string palabraMayus = palabra;
    transform(palabraMayus.begin(), palabraMayus.end(), palabraMayus.begin(), ::toupper);
    return palabraMayus;
}
