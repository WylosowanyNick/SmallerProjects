#include <iostream>

using namespace std;

bool func(int n, int m, int tab[])
{
    int two_to_n=(1<<n), suma, iterator=1;
    
    for(int i=1; i<two_to_n; i++)
    {
        suma=0;
        for(int j=0; j<n; j++)
            if((iterator>>j) & 1)
                suma += tab[j];
        
        if(suma == m)
            return true;
        iterator++;
    }
    
    return false;
}

int main()
{
    int t, n, m;

    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        int *tab = new int[n];
        for(int i=0; i<n; i++)
            cin >> tab[i];
        
        cout << ((func(n, m, tab)) ? "Yes" : "No") << endl;

        delete []tab;
    }
}