#include <iostream>

using namespace std;

int main()
{
    int t, g, i, n, q;

    cin >> t;
    while(t--)
    {
        cin >> g;
        while(g--)
        {
            cin >> i >> n >> q;

            if(n%2==0 || i==q)
                cout << n/2 << endl;
            else
                cout << (n+1)/2 << endl;
        }
    }
}