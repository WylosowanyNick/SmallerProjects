#include <iostream>
#include <string>
#include <set>

using namespace std;

bool func(string s, set<char> special_characters)
{
    bool b=false;
    int n=s.length();

    for(int i=0; i<n; i++)
        if(islower(s[i]))
        {
            b = true;
            break;
        }
    if(!b)
        return b;
    
    b=false;
    for(int i=1; i<n-1; i++)
        if(isupper(s[i]))
        {
            b = true;
            break;
        }
    if(!b)
        return b;
        
    b=false;
    for(int i=1; i<n-1; i++)
        if(isdigit(s[i]))
        {
            b = true;
            break;
        }
    if(!b)
        return b;

    b=false;
    for(int i=1; i<n-1; i++)
        if(special_characters.find(s[i]) != special_characters.end())
        {
            b = true;
            break;
        }
    if(!b)
        return b;
    
    if(n<10)
        return false;
    
    return true;
}

int main()
{
    int t;
    string s;

    set<char> special_characters;
    special_characters.insert('@');
    special_characters.insert('#');
    special_characters.insert('%');
    special_characters.insert('&');
    special_characters.insert('?');
    
    getline(cin, s);
    t = stoi(s);
    while(t--)
    {
        getline(cin, s);
        cout << ((func(s, special_characters)) ? "YES" : "NO") << endl;
    }
}