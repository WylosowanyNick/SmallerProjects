#include <iostream>
#define ll long long

using namespace std;

ll func(ll n, ll tab[])
{
    if(n<12)
        return n;
    else if(tab[n] != 0)
        return tab[n];
    else
        return tab[n] = max(n, func(n/2, tab)+func(n/3, tab)+func(n/4, tab));
}

int main()
{
    ll n;
    while(cin >> n)
    {
        ll *tab = new ll [n+1];

        // Potrzebne, gdy pamiec nie jest dynamicznie alokowana
        // z wartosciami rownymi 0
        // for(int i=0; i<n+1; i++)
        //     tab[i] = 0;

        cout << func(n, tab) << endl;

        delete []tab;
    }
}