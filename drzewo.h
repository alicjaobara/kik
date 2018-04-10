/**
* \file drzewo.h
* \brief Plik nagłówkowy modułu drzewo.
*/
#ifndef M_H
#define M_H
#include "gra.h"
/** \brief Element drzewa dynamicznego.
*
* Definicja elementu dynamicznego drzewa możliwych ruchów.
*/
struct wezel
{
    ///tablica - plansza
    char P[3][3];
    ///ilość możliwych do wykonania ruchów
    int nruchu;
    ///znak danego gracza 1-'x' 2-'o'
    int gracz; //1-'x'  2-'o'
    ///wykonywany ruch - numer kolejnego możliwego ruchu
    int nr; //numer wykonywanego ruchu
    ///sytuacja na planszy 0-nieroztrzygnięta 1-wygrana komputera 2-wygrana gracza 3-remis
    int sytuacja; //0-nieroz 1-komputer 2-gracz 3-remis
    ///wskaźnik na listę kolejnych elementów drzewa
    struct wsk *n;
};

/** \brief Element listy w drzewie dynamicznym.
*
* Definicja elementu listy dynamicznej w drzewie.
*/
struct wsk
{
    ///wskaźnika na kolejny element drzewa
    wezel *w;
    ///wskaźnik na kolejny element listy
    wsk *q;
};
/** \brief Nowe drzewo.
*
* Funkcja tworząca nowe drzewo wszystkich możliwych ruchów.
* \param T aktualna plansza
* \param znakk znak którym gra komputer
* \return korzeń nowego drzewa
*/
wezel* drzewo(char T[3][3],char znakk);
/** \brief Usuwanie drzewa.
*
* Procedura usuwająca drzewo.
* \param kor korzeń drzewa
*/
void usun_drzewo(wezel*& kor);
/** \brief Usuwanie listy w drzewie.
*
* Procedura pomocnicza przy usuwaniu drzewa, usuwająca listy dynamiczne zawarte w drzewie.
* \param n wskaźnik na pierwszy element listy
*/
void usun_bok(wsk*& n);
/** \brief Rekurencyjne tworzenie drzewa.
*
* Procedura rekurencyjna do tworzenia drzewa.
* \param pop wskaźnik poprzedniego elementu
* \param poziom ilość początkowych możliwych ruchów
* \param znakk znak którym gra komputer
*/
void t_drzewo(wezel* pop, int poziom, char znakk);
/** \brief Przepisywanie tablicy.
*
* Procedura przepisująca elementy z jednej tablicy do drugiej.
* \param T tablica do której przepisujemy elementy
* \param P tablica z której przepisujemy elementy
*/
void przepisz(char T[3][3],char P[3][3]); // T=P
/** \brief Ulepszenie drzewa.
*
* Procedura usuwająca inne ruchy możliwe dla gracza jeżeli ma możilwy ruch wygrywający.
* Procedura rekurencyjna.
* \param pop poprzedni element drzewa w funkcji rejkurencyjnej
*/
void lepsze(wezel* pop);
/** \brief Usuwanie ruchów.
*
* Procedura usuwająca inne możliwe ruchy gracza, gdy istnieje jego ruch wygrywający w danym poziomie drzewa.
* \param pop element drzewa
*/
void sprawdz_poziom(wezel* pop);

#endif // M_H
