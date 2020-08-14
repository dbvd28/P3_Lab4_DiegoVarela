#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <vector>
using namespace std;
class Jugador
{
private:
    string nombre;
    vector<string > mano;
    int puntuacion;
    friend class Juego;

public:
    Jugador(string _nombre)
    {
        nombre = _nombre;
        puntuacion = 0;
    }
    ~Jugador()
    {
    }
};
#endif