#include <iostream>

using namespace std;

void func(int n, int k, int x, int y)
{
    if(x<y)
    {
        switch(k%4)
        {
            case 1:
                cout << x+n-y << ' ' << n << endl;
                break;
            case 2:
                cout << n << ' ' << n-y+x << endl;
                break;
            case 3:
                cout << y-x << ' ' << 0 << endl;
                break;
            case 0:
                cout << 0 << ' ' << y-x << endl;
        }
    }
    else if(x==y)
    {
        cout << n << ' ' << n << endl;
    }
    else
    {
        switch(k%4)
        {
            case 1:
                cout << n << ' ' << y+n-x << endl;
                break;
            case 2:
                cout << n-x+y << ' ' << n << endl;
                break;
            case 3:
                cout << 0 << ' ' << x-y << endl;
                break;
            case 0:
                cout << x-y << ' ' << 0 << endl;
        }
    }
}

int main()
{
    int n, k, x, y, t;

    cin >> t;
    while(t--)
    {
        cin >> n >> k >> x >> y;
        func(n, k, x, y);
    }
}