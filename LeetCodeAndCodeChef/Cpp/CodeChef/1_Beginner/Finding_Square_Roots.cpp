#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T, N;
    
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << (int) sqrt(N) << endl;
    }
    
    return 0;
}