// Tablica "nums" i liczba "target". Zwróć dwa indeksy tablicy nums,
// gdzie te dwa elementy sumują się do target.
// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>

class Solution
{
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target)
  {
    std::unordered_map<int, unsigned short> map;

    int complement; std::unordered_map<int, unsigned short>::const_iterator found;
    for(unsigned short i=0; i<nums.size(); i++)
    {
      complement = target - nums[i];

      found = map.find(complement);
      if(found != map.end())
        return {found->second, i};
        
      map.insert({nums[i], i});
    }

    return {};
  }
};