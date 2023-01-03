#include <iostream>

struct Trio
{
    int f,s,t;
};

int main()
{
    int T,N;
    Trio c,p;

    std::cin >> T;
    while(T--)
    {
        p.f=2;
        std::cin >> N;
        while(N--)
        {
            std::cin >> c.f >> c.s >> c.t;
            if(c.s==c.t || c.f==1)
            {
                std::cout << "YES\n";
                p.f=1; p.s=c.s; p.t=c.t;
            }
            else if(p.f == 2)
            {
                std::cout << "NO\n";
            }
            else if(
                p.s<c.s && p.t<c.s &&
                p.s<c.t && p.t<c.t
            )
            {
                std::cout << "NO\n";
                p.f = 2;
            }
            else if(std::max(p.s, p.t) == std::min(c.s, c.t))
            {
                std::cout << "NO\n";
                p.f = 2;
            }
            else
            {
                std::cout << "YES\n";
                p.s=c.s; p.t=c.t;
            }
        }
    }
}
