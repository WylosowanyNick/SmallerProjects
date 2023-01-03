#include <iostream>
#include <string>

using namespace std;

int func(string str)
{
    int tab[3];
    tab[0] = stoi(str.substr(0, 2));
    tab[1] = stoi(str.substr(3, 2));
    tab[2] = (str.substr(6, 2).compare("AM")) ? 0 : 1;
    
    if(tab[2])
        return (tab[0]==12) ? tab[1] : (60*tab[0]+tab[1]);
    else
        return (tab[0]==12) ? (60*tab[0]+tab[1]) : (60*(tab[0]+12)+tab[1]);
}

int main()
{
    int chef_time, n, t;
    string str;
    
    getline(cin, str);
    t = stoi(str);
    while(t--)
    {
        getline(cin, str);
        chef_time = func(str);
        
        getline(cin, str);
        n = stoi(str);

        for(int i=0; i<n; i++)
        {
            getline(cin, str);
            cout << ((func(str.substr(0, 8)) <= chef_time && chef_time <= func(str.substr(9, 8))) ? 1 : 0);
        }
        cout << endl;
    }
}