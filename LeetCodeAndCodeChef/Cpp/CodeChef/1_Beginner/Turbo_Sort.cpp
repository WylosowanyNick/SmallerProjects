#include <stdio.h>

using namespace std;

int main()
{
  int t, n, tab[1000001];
  for(int i=0; i<1000001; i++)
  tab[i] = 0;

  scanf("%d\n", &t);
  while(t--)
  {
    scanf("%d\n", &n);
    tab[n] += 1;
  }

  for(int i=0; i<1000001; i++)
  while(tab[i]--)
  printf("%d\n", i);

  return 0;
}
