#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, k;
    long int val, suma;

    cin >> t;
    while(t--)
    {
        cin >> n >> k;

        suma = 0;
        for(int i=1; ; i++)
        {
            if(n)
            {
                cin >> val;
                suma += val;
                n--;

                suma -= k;

                if(suma<0)
                {
                    while(n--)
                        cin >> val;

                    cout << i << endl;
                    break;
                }
            }
            else
            {
                cout << i + suma/k << endl;
                break;
            }
        }
    }
}