// Array integerów. Zwróc wszystkie, różne od siebie trójki
// elementów arraya, które sumują się do 0.
// https://leetcode.com/problems/3sum/
// Poprawne, ale nie chce mi się tego optymalizować już

#include <vector>
#include <unordered_map>
#include <hash_set>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::hash_set;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    vector<vector<int>> res;
    hash_set<vector<int>> s;
    
    for(int i=0; i<nums.size(); i++)
    {
      unordered_map<int, vector<int>> m;
      for(int j=i+1; j<nums.size(); j++)
      {
        int sumOfTwo = nums[i]+nums[j];
        if(m.find(sumOfTwo) == m.end())
          m.insert({sumOfTwo, vector<int>({j})});
        else
          m[sumOfTwo].push_back(j);
      }
      
      for(int k=i+1; k<nums.size(); k++)
        if(m.find(-nums[k]) != m.end())
        {
          vector<int> v({nums[i],  nums[m[-nums[k]][0]], nums[k]}); sort(v.begin(), v.end());
          if(s.find(v) != s.end()) continue;

          for(auto& j : m[-nums[k]])
            if(j != k)
            {
              res.push_back(v);
              s.insert(v);
              break;
            }
        }
    }

    return res;
  }
};
