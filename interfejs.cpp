/**
* \file interfejs.cpp
* \brief Plik źródłowy modułu interfejs.
*/
#include "interfejs.h"
int wczytaj_int()
{
    int numer;
    while(!(cin>>numer))
    {
      cout<<"Podaj wybor jeszcze raz"<<endl;
      cin.clear();
      cin.sync();
    }
    return numer;
}
void wyniki()
{
    string s;
    ifstream plikwej("wyniki.txt");
    if (plikwej.good())
    {
        cout<<"tablica wynikow\nnazwa gracza wygrane remisy"<<endl;
        while(!plikwej.eof())
        {
            getline(plikwej,s);
            cout<<setw(15)<<s<<endl;
        }
    }
    else cout<<"Nie ma pliku z wynikami"<<endl;
}
void drukuj_plansze(char T[3][3])
{
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<setw(5)<<T[i][j];
        cout<<endl;
    }
}
int podaj_ruch()
{
    cout<<"Podaj ruch"<<endl;
    int nruch=wczytaj_int();
    while(!(nruch>=1 && nruch<=9))
    {
        cout<<"Niepoprawny ruch, podaj jeszcze raz"<<endl;
        nruch=wczytaj_int();
    }
    return nruch;
}
char wybierz_znak()
{
    cout<<"Wybierz znak:"<<endl;
    cout<<"1.kolko\n2.krzyzyk"<<endl;
    int numer=wczytaj_int();
    while(!(numer==1 || numer==2))
    {
        cout<<"Podaj wybor jeszcze raz"<<endl;
        numer=wczytaj_int();
    }
    if (numer==1) return 'o';
    else return 'x';
}
int zaczyna()
{
    cout<<"Wybierz kto zaczyna:"<<endl;
    cout<<"1.zaczyna gracz\n2.zaczyna komputer"<<endl;
    int numer=wczytaj_int();
    while(!(numer==1 || numer==2))
    {
        cout<<"Podaj wybor jeszcze raz"<<endl;
        numer=wczytaj_int();
    }
    if (numer==1) return 1;
    else return 0;
}
string podaj_nazwe()
{
    string nowe;
    cout<<"Podaj nazwe"<<endl;
    while(!(cin>>nowe))
    {
      cout<<"Podaj wybor jeszcze raz"<<endl;
      cin.clear(); //kasowanie flagi błędu strumienia
      cin.sync(); //kasowanie zbędnych znaków z bufora
    }
    return nowe;
}
