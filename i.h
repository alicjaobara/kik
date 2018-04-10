#ifndef I_H
#define I_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "m.h"
using namespace std;
struct osoba //struktura do wpisywania wyników
{
    string nazwa;
    int wygrane;
    int remisy;
};

void wyniki();
int powroty();
void wpisz_do_wyniki(int l); //dopisuje nowe wyniki, l=1 gdy wygrana, l=0 gdy remis

void plansza(char T[3][3]);//wypełnia plansze '-'
void drukuj_plansze(char T[3][3]);
int podaj_ruch();
void wykonaj_ruch(char T[3][3],char znak);

void przepisz(char T[3][3],char P[3][3]); // T=P
void wpisz_tab(char T[3][3], int n, char znak); //wpisuje znak do n-tego wolnego miejsca na planszy T

int wygrana(char T[3][3]); //sprawdza czy wygrana, zwraca: 1-gracz, 2-koputer
bool remis(char T[3][3]); //sprawdza czy remis

char wybierz_znak();
int zaczyna();

void gra();


#endif // I_H
