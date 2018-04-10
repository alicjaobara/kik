#ifndef M_H
#define M_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include"i.h"
using namespace std;

struct wezel
{
    char P[3][3];
    int nruchu; //ilość możliwych do wykonania ruchów
    int sytuacja; //0, 1-wygrana, 2-remis
    int gracz;  //0-komputer, 1-gracz
    struct wsk *n;
};
struct wsk
{
    wezel *w;
    wsk *q;
};

void t_drzewo(wezel* pop);
void wypisz_drzewo(wezel* k);
void usun_bok(wsk*& n);
void usun_drzewo(wezel*& k);
wezel* drzewo(char T[3][3]);
int wybierz_ruch(wezel* k);

#endif // M_H
