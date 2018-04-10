#include "i.h"
void wyniki()
{
    cout<<"tablica wynikow\nnazwa gracza wygrane remisy"<<endl;
    string s;
    ifstream plikwej("wyniki.txt");
    if (plikwej.good())
        while(!plikwej.eof())
        {
            getline(plikwej,s);
            cout<<setw(15)<<s<<endl;
        }
    else cout<<"blad pliku"<<endl;
};
int powroty()
{
    cout<<"1.Powrot\n2.Koniec programu"<<endl;
    int numer;
    do
        cin>>numer;
    while(!(numer==1 || numer==2));
    return numer;
};
void plansza(char T[3][3])
{
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            T[i][j]='-';
};
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
    int nruch;
    do
        cin>>nruch;
    while(!(nruch>=1 && nruch<=9));
    return nruch;
}
void wykonaj_ruch(char T[3][3],char znak)
{
    int nruch=podaj_ruch();
    while(T[(nruch-1)/3][(nruch-1)%3]!='-')
    {
        cout<<"niepoprawny ruch, podaj jeszcze raz"<<endl;
        nruch=podaj_ruch();
    }
    T[(nruch-1)/3][(nruch-1)%3]=znak;
}
int wygrana(char T[3][3])
{
    cout<<"program sprawdza czy wygrana"<<endl;
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
        if (suma1==333 || suma2==333) return 1;
        if(suma1==360 || suma2==360) return 2;
    }
    if (suma3==333 || suma4==333) return 1;
    if(suma3==360 || suma4==360) return 2;
    return 0;
}
bool remis(char T[3][3])
{
    cout<<"program sprawdza czy remis"<<endl;
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(T[i][j]=='-') return 0;
    return 1;
}
char wybierz_znak()
{
    cout<<"1.kolko\n2.krzyzyk"<<endl;
    int numer;
    do
        cin>>numer;
    while(!(numer==1 || numer==2));
    if (numer==1) return 'o';
    else return 'x';
}
int zaczyna()
{
    cout<<"1.zaczyna gracz\n2.zaczyna komputer"<<endl;
    int numer;
    do
        cin>>numer;
    while(!(numer==1 || numer==2));
    if (numer==1) return 1;
    else return 0;
}

void gra()
{
    char P[3][3];
    plansza(P);
    drukuj_plansze(P);
    int n=1;
    int r=0;
    int w=0;
    char znak=wybierz_znak();
    char znakk;
    if(znak=='o') znakk='x';
    else znakk='o';
    int numer=zaczyna();
    while(!w && !r)
    {
        if(n%2==numer)
            wykonaj_ruch(P,znak);
        else
        {
            cout<<"program buduje drzewo mozliwych gier, wybiera nie przegrywajacy ruch i komputer wykonuje ten ruch"<<endl<<endl;
            //wykonaj_ruch(P,'x');
            wpisz_tab(P,1,znakk);
        }
        drukuj_plansze(P);
        n++;
        w=wygrana(P); //cout<<"w="<<w<<endl;
        r=remis(P); //cout<<"r="<<r<<endl;
    }
    if(znak=='x')
    {
    if(w==1) w=2;
    else w=1;
    }
    if (w==1)
    {
        cout<<"WYGRANA GRACZ"<<endl;
        wpisz_do_wyniki(1);
        wyniki();
    }
    else
    {
    if (w==2) cout<<"WYGRANA KOMP"<<endl;
    else
    {
        cout<<"REMIS"<<endl;
        wpisz_do_wyniki(0);
        wyniki();
    }
    }
}

void wpisz_do_wyniki(int l)
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
    else cout<<"blad pliku"<<endl;
    plikwej.close();

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

    string nowe;
    cout<<"Podaj nazwe"<<endl;
    cin>>nowe;
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

void przepisz(char T[3][3],char P[3][3])
{
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            T[i][j]=P[i][j];
}
void wpisz_tab(char T[3][3], int n,char znak)
{
    int k=0;
    int nruch=1;
    while(k!=n)
    {
        if (T[(nruch-1)/3][(nruch-1)%3]=='-') k++;
        if (k==n) T[(nruch-1)/3][(nruch-1)%3]=znak;
        nruch++;
    }
}
