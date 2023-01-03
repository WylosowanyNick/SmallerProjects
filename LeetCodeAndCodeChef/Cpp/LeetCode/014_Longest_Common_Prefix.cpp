// Write a function to find the longest common prefix string
// amongst an array of strings.
// https://leetcode.com/problems/longest-common-prefix/
// Zadowalająca mnie implementacja

#include <string>
#include <vector>

class Solution
{
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs)
  {
    for(auto& str: strs)
      if(!str.length())
        return std::string();
    
    char trialChar = strs[0][0];
    for(auto& str : strs)
      if(str[0] != trialChar)
        return std::string();
    
    int i = 1;
    while(i<strs[0].length())
    {
      trialChar = strs[0][i];

      for(auto& str : strs)
        if(i>=str.length() || str[i]!=trialChar)
          return str.substr(0, i);
        
      i++;
    }

    return strs[0].substr(0, i);
  }
};