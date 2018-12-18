#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int    *ft_range(int min, int max)
{
    int *a;
    int i;
    
    if (min >= max)
        return (0);
    a = (int*)malloc(sizeof(int) * (max - min));
    i = 0;
    while (min < max)
    {
        a[i] = min;
        i++;
        min++;
    }
    return (a);
}

int main()
{
    int* res;
    int i;
    res = ft_range(5, 10);
    for (i = 0; i < 5; i++)
        printf("%d,", res[i]);
    printf("\n");
    
    res = ft_range(-20, -15);
    for (i = 0; i < 5; i++)
        printf("%d,", res[i]);
    printf("\n");
    
    res = ft_range(100, 101);
    for (i = 0; i < 1; i++)
        printf("%d,", res[i]);
    printf("\n");
    
    res = ft_range(10, 5);
    printf("%" PRIxPTR "\n", (uintptr_t) res);
    
}
