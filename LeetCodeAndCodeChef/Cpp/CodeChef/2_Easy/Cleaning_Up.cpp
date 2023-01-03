#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t, n, m, val;
    bool chef_flag;
    queue<int> chef, assistant;

    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        bool *tab = new bool[n]; // false indicates not finished task
        for(int i=0; i<n; i++)
            tab[i] = false;

        while(m--)
        {
            cin >> val;
            tab[val-1] = true;
        }

        chef_flag = true;
        for(int i=0; i<n; i++)
        {
            if(!tab[i])
                if(chef_flag)
                {
                    chef.push(i+1);
                    chef_flag = false;
                }
                else
                {
                    assistant.push(i+1);
                    chef_flag = true;
                }
        }

        if(!chef.empty())
        {
            cout << chef.front();
            chef.pop();
        }
        while(!chef.empty())
        {
            cout << ' ' << chef.front();
            chef.pop();
        }
        cout << endl;

        if(!assistant.empty())
        {
            cout << assistant.front();
            assistant.pop();
        }
        while(!assistant.empty())
        {
            cout << ' ' << assistant.front();
            assistant.pop();
        }
        cout << endl;
    }
}