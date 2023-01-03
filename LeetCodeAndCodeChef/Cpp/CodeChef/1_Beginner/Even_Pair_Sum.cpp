#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned long int a, b, a_mod, b_mod;

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        a_mod = a%2;
        b_mod = b%2;

        if(a_mod && b_mod)
            cout << ((a+1)/2)*((b+1)/2) + ((a-1)/2)*((b-1)/2) << endl;
        else if(~a_mod && b_mod)
            cout << (a/2)*((b+1)/2) + (a/2)*((b-1)/2) << endl;
        else if(a_mod && ~b_mod)
            cout << ((a+1)/2)*(b/2) + ((a-1)/2)*(b/2) << endl;
        else
            cout << 2*(a/2)*(b/2) << endl;
    }
}