/**
* \file tablice.cpp
* \brief Plik źródłowy modułu tablice.
*/
#include "tablice.h"
void lista_tab(tab *&t, int N, wezel *pop, int licznik,int nr)
{
    if(pop!=0)
        if(pop->n!=0)
        {
            tab *x=NULL;
            if(t==0)
            {
                t=new tab;
                x=t;
                x->nast=NULL;
                x->R=nowa_tab(N);
                x->W=nowa_tab(N);
                x->P=nowa_tab(N);
                x->nruchu=licznik;
                licznik++;
            }
            else
            {
                x=t;
            }
            wsk *a=pop->n;
            while(a!=0)
            {
                if(a->w!=0)
                {
                    if(x->nruchu==1)
                    {
                        nr=a->w->nr-1;
                    }
                    if(a->w->sytuacja==1)
                    {
                        x->W[nr]++; //wygrana komp
                    }
                    if(a->w->sytuacja==2)
                    {
                        x->P[nr]++; //wygrana gracz
                    }
                    if(a->w->sytuacja==3)
                    {
                        x->R[nr]++; //remisy
                    }
                    lista_tab(x->nast,N,a->w,licznik,nr);
                }
                a=a->q;
            }
        }
}
void usun_tab(tab *&k)
{
    if(k!=0)
    {
        delete []k->P;
        delete []k->R;
        delete []k->W;
        usun_tab(k->nast);
        delete k;
        k=NULL;
    }
}
int* nowa_tab(int N)
{
    int *T;
    T=new int [N];
    for(int i=0;i<N;i++)
    {
        T[i]=0;
    }
    return T;
}
int ruch_komp(tab*t, int N)
{
    tab*x=t;
    {
        if(x!=0)
        {
            for(int i=0;i<N;i++)
            {
                if(x->W[i]!=0)
                {
                    return i+1; //wygrana po 1 ruchu komputera
                }
            }
            if(czy_pelna_tab(x->R,N))
            {
                return 1; //remis po 1 ruchu komputera nie ma innej opcji
            }
            if(x->nast!=0)
            {
                if(czy_pelna_tab(x->nast->P,N))
                {
                    return 1; //przegrał po ruchu gracza nie ma innej opcji
                }
                if(czy_prawie_pelna_tab(x->nast->P,N))
                {
                    for(int i=0;i<N;i++)
                    {
                        if(x->nast->P[i]==0)
                        {
                            return i+1;
                        }
                    }
                }
                int *sumaW; //suma wygranych dla danego ruchu
                sumaW=nowa_tab(N);
                int *sumap;
                sumap=nowa_tab(N);
                for(int i=0;i<N;i++)
                {
                    tab*a=x;
                    while(a!=0)
                    {
                        sumaW[i]+=a->W[i];
                        a=a->nast;
                    }
                }
                for(int i=0;i<N;i++)
                {
                    tab*a=x;
                    while(a!=0)
                    {
                        sumap[i]+=a->P[i];
                        a=a->nast;
                    }
                }
                int ip=0;
                for(int i=1;i<N;i++)
                {
                    if(sumap[i]>sumap[ip])ip=i;
                }
                int imax=0;
                for(int i=1;i<N;i++)
                {
                    if(sumap[i]!=sumap[ip])
                    {
                        if(sumaW[i]>sumaW[imax])imax=i;
                    }
                }
                delete []sumap;
                delete []sumaW;
                return imax+1;
            }
        }
    }
    return 1;
}
bool czy_pelna_tab(int *T, int N)
{
    for(int i=0;i<N;i++)
    {
        if(T[i]==0) return 0;
    }
    return 1;
}
bool czy_prawie_pelna_tab(int *T, int N)
{
    int l=0;
    for(int i=0;i<N;i++)
    {
        if(T[i]==0)
        {
            l++;
        }
    }
    if (l==1)return 1;
    return 0;
}
