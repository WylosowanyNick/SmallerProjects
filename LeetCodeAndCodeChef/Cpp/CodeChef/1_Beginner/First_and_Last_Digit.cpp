#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int t;

    cin >> t;
    
    while(t--)
    {
        cin >> str;
        cout << (int) (str[0]-'0') + (int) (str[str.length()-1]-'0') << endl;
    }

    return 0;
}