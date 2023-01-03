#include <iostream>

using namespace std;

int main()
{
    int t, k, n, uncle_johny, cnt;

    cin >> t;
    while(t--)
    {
        cin >> n;
        int *tab = new int[n];
        for(int i=0; i<n; i++)
            cin >> tab[i];
        
        cin >> k;
        uncle_johny = tab[k-1];
        cnt = 1;
        for(int i=0; i<n; i++)
            if(tab[i]<uncle_johny)
                cnt++;
        
        cout << cnt << endl;
        
        delete []tab;
    }
}