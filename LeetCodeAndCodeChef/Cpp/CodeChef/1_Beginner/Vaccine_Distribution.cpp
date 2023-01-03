#include <iostream>

using namespace std;

int main()
{
    int t, n, d, val, n_risk, n_normal, ans;

    cin >> t;
    while(t--)
    {
        n_normal = n_risk = ans = 0;
        cin >> n >> d;
        while(n--)
        {
            cin >> val;
            if(9<val && val<80)
                n_normal++;
            else
                n_risk++;
        }

        ans = 0;
        ans += ((n_risk%d==0) ? n_risk/d : n_risk/d+1);
        ans += ((n_normal%d==0) ? n_normal/d : n_normal/d+1);

        cout << ans << endl;
    }
}