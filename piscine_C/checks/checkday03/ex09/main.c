#include <stdio.h>


void    ft_sort_integer_table(int *tab, int size)
{
    int i;
    int k;
    int a;
    
    i = 0;
    while (i < size)
    {
        k = i + 1;
        while (k < size)
        {
            if (tab[i] > tab[k])
            {
                a = tab[i];
                tab[i] = tab[k];
                tab[k] = a;
            }
            k++;
        }
        i++;
    }
}

int main()
{
    int test1[] = {1,5,4,2,3};
    int size = 5;
    ft_sort_integer_table(test1, size);
    
    for (int i = 0; i < size; i++)
        printf("%d,", test1[i]);
}
