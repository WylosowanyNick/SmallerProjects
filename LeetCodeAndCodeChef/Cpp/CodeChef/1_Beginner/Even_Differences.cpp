#include <iostream>

using namespace std;

int main()
{
    int t, n, n_even, n_odd, val;

    cin >> t;
    while(t--)
    {
        cin >> n;

        n_even = n_odd = 0;
        while(n--)
        {
            cin >> val;
            if(val%2==0)
                n_even++;
            else
                n_odd++;
        }

        cout << min(n_even, n_odd) << endl;
    }
}