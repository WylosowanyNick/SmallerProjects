#include <iostream>

using namespace std;

int main()
{
    int t, n;

    cin >> t;
    while(t--)
    {
        cin >> n;
        int * tab, sum;
        tab = new int[n];

        sum = 0;
        for(int i=0; i<n; i++)
            sum += tab[i];

        

        delete []tab;
    }

    return 0;
}
