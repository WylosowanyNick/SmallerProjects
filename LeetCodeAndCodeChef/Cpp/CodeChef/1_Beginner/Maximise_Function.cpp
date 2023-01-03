#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long int t, n, maks, mini, val;

    cin >> t;
    while(t--)
    {
        cin >> n;

        cin >> val;
        mini = maks = val;
        n--;

        while(n--)
        {
            cin >> val;
            if(val<mini)
                mini = val;
            
            if(maks<val)
                maks = val;
        }

        cout << 2*(maks-mini) << endl;
    }
}