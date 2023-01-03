#include <iostream>
#include <map>

int main()
{
    int T, N, x, i, ans;
    std::cin >> T;
    while(T--)
    {
        std::map<int, int> primepowers;
        std::cin >> N;
        while(N--)
        {
            std::cin >> x;
            for(i=2; i*i<=x; i++)
            {
                while(x%i == 0)
                {
                    x /= i;
                    primepowers[i]++;
                }
            }
            if(x > 1) primepowers[x]++;
        }
        ans = 1;
        for(auto& it : primepowers)
            ans *= it.second+1;
        
        std::cout << ans << '\n';
    }
}