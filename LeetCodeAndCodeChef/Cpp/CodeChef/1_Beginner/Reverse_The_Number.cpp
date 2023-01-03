#include <iostream>

using namespace std;

int main()
{
    int t;
    string str;

    cin >> t;
    while(t--)
    {
        cin >> str;

        while(str.back()=='0')
            str.pop_back();

        for(int i=str.length()-1; i>-1; i--)
            cout << str[i];
        
        cout << endl;
    }

    return 0;
}