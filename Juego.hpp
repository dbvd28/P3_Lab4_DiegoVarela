#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <random>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <string>
#include "Jugador.hpp"
using namespace std;
class Juego
{

public:
    static void Jugar(int num_jugadores, string nombre_jugador)
    {
        vector<Jugador *> jugadores;
        vector<string> baraja;
        Jugador *humano = new Jugador(nombre_jugador);
        jugadores.push_back(humano);
        while (num_jugadores < 2 || num_jugadores > 10)
        {
            cout << "Ingrese el numero correcto de jugadores de 2 a 10 porfavor:" << endl;
            cin >> num_jugadores;
        }
        for (int i = 1; i < num_jugadores; i++)
        {
            jugadores.push_back(new Jugador("Bot-" + to_string(i)));
        } //For que crea las cartas a la baraja
        for (int i = 1; i <= 13; i++)
        {
            if (i == 1)
            {
                baraja.push_back("A|O?");
                baraja.push_back("A|<3");
                baraja.push_back("A|-#");
                baraja.push_back("A|<>");
            }
            else if (i > 1 && i <= 10)
            {
                baraja.push_back(to_string(i) + "|O?");
                baraja.push_back(to_string(i) + "|<3");
                baraja.push_back(to_string(i) + "|-#?");
                baraja.push_back(to_string(i) + "|<>");
            }
            else if (i == 11)
            {
                baraja.push_back("J|O?");
                baraja.push_back("J|<3");
                baraja.push_back("J|-#");
                baraja.push_back("J|<>");
            }
            else if (i == 12)
            {
                baraja.push_back("Q|O?");
                baraja.push_back("Q|<3");
                baraja.push_back("Q|-#");
                baraja.push_back("Q|<>");
            }
            else if (i == 13)
            {
                baraja.push_back("K|O?");
                baraja.push_back("K|<3");
                baraja.push_back("K|-#");
                baraja.push_back("K|<>");
            }
        } //termina for de la baraja
        //shuffle de la baraja
        int size = baraja.size();
        for (int i = 0; i < 1000; i++)
        {
            int j = rand() % (size);
            int k = rand() % (size);
            swap(baraja[k], baraja[j]);
        } // Fin For
        //termina shuffle
        int num = 0;
        static int cartasasignadas = 0;
        //Asignar mano a jugador humano
        for (int i = 0; i < 3; i++)
        {
            jugadores[0]->mano.push_back(baraja.back());
            baraja.pop_back();
        } //termina de asignar la mano al humano
        //Asignar mano a jugador bot
        int cont = 1;
        while (cont < num_jugadores)
        {
            for (int i = 0; i < 3; i++)
            {
                jugadores[cont]->mano.push_back(baraja.back());
                baraja.pop_back();
            }
            cont++;
        } //termina de asignar la mano de los bots
        int cont_cartasagarradas = 0;
        int opcion;
        int cont1 = 0;
        //sacar la puntuacion de cada jugador
        for (int i = 0; i < jugadores.size(); i++)
        {
            for (int j = 0; j < jugadores[i]->mano.size(); j++)
            {
                if (jugadores[i]->mano[j] != "|")
                {
                    cont1++;
                }
                else
                {
                    string punt = jugadores[i]->mano[j].substr(0, cont1);
                    if (punt == "A")
                    {
                        jugadores[i]->puntuacion =1;
                    }
                    else if (punt == "J")
                    {
                        jugadores[i]->puntuacion = 11;
                    }
                    else if (punt == "Q")
                    {
                        jugadores[i]->puntuacion =12;
                    }
                    else if (punt == "K")
                    {
                        jugadores[i]->puntuacion = 13;
                    }
                    else if (punt == "2" || punt == "3" || punt == "4" || punt == "5" || punt == "6" || punt == "7" || punt == "8" || punt == "9" || punt == "10")
                    {
                        jugadores[i]->puntuacion = stoi(punt);
                    }
                }
            }
        }
        cout << jugadores[0]->nombre << ":";
        for (int i = 0; i < jugadores[0]->mano.size(); i++)
        {
            cout << jugadores[0]->mano[i] << ",";
        }
        cout << endl;
        cout << "Quiere agarrar una carta" << endl
             << "1) Si" << endl
             << "2) No" << endl;
        cin >> opcion;
        while (opcion == 1)
        { //manejo de puntuacion bots
            cont_cartasagarradas++;
            jugadores[0]->mano.push_back(baraja.back());
            baraja.pop_back();
            for (int i = 1; i < jugadores.size(); i++)
            {
                if (jugadores[i]->puntuacion <= 15)
                {

                    jugadores[i]->mano.push_back(baraja.back());
                    baraja.pop_back();
                }
                else if (jugadores[i]->puntuacion > 15 && jugadores[i]->puntuacion <= 25)
                {

                    jugadores[i]->mano.push_back(baraja.back());
                    baraja.pop_back();
                }
                else if (jugadores[i]->puntuacion > 25 && jugadores[i]->puntuacion <= 31)
                {
                    int numran = rand() % 100;
                    if (numran > 95)
                    {
                        jugadores[i]->mano.push_back(baraja.back());
                        baraja.pop_back();
                    }
                }
            } //fin manejo de bots
            //Mostrar cartas al usuario
            cout << jugadores[0]->nombre << ":";
            for (int i = 0; i < jugadores[0]->mano.size(); i++)
            {
                cout << jugadores[0]->mano[i] << ",";
            }
            cout << endl;
            cout << "Quiere agarrar una carta" << endl
                 << "1) Si" << endl
                 << "2) No" << endl;
            cin >> opcion;
        }
        int mayor = 1;

        for (int i = 0; i < jugadores.size(); i++)
        {
            if (jugadores[i]->puntuacion == 31)
            {
                cout << "1." << jugadores[i]->nombre << ":" << jugadores[i]->puntuacion << endl;
            }
            else if (jugadores[i]->puntuacion >= 31)
            {
                cout << "Perdedor" << jugadores[i]->nombre << ":" << jugadores[i]->puntuacion << endl;
            }
            else if (jugadores[i]->puntuacion <= 31)
            {
                cout <<mayor<<". "<<jugadores[i]->nombre<<":" << jugadores[i]->puntuacion << endl;
                mayor++;
            }
        }
    }
};
#endif