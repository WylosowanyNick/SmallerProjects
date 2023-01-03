#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int dif = A-B;

    cout << ((dif%10==9) ? dif-1 : dif+1) << endl;

    return 0;
}