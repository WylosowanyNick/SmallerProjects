#include <iostream>
#include <unordered_set>
#include <algorithm>

class MinAndMax
{
public:
    int a[2];

    void reinit()
    {
        a[0] = INT_MAX;
        a[1] = INT_MIN;
    }

    void push(const int& x)
    {
        if(x < a[0]) a[0] = x;
        if(x > a[1]) a[1] = x;
    }

    int operator[](const int& i) { return a[i]; }
};

int main()
{
    int T, N, a[10000], b[9999], i, ans, diff1, diff2;
    MinAndMax A, B;
    
    std::unordered_set<int> s;
    std::cin >> T;
    while(T--)
    {
        std::cin >> N;
        A.reinit(); B.reinit();
        for(i=0; i<N; i++) { std::cin >> a[i]; s.insert(a[i]); A.push(a[i]); }
        for(i=0; i<N-1; i++) { std::cin >> b[i]; B.push(b[i]); }

        diff1 = B[0] - A[0];
        diff2 = B[1] - B[1];
        if(diff1 == diff2) { std::cout << diff1 << '\n'; continue; }

        std::sort(a, a+N);
        std::sort(b, b+N-1);

        ans = b[0] - a[1];
        for(i=0; i<N-1; i++)
        {
            if(s.count(b[i] - ans) == 0)
            {
                ans = b[0] - a[0];
                break;
            }
        }

        if(ans <= 0) ans = b[0] - a[0];
        std::cout << ans << '\n';
    }
}