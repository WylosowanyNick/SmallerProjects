#include <iostream>

int main()
{
    int t, tab[3], suma;
    bool b;
    
    std::cin >> t;
    while(t--)
    {
        std::cin >> tab[0] >> tab[1] >> tab[2];

        suma = 0;
        for(int i=0; i<3; i++)
            suma += tab[i];

        b = false;
        for(int i=0; i<3; i++)
            if(suma == 2*tab[i])
            {
                b = true;
                break;
            }
        
        std::cout << ((b) ? "YES" : "NO") << std::endl;
    }
}