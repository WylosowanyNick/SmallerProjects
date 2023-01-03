#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t, n, a=0, i=1, inc;
    
    cin >> t;
    while(t--)
    {
    a=0;
    i=1;
    cin >> n;

    do
    {
        inc = n/pow(5, i);
        a += inc;
        i++;
    } while (inc);
    
    cout << a << endl;
    }

    return 0;
}