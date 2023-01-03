// https://leetcode.com/problems/integer-to-roman/
// Zadowalająca mnie implementacja

#include <string>

class Solution
{
public:
  std::string intToRoman(int num)
  {
    std::string res;

    int step1 = num/1000;
    int step2 = (num%1000)/100;
    int step3 = (num%100)/10;
    int step4 = (num%10);

    res.append(step1, 'M');

    if(step2 == 9) res.append("CM");
    else if(step2 > 4) { res.append("D"); res.append(step2-5, 'C'); }
    else if(step2 == 4) res.append("CD");
    else res.append(step2, 'C');

    if(step3 == 9) res.append("XC");
    else if(step3 > 4) { res.append("L"); res.append(step3-5, 'X'); }
    else if(step3 == 4) res.append("XL");
    else res.append(step3, 'X');

    if(step4 == 9) res.append("IX");
    else if(step4 > 4) { res.append("V"); res.append(step4-5, 'I'); }
    else if(step4 == 4) res.append("IV");
    else res.append(step4, 'I');

    return res;
  }
};
