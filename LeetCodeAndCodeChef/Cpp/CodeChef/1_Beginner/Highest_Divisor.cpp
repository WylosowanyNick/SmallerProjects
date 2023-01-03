#include <iostream>

using namespace std;

int func(int n)
{
    for(int i=10; i>-1; i--)
        if(n%i==0)
            return i;
}

int main()
{
    int n;
    
    cin >> n;
    cout << func(n) << endl;
}