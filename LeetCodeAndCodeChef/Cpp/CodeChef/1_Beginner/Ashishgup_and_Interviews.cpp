#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void func(int n, int k, int a[])
{
    int cnt=n;
    bool too_slow=false, bot=true;
    
    for(int i=0; i<n; i++)
        if(a[i]==-1)
            cnt--;
    
    for(int i=0; i<n; i++)
        if(k<a[i])
        {
            too_slow=true;
        }
    
    for(int i=0; i<n; i++)
        if(1<a[i])
        {
            bot=false;
            break;
        }
    
    for(int i=0; i<n; i++)
        if(a[i]==-1)
        {
            bot=false;
            break;
        }

    if(cnt<ceil(n/2.0))
        cout << "Rejected" << endl;
    else if(too_slow)
        cout << "Too Slow" << endl;
    else if(bot)
        cout << "Bot" << endl;
    else
        cout << "Accepted" << endl;
}

int main()
{
    int t, n, k;

    cin >> t;
    while(t--)
    {
        cin >> n >> k;

        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        func(n, k, a);
    }
}