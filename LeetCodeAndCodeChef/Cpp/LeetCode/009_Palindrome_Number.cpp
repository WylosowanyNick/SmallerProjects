// Integer. Sprawdź, czy palindromiczny.
// https://leetcode.com/problems/palindrome-number/
// Najprostsza implementacja. std::to_string jest ciężkie obliczeniowo.

#include <string>

class Solution
{
public:
  bool isPalindrome(int x)
  {
    std::string s = std::to_string(x);
    int sLen = s.size();
    for(int i=0; i<sLen/2; i++)
      if(s[i] != s[sLen-1-i]) return false;

    return true;
  }
};
