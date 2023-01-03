// Integer. Zwróć odwrócony integer.
// https://leetcode.com/problems/reverse-integer/

#include <string>

class Solution
{
public:
  int reverse(int x)
  {
    if(!x) return 0;
    
    if(x>0)
    {
      std::string xStr(std::to_string(x));

      int xStrLen=xStr.size(), lastNonZeroInd=xStrLen-1;
      while(xStr[lastNonZeroInd] == '0') lastNonZeroInd--;

      std::string res(lastNonZeroInd+1, '*');
      int i=0, j=lastNonZeroInd;
      while(j > -1)
      {
        res[i] = xStr[j];
        i++; j--;
      }

      if(res.size() < 10) return stoi(res);
      else // res.size() == 10
      {
        char tab[] = "2147483647";
        for(i=0; i<10; i++)
          if(res[i] > tab[i]) return 0;
          else if(res[i] < tab[i]) break;
        
        return stoi(res);
      }
    }
    else // x < 0
    {
      std::string xStr(std::to_string(x));

      int xStrLen=xStr.size(), lastNonZeroInd=xStrLen-1;
      while(xStr[lastNonZeroInd] == '0') lastNonZeroInd--;

      std::string res(lastNonZeroInd+1, '*');
      int i=1, j=lastNonZeroInd;
      while(j > 0)
      {
        res[i] = xStr[j];
        i++; j--;
      }
      res[0] = xStr[0];

      if(res.size() < 11) return stoi(res);
      else // res.size() == 11
      {
        char tab[] = "-2147483648";
        for(i=0; i<11; i++)
          if(res[i] > tab[i]) return 0;
          else if(res[i] < tab[i]) break;
        
        return stoi(res);
      }
    }
  }
};