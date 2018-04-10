/**
* \file tablice.h
* \brief Plik nagłówkowy modułu tablice.
*/
#ifndef A_H
#define A_H

#include "drzewo.h"
/** \brief Element listy dynamicznej tablic.
*
* Definicja elementu dynamicznej lity tablic.
* Tablice zawierają liczbę wygranych, remisów i przegranych dla kopmutera dla jednego poziomu drzewa.
*/
struct tab
{
    ///wskaźnik tablicy liczby wygranych gier
    int *W; //tablica wygranych
    ///wskaźnik tablicy liczby zremisowanych gier
    int *R; //tablica remisów
    ///wskaźnik tablicy liczby przegranych gier
    int *P; //tablica przegranych
    ///numer kolejnego wykonywanego ruchu w drzewie / poziom drzewa
    int nruchu; //numer wykonanego ruchu
    ///wskaźnik na następny element listy
    tab *nast;
};
/** \brief Deklaracja struktury wezel zdefiniowanej w module drzewo.
* \see wezel
*/
struct wezel;
/** \brief Deklaracja struktury wsk zdefiniowanej w module drzewo.
* \see wsk
*/
struct wsk;
/** \brief Tworzenie listy.
*
* Procedura rekurencyjna tworząca nową listę tablic.
* \param t poprzedni element listy
* \param N liczba możliwych do wykonania przez kompuer ruchów
* \param pop element drzewa, z którego zczytywane są liczby wygranych, przegranych i remisów dla następnego ruchu
* \param licznik numer określający, który to z kolei wykonywany ruch
* \param nr numer wykonywanego ruchu
*/
void lista_tab(tab *&t, int N, wezel *pop, int licznik, int nr);
/** \brief Usuwanie listy.
*
* Procedura rekurencyjna usuwająca listę tablic.
* \param k głowa listy
*/
void usun_tab(tab *&k);
/** \brief Wybór ruchu komputera.
*
* Funkcja zwracająca numer ruchu do wykonania dla komputera na podstawie listy tablic.
* \param x głowa listy
* \param N liczba możliwych do wykonania ruchów
* \return numer ruchu
*/
int ruch_komp(tab *x, int N);
/** \brief Tworzenie nowej tablicy.
*
* Funkcja tworząca nową tablicę jednowymiarową dynamiczną o wielkości N i zwracająca jej wskaźnik.
* \param N wielkość tablicy
* \return wskaźnik tablicy
*/
int *nowa_tab(int N);
/** \brief Sprawdznie czy tablica jest pełna.
*
* Funkcja sprawdzająca czy dana tablica T ma jakieś pole równe 0, wówczas zwracająca false.
* \param T wskaźnik tablicy
* \param N wielkość tablicy
* \return czy tablica jest pełna
*/
bool czy_pelna_tab(int *T, int N);
/** \brief Sprawdznie czy tablica jest prawie pełna.
*
* Funkcja sprawdzająca czy dana tablica T ma dokładnie jedno pole równe 0, wówczas zwracająca true.
* \param T wskaźnik tablicy
* \param N wielkość tablicy
* \return czy tablica jest prawnie pełna
*/
bool czy_prawie_pelna_tab(int *T, int N);


#endif // A_H
