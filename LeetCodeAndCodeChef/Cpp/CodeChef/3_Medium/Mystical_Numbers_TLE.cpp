#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, N, Q, L, R, X, cnt;

    std::cin >> T;
    while(T--)
    {
        std::cin >> N;
        int a[N];
        for(int i=0; i<N; i++)
            std::cin >> a[i];

        std::cin >> Q;
        while(Q--)
        {
            std::cin >> L >> R >> X;
            cnt = 0;
            for(int i=L-1; i<R; i++)
                if((X ^ a[i]) > (X & a[i]))
                    cnt++;

            std::cout << cnt << '\n';
        }
    }
}
