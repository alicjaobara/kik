/**
* \file drzewo.cpp
* \brief Plik źródłowy modułu drzewo.
*/
#include "drzewo.h"
void t_drzewo(wezel* pop, int poziom, char znakk)
{
    //poziom to ilosc początkowych mozliwych ruchów, a znakk to symbol komputera
    if(pop!=0)
    {
        wsk* a=NULL;
        pop->n=new wsk;
        a=pop->n;
        a->q=NULL;
        a->w=NULL;
        for(int i=0;i<pop->nruchu;i++)
        {
            wezel* akt;
            a->w=new wezel;
            akt=a->w;
            akt->n=NULL;
            akt->nruchu=pop->nruchu-1;
            akt->nr=i+1;
            przepisz(akt->P,pop->P);
            akt->gracz=(pop->gracz+1)%2;
            char znak;
            if(akt->gracz==1) znak='x';
            else znak='o';
            {
                wpisz_tab(akt->P,i+1,znak);
            }
            akt->sytuacja=wygrana(akt->P);
            if(znakk=='x')
            {
                if(akt->sytuacja==1) akt->sytuacja=2;
                else
                {
                    if(akt->sytuacja==2) akt->sytuacja=1;
                }
            }
            if(akt->sytuacja==0 && akt->nruchu>0 /*&&(poziom-(pop->nruchu))<2*/) t_drzewo(akt,poziom,znakk);
            a->q=new wsk;
            a->q->q=NULL;
            a->q->w=NULL;
            a=a->q;
        }
    }
}
void usun_bok(wsk*& n)
{
    if(n!=0)
    {
        if(n->q!=0)
        {
            usun_drzewo(n->q->w);
            usun_bok(n->q);
        }
        delete n;
        n=NULL;
    }
}
void usun_drzewo(wezel *&kor)
{
    if(kor!=0)
    {
        if(kor->n!=0)
        {
            if(kor->n->w!=0) usun_drzewo(kor->n->w);
            usun_bok(kor->n);
        }
        delete kor;
        kor=NULL;
    }
}
wezel* drzewo(char T[3][3], char znakk) //tworzy drzewo 3 kolejnych ruchów //znakk-znak komp
{
    wezel* korzen=NULL;
    korzen=new wezel;
    korzen->n=NULL;
    korzen->nr=0;
    przepisz(korzen->P,T);
    int p=0;
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(korzen->P[i][j]!='-')p++;
    korzen->nruchu=9-p;
    if(znakk=='x') korzen->gracz=0;
    else korzen->gracz=1;
    korzen->sytuacja=wygrana(T);
    t_drzewo(korzen,korzen->nruchu,znakk);
    return korzen;
}
void przepisz(char T[3][3],char P[3][3])
{
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            T[i][j]=P[i][j];
}
void lepsze(wezel* pop)
{
    wsk *akt=pop->n;
    while(akt!=0)
    {
        if(akt->w!=0)
        {
            wezel *a=akt->w;
            lepsze(a);
            sprawdz_poziom(a);
        }
        akt=akt->q;
    }
}
void sprawdz_poziom(wezel* pop)
{
    wsk *a=pop->n;
    wsk *np=NULL;
    wsk *pop_np=a;
    while(a!=0)
    {
        if(a->w!=0)
        {
            if(a->w->sytuacja==2)
            {
                np=a;
                goto wyjdz;
            }
        }
        pop_np=a;
        a=a->q;
    }
wyjdz:
    if(np!=NULL)
    {
        if(pop_np==np)
        {
            wsk *pom=pop->n->q;
            usun_bok(pom);
            pop->n->q=NULL;
        }
        else
        {
            wsk *pom=pop->n;
            pop->n=np;
            pop_np->q=np->q;
            np->q=NULL;
            usun_bok(pom);
        }
    }
}
