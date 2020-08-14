#include "Juego.hpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cant_jugadores;
    string nombre;
    cout << "Ingrese su nombre:";
    cin >> nombre;
    cout << "Ingrese la cantidad";
    cin >> cant_jugadores;
    Juego::Jugar(cant_jugadores,nombre);
}