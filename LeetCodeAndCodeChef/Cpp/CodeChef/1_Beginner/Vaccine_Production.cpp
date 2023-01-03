#include <iostream>

using namespace std;

int main()
{
    int d1, v1, d2, v2, p, d=0, v=0;
    cin >> d1 >> v1 >> d2 >> v2 >> p;

    while(v<p)
    {
        d++;
        if(d1<=d)
            v+=v1;
        
        if(d2<=d)
            v+=v2;
    }
    cout << d << endl;
}