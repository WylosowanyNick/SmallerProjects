#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, cnt;
    string str;

    cin >> t;
    while(t--)
    {
        cnt = 0;
        cin >> str;

        for(int i=0; i<str.length(); i++)
        {
            if(str[i]=='4')
                cnt++;
        }

        cout << cnt << endl;
    }
    

    return 0;
}