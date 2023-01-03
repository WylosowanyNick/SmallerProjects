#include <iostream>

int main()
{
    int T, A, B;
    std::cin >> T;
    while(T--)
    {
        std::cin >> A >> B;
        if(A != B) std::cout << (((A-B)%2) ? (B-A+1)/2 : (B-A+2)/2) << '\n';
        else std::cout << (B-A)/2 << '\n';
    }
}