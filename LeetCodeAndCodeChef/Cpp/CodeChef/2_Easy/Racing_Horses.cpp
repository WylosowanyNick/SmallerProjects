#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T, N, *tab=NULL, mini;

    cin >> T;
    while(T--)
    {
        cin >> N;
        tab = new int[N];
        for(int i=0; i<N; i++)
            cin >> tab[i];

        sort(tab, tab+N);
        mini=tab[1]-tab[0];
        for(int i=2; i<N; i++)
            if(tab[i]-tab[i-1]<mini)
                mini = tab[i] - tab[i-1];

        delete [] tab;

        cout << mini << endl;
    }
}