// https://leetcode.com/problems/roman-to-integer/
// Najlepsza

#include <string>

class Solution
{
public:
  int romanToInt(std::string s)
  {
    int res=0, i=0;

    while(i<s.length() && s[i]=='M') { res+=1000; i++; }

    while(i<s.length())
    {
      if(i+1<s.length())
        if(s[i]=='C' && s[i+1]=='M') { res += 900; i+=2; continue; }
        else if(s[i]=='C' && s[i+1]=='D') { res += 400; i+=2; continue; }
        else if(s[i]=='X' && s[i+1]=='C') { res += 90; i+=2; continue; }
        else if(s[i]=='X' && s[i+1]=='L') { res += 40; i+=2; continue; }
        else if(s[i]=='I' && s[i+1]=='X') { res += 9; i+=2; continue; }
        else if(s[i]=='I' && s[i+1]=='V') { res += 4; i+=2; continue; }
      
      if(s[i] == 'D') { res += 500; i++; continue; }
      else if(s[i] == 'C') { res += 100; i++; continue; }
      else if(s[i] == 'L') { res += 50; i++; continue; }
      else if(s[i] == 'X') { res += 10; i++; continue; }
      else if(s[i] == 'V') { res += 5; i++; continue; }
      else if(s[i] == 'I') { res += 1; i++; continue; }
    }

    return res;
  }
};