/**
* \file interfejs.h
* \brief Plik nagłówkowy modułu interfejs.
*/
#ifndef INTERFEJS_H
#define INTERFEJS_H

#include "gra.h"
using namespace std;
/** \brief Wczytywanie int-ów.
*
* Funkcja wczytujaca od użytkownika zmienną typu int.
* \return wczytany int
*/
int wczytaj_int();
/** \brief Wypisywanie wyników.
*
* Procedura wypisująca tablicę wyników z pliku "wyniki.txt".
*/
void wyniki();
/** \brief Wypisanie planszy.
*
* Procedura wypisująca planszę.
* \param T plansza
*/
void drukuj_plansze(char T[3][3]);
/** \brief Wczytywanie ruchu.
*
* Funkcja wczytująca od użytkownika numer ruchu.
* \return numer ruchu
*/
int podaj_ruch();
/** \brief Wczytywanie od gracza wyboru znaku.
*
* Funkcja interfejsu, wczytujaca od użytkownika numer oznaczajązy jego wybór dotyczący tego jakim znakiem będzie grał.
* \return wybrany znak
*/
char wybierz_znak();
/** \brief Wczytywanie od gracza kto zaczyna.
*
* Funkcja interfejsu, wczytujaca od użytkownika numer oznaczajązy jego wybór dotyczący tego kto zacznie grę.
* \return wczytany numer
*/
int zaczyna();
/** \brief Wczytywanie nazwy.
*
* Funkcja interfejsu, wczytujaca od użytkownika jego nazwę do dopisania go do tablicy wyników.
* \return wczytana nazwa
*/
string podaj_nazwe();

#endif // INTERFEJS_H
