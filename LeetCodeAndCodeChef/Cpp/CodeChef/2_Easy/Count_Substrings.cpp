#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n;
    long int cnt;
    string s;

    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;

        cnt = 0;
        for(int i=0; i<n; i++)
            if(s[i]=='1')
                cnt++;
        
        cout << cnt*(cnt+1)/2 << endl;
    }
}