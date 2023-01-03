// Array z wysokościami słupków. Znajdź maksymalną objętość naczynia
// utworzonego z tych, dwóch słupków.
// https://leetcode.com/problems/container-with-most-water/
// Słaba implementacja

#include <vector>

class Solution
{
public:
  int maxArea(std::vector<int>& height)
  {
    int res=0;
    
    // Inicjalizowanie maksimum
    for(int i=1; i<height.size(); i++)
    {
      int currentVolume = GetVolume(0, height[0], i, height[i]);
      if(currentVolume > res) res = currentVolume;
    }

    for(int i=1; i<height.size(); i++)
    {
      if(!height[i]) continue;

      for(int j=i+res/height[i]; j<height.size(); j++)
      {
        int currentVolume = GetVolume(i, height[i], j, height[j]);
        if(currentVolume > res) res = currentVolume;
      }
    }

    return res;
  }

private:
  inline int GetVolume(int ind1, int height1, int ind2, int height2)
  {
    return (ind2-ind1) * (height1<height2 ? height1 : height2);
  }
};
