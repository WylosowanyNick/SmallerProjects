#include <stdio.h>

using namespace std;

int main()
{
  int T, A, B;

  scanf("%d\n", &T);
  while(T--)
  {
    scanf("%d %d\n", &A, &B);
    printf("%d\n", A+B);
  }

  return 0;
}
