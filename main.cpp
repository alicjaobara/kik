#include "m.h"
#include "i.h"
using namespace std;
int main()
{
    cout<<"Start programu"<<endl;
    start:
    cout<<"Wybierz opcje: \n1. Nowa gra\n2. Wyniki\n3. Koniec programu"<<endl;
    int numer;
    do
        cin>>numer;
    while(numer<=0 || numer>=4);

    switch(numer)
    {
        case 1: gra(); break; //nowa gra;
        case 2: wyniki(); break; //wyniki;
        case 3: goto koniec; break; //koniec programu;
    }
    if(powroty()==1) goto start;
    else goto koniec;

    koniec:
    cout<<"Koniec pogramu."<<endl;
    return 0;
}
