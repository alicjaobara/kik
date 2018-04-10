/**
* \file gra.h
* \brief Plik nagłówkowy modułu gra.
*/
#ifndef I_H
#define I_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "drzewo.h"
#include "tablice.h"
#include "interfejs.h"
using namespace std;
/** \brief Element do wpisywania wyników
*
* Definicja elementu potrzebnego przy wpisywaniu nowych wyników do pliku.
*/
struct osoba //struktura do wpisywania wyników
{
    ///nazwa danego gracza
    string nazwa;
    ///liczba wygranych gier danego gracza
    int wygrane;
    ///liczba zremisowanych gier danego gracza
    int remisy;
};
/** \brief Gra.
*
* Procedura przeprowadzająca grę.
*/
void gra();
/** \brief Wpisywanie ruchu do planszy.
*
* Procedura wpisująca dany znak do n-tego wolnego miejsca na planszy T.
* \param T plansza
* \param n numer ruchu
* \param znak znak do wpisania
*/
void wpisz_tab(char T[3][3], int n, char znak); //wpisuje znak do n-tego wolnego miejsca na planszy T
/** \brief Sprawdzanie sytuacji.
*
* Funkcja zwracająca w jakiej sytuacji znajduje się plansza.
* Zwraca 0-nieroztrzygnięta 1-wygrana kółka 2-wygrana krzyżyka 3-remis
* \param T plansza
* \return sytuacja
*/
int wygrana(char T[3][3]); //0-nieroz 1-'o' 2-'x' 3-remis
/** \brief Wpisywanie do wyników.
*
* Procedura dopisująca wyniku do pliku "wyniki.txt".
* \param l parametr mówiący czy dopisać wygraną(l=1), czy remis(l=0).
* \param nowe nowa nazwa gracza
*/
void wpisz_do_wyniki(int l, string nowe); //dopisuje nowe wyniki, l=1 gdy wygrana, l=0 gdy remis
/** \brief Nowa plansza.
*
* Procedura wypełniająca planszę znakami '-'.
* \param T plansza
*/
void nowa_plansza(char T[3][3]);//wypełnia plansze '-'

#endif // I_H
