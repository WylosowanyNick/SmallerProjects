// String. Zwróć najdłuższy substring bez powtarzających się liter.
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_set>

class Solution
{
public:
  int lengthOfLongestSubstring(std::string s)
  {
    std::unordered_set<char> m; unsigned short curMax=0;

    for(int i=0; i<s.size(); i++)
    {
      if(m.find(s[i]) == m.end())
        m.insert(s[i]);
      else
      {
        if(curMax < m.size()) curMax = m.size();

        m.clear();
        for(unsigned short j=i; j>-1; j--)
          if(m.find(s[j]) == m.end()) m.insert(s[j]);
          else break;
      }
    }
    if(curMax < m.size()) curMax = m.size();
    return curMax;
  }
};