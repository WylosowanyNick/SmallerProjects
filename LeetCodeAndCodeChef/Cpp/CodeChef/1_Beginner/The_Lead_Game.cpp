#include <iostream>

using namespace std;

int main()
{   
    // Pobieranie danych
    int N;
    cin >> N;

    int Si[N], Ti[N], res[N];
    cin >> Si[0] >> Ti[0];
    res[0] = Ti[0] - Si[0];

    int a, b;
    for(int i=1; i<N; i++)
    {
        cin >> a >> b;
        Si[i] = Si[i-1] + a;
        Ti[i] = Ti[i-1] + b;
        res[i] = Ti[i] - Si[i];
    }

    // Wybor zwycieskiego wyniku
    int ind=0, maks=abs(res[0]);
    for(int i=1; i<N; i++)
        if(maks<abs(res[i]))
        {
            ind=i;
            maks=abs(res[i]);
        }

    // Wybor zwyciezcy
    (0<res[ind]) ? cout << "2 " << res[ind] : cout << "1 " << -res[ind];

    return 0;
}