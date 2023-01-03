#include <iostream>
#include <limits.h>

int main()
{
    int T, N, X, mini, maxi, temp;
    std::cin >> T;
    while(T--)
    {
        std::cin >> N >> X;

        mini = INT_MAX; maxi = INT_MIN;
        for(int i=0; i<N; i++)
        {
            std::cin >> temp;
            if(temp < mini)
                mini = temp;

            if(temp > maxi)
                maxi = temp;
        }

        if(X<mini || X>maxi)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
}