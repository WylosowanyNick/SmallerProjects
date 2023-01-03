#include <iostream>

using namespace std;

int main()
{
    int T, N;
    
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << ((N<10) ? "Thanks for helping Chef!" : "-1") << endl;
    }

    return 0;
}