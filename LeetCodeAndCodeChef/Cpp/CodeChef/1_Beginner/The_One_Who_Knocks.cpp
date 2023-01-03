#include <iostream>

using namespace std;

int main()
{
    int t, x, y;

    cin >> t;
    while(t--)
    {
        cin >> x >> y;

        if(x<y)
            switch((y-x)%4)
            {
                case 0:
                    cout << 3 << endl;
                    break;
                case 1:
                    cout << 1 << endl;
                    break;
                case 2:
                    cout << 2 << endl;
                    break;
                case 3:
                    cout << 1 << endl;
            }
        else if(y<x)
            cout << (((x-y)%2==0) ? 1 : 2) << endl;
        else
            cout << 0 << endl;
    }
}