#include <stdio.h>

using namespace std;

int main()
{
  int t, n, j, next, size_of_array, result, tab[158]; // log10(100!) = 157.97;
  scanf("%d\n", &t);

  while(t--)
  {
    tab[0] = 1;
    size_of_array = 1;
    for(int i=1; i<158; i++)
    tab[i] = 0;

    // Krokami mnożenia liczby o znanej reprezentacji tablicowej miejsc
    // dziesiętnych (tablica ma znaną wielkość) są:
    // 1.Wymnożenie początkowego miejsca dziesiętnego,
    // 2.Dodanie nadmiarowej liczby na dalsze miejsce dziesiętne,
    // 3.Powtórzenie kroku 1 dla następnej pozycji miejsca dziesiętnego o ile:
    // Nadmiarowa liczba jest większa od 0 lub istnieje jeszcze niewymnożona
    // wartość w tablicy.
    // Tak otrzymana liczba powinna zostać wyświetlona idąc od ostatniego
    // niezerowego miejsca tablicy.
    scanf("%d\n", &n);
    for(int i=n; 1<i; i--)
    {
      j = 0;
      next = 0;
      do
      {
        result = tab[j]*i + next%10;
        tab[j] = result%10;
        next = next/10 + result/10;

        if(size_of_array == j)
        size_of_array = j+1;

        j++;
      }while(j<size_of_array || 0<next);
    }

    for(int i=size_of_array-1; 0<=i; i--)
    printf("%d", tab[i]);

    printf("\n");
  }
  return 0;
}
