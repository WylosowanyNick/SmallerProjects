#include <stdio.h>

using namespace std;

int main()
{
  int n, k, cnt=0, d;
  scanf("%d %d\n", &n, &k);

  while(n--)
  {
    scanf("%d\n", &d);

    if(d%k == 0)
    cnt++;
  }

  printf("%d", cnt);

  return 0;
}
