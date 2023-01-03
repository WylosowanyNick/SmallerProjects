// Dwie forward listy reprezentujące kolejne cyfry dwóch, pewnych liczb.
// Zwróc forward listę reprezentującą sumę tych dwóch, pewnych liczb.
// UWAGA: poniższa implementacja nie jest najlepsza.
// https://leetcode.com/problems/add-two-numbers/

// #include <iostream>

struct ListNode
{
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode *res=new ListNode, *currentRes=res, l1Copy, l2Copy;
    l1Copy.val = l1->val; l1Copy.next = l1->next; l2Copy.val = l2->val; l2Copy.next = l2->next;
    int addOne, val;

    val = l1Copy.val + l2Copy.val;
    if(val < 10)
    {
      currentRes->val = val;
      addOne = 0;
    }
    else
    {
      currentRes->val = val-10;
      addOne = 1;
    }

    while(l1Copy.next || l2Copy.next || addOne)
    {
      // Następne liczby
      if(l1Copy.next)
      {
        l1Copy.val=l1Copy.next->val; l1Copy.next=l1Copy.next->next;
      }
      else
        l1Copy.val=0;

      if(l2Copy.next)
      {
        l2Copy.val=l2Copy.next->val; l2Copy.next=l2Copy.next->next;
      }
      else
        l2Copy.val=0;

      // Następny node wynikowy
      currentRes->next = new ListNode;
      currentRes = currentRes->next;

      val = l1Copy.val + l2Copy.val + addOne;
      if(val < 10)
      {
        currentRes->val = val;
        addOne = 0;
      }
      else
      {
        currentRes->val = val-10;
        addOne = 1;
      }
    }

    return res;
  }
};

// int main()
// {
//   ListNode *l1=new ListNode, *l2=new ListNode, *currentL1=l1, *currentL2=l2, *res, *currentRes;
//   int t1[] = {9,9,9,9,9,9,9}, t2[] = {9,9,9,9}; // t1 i t2 muszą być niepustymi tablicami
//
//   // Ustawianie l1 i l2
//   currentL1->val=t1[0]; currentL2->val=t2[0];
//   for(int i=1; i<sizeof(t1)/sizeof(int); i++)
//   {
//     currentL1->next = new ListNode(t1[i]);
//     currentL1 = currentL1->next;
//   }
//   for(int i=1; i<sizeof(t2)/sizeof(int); i++)
//   {
//     currentL2->next = new ListNode(t2[i]);
//     currentL2 = currentL2->next;
//   }
//
//   currentL1 = l1; currentL2 = l2;
//   while(currentL1)
//   {
//     std::cout << currentL1->val << ' ';
//     currentL1 = currentL1->next;
//   }
//   std::cout << std::endl;
//   while(currentL2)
//   {
//     std::cout << currentL2->val << ' ';
//     currentL2 = currentL2->next;
//   }
//   std::cout << std::endl;
//
//   // Test
//   Solution solution = Solution();
//
//   res = solution.addTwoNumbers(l1, l2);
//
//   currentRes = res;
//   while(currentRes)
//   {
//     std::cout << currentRes->val << ' ';
//     currentRes = currentRes->next;
//   }
//   std::cout << std::endl;
// }