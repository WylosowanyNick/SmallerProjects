// String. Zwróć najdłuższy palindromiczny substring.
// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>

class Solution
{
public:
  std::string longestPalindrome(std::string s)
  {
    int strLen=0, i,j, firstInd;
    for(i=0; i<s.size(); i++)
    {
      j=0;
      while(j<=i && i+j<s.size() && s[i-j] == s[i+j]) j++;
      j--;
      if(2*j+1 > strLen)
      {
        firstInd = i-j;
        strLen = 2*j+1;
      }
    }

    for(i=0; i<s.size()-1; i++)
    {
      j=0;
      while(j<=i && i+1+j<s.size() && s[i-j] == s[i+1+j]) j++;
      j--;
      if(2*j+2 > strLen)
      {
        firstInd = i-j;
        strLen = 2*j+2;
      }
    }

    return s.substr(firstInd, strLen);
  }
};