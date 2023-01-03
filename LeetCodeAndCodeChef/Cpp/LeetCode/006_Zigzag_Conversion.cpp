// https://leetcode.com/problems/zigzag-conversion/

#include <string>

class Solution
{
public:
  std::string convert(std::string s, int numRows)
  {
    int i, iter, sLen=s.size(), step=2*(numRows-1), j, step1, step2;

    if(numRows == 1) return s.substr(0);
    std::string res(sLen, '*');

    i=0; iter=0;
    while(iter < sLen)
    {
      res[i] = s[iter];
      i++; iter+=step;
    }

    for(j=1; j<numRows-1; j++)
    {
      iter=j;
      step1=2*(numRows-1-j);
      step2=2*j;

      while(iter < sLen)
      {
        res[i] = s[iter];
        i++; iter+=step1;
        if(iter >= sLen) break;
        res[i] = s[iter];
        i++; iter+=step2;
      }
    }

    iter=numRows-1;
    while(iter < sLen)
    {
      res[i] = s[iter];
      i++; iter+=step;
    }

    return res;
  }
};