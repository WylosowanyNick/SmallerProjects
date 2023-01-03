#include <iostream>

using namespace std;

int func(int tab[], int s)
{
    int maks=tab[0];
    for(int i=1; i<s; i++)
        if(maks<tab[i])
            maks=tab[i];
    
    int sec_maks = (tab[0]<maks) ? tab[0] : tab[1];
    for(int i=1; i<s; i++)
        if(sec_maks<tab[i] && tab[i]<maks)
            sec_maks = tab[i];
    
    return sec_maks;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int tab[3];
        cin >> tab[0] >> tab[1] >> tab[2];
        cout << func(tab, 3) << endl;
    }
    
    return 0;
}