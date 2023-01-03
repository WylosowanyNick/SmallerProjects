// Zaimplementuj stoi (atoi).
// https://leetcode.com/problems/string-to-integer-atoi/
// Nie jest to najlepsza implementacja (złe sformułowanie problemu).

#include <string>
#define INT_MAX  2147483647
#define INT_MIN -2147483648

class Solution
{
public:
  int myAtoi(std::string s)
  {
    unsigned char sLen=s.size(), negate=0, firstInd, lastInd, numLen;
    int i=0, res=0;
    unsigned int tenPowers=1;

    while(i<sLen && s[i]==' ') i++;
    if(i==sLen) return 0;

    while(i<sLen && s[i]<'0' && s[i]>'9' && s[i]!='-' && s[i]!='+') i++;
    if(i==sLen) return 0;

    if(s[i]=='-')
    {
      negate = 1;
      if(++i==sLen) return 0;
      firstInd = i;
      while(i<sLen && s[i]>='0' && s[i]<='9') i++;
      lastInd = i;
    }
    else if(s[i]=='+')
    {
      if(++i==sLen) return 0;
      firstInd = i;
      while(i<sLen && s[i]>='0' && s[i]<='9') i++;
      lastInd = i;
    }
    else
    {
      firstInd = i;
      while(i<sLen && s[i]>='0' && s[i]<='9') i++;
      lastInd = i;
    }
    
    i = firstInd;
    while(i<sLen && s[i]=='0') i++;
    if(i==sLen) return 0;
    firstInd = i;

    numLen = lastInd - firstInd;
    if(numLen > 10) return (negate) ? INT_MIN : INT_MAX;
    if(numLen == 10)
      if(negate)
      {
        char tab[] = "2147483648";
        for(i=0; i<10; i++)
          if(s[i+firstInd]>tab[i]) return INT_MIN;
          else if(s[i+firstInd]<tab[i]) break;
      }
      else
      {
        char tab[] = "2147483647";
        for(i=0; i<10; i++)
          if(s[i+firstInd]>tab[i]) return INT_MAX;
          else if(s[i+firstInd]<tab[i]) break;
      }

    for(i=lastInd-1; i>=firstInd; i--)
    {
      res -= (s[i]-'0')*tenPowers;
      tenPowers *= 10;
    }

    return (negate) ? res : -res;
  }
};
