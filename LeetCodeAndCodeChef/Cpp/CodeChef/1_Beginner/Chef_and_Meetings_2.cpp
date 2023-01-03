#include <iostream>
#include <string>

using namespace std;

int func(string str1="12:01", string str2="PM")
// Function transforms AM/PM time to number
{
    int tab[2];
    tab[0] = stoi(str1.substr(0, 2));
    tab[1] = stoi(str1.substr(3, 2));
        
    if(str2=="AM")
        return (tab[0]==12) ? tab[1] : (60*tab[0]+tab[1]);
    else
        return (tab[0]==12) ? (60*tab[0]+tab[1]) : (60*(tab[0]+12)+tab[1]);
}

int main()
{
    string p1, p2, l1, l2, r1, r2;
    int n, chef_time, l, r, t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    cin >> t;
    while(t--)
    {
        cin >> p1 >> p2;
        chef_time = func(p1, p2);

        cin >> n;
        while(n--)
        {
            cin >> l1 >> l2 >>  r1 >> r2;
            l = func(l1, l2);
            r = func(r1, r2);

            cout << ((l <= chef_time && chef_time <= r) ? 1 : 0);
        }
        cout << endl;
    }
}