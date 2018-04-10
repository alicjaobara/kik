/**
* \file gra.cpp
* \brief Plik źródłowy modułu gra.
*/
#include "gra.h"
void nowa_plansza(char T[3][3])
{
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            T[i][j]='-';
}
void wpisz_tab(char T[3][3], int n, char znak)
{
    int k=0;
    int nruch=1;
    while(k!=n && nruch<10)
    {
        if (T[(nruch-1)/3][(nruch-1)%3]=='-') k++; //liczy wolne pola
        if (k==n) T[(nruch-1)/3][(nruch-1)%3]=znak;
        nruch++;
    }
}
int wygrana(char T[3][3])
{
    int suma3=0;
    int suma4=0;
    for (int i=0;i<3;i++)
    {
        int suma1=0;
        int suma2=0;
        suma3+=T[i][i];
        suma4+=T[i][2-i];
        for(int j=0;j<3;j++)
        {
            suma1+=T[i][j];
            suma2+=T[j][i];
        }
        if (suma1==333 || suma2==333) return 1; //wygrana 'o'
        if(suma1==360 || suma2==360) return 2; //wygrana 'x'
    }
    if (suma3==333 || suma4==333) return 1; //wygrana 'o'
    if (suma3==360 || suma4==360) return 2; //wygrana 'x'
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(T[i][j]=='-') return 0;
    return 3; //remis
}

void gra()
{
    char P[3][3];
    nowa_plansza(P);
    drukuj_plansze(P);
    int n=1;
    int w=0;
    int numer=zaczyna();
    char znak=wybierz_znak();
    char znakk;
    if(znak=='o') znakk='x';
    else znakk='o';
    while(!w)
    {
        if(n%2==numer)
        {
            int nruch=podaj_ruch();
            while(P[(nruch-1)/3][(nruch-1)%3]!='-')
            {
                cout<<"Niepoprawny ruch, podaj jeszcze raz"<<endl;
                nruch=podaj_ruch();
            }
            P[(nruch-1)/3][(nruch-1)%3]=znak;
        }
        else
        {
            wezel* korzen=drzewo(P,znakk);
            int N=korzen->nruchu;
            lepsze(korzen);
            tab *g=NULL;
            lista_tab(g,N,korzen,1,0);
            wpisz_tab(P,ruch_komp(g,N),znakk);
            usun_tab(g);
            usun_drzewo(korzen);
        }
        drukuj_plansze(P);
        n++;
        w=wygrana(P);
    }
    if(znak=='x')
    {
        if(w==1) w=2;
        else
        {
            if(w==2) w=1;
        }
    }
    if (w==1)
    {
        cout<<"WYGRANA"<<endl;
        wpisz_do_wyniki(1,podaj_nazwe());
        wyniki();
    }
    else
    {
        if (w==2) cout<<"PRZEGRANA"<<endl;
        else
        {
            cout<<"REMIS"<<endl;
            wpisz_do_wyniki(0,podaj_nazwe());
            wyniki();
        }
    }
}

void wpisz_do_wyniki(int l, string nowe) //l=wyg
{
    string s;
    int N=0;
    ifstream plikwej("wyniki.txt");
    if (plikwej.good())
        while(!plikwej.eof())
        {
            getline(plikwej,s);
            N++;
        }
    plikwej.close();
    if(N!=0)
    {
        osoba *T;
        T=new osoba[N];
        plikwej.open("wyniki.txt");
        if (plikwej.good())
            for(int i=0;i<N;i++)
            {
                plikwej>>T[i].nazwa;
                plikwej>>T[i].wygrane;
                plikwej>>T[i].remisy;
            }
        plikwej.close();
        bool czy=false;
        for(int i=0;i<N;i++)
        {
            if(nowe==T[i].nazwa)
            {
                if(l==1) T[i].wygrane++;
                else T[i].remisy++;
                czy=true;
            }
        }
        if(!czy)
        {
            ofstream wyj("wyniki.txt",ios_base::app);
            if(l==1) wyj<<endl<<nowe<<" 1 0";
            else  wyj<<endl<<nowe<<" 0 1";
            wyj.close();
        }
        else
        {
            ofstream wyj("wyniki.txt");
            for(int i=0;i<N-1;i++)
                wyj<<T[i].nazwa<<" "<<T[i].wygrane<<" "<<T[i].remisy<<endl;
            wyj<<T[N-1].nazwa<<" "<<T[N-1].wygrane<<" "<<T[N-1].remisy;
            wyj.close();
        }
        delete []T;
    }
    else
    {
        ofstream wyj("wyniki.txt");
        if(l==1) wyj<<nowe<<" 1 0";
        else  wyj<<nowe<<" 0 1";
        wyj.close();
    }
}
