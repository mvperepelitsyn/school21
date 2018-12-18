#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int    ft_ultimate_range(int **range, int min, int max)
{
    int s;
    int i;
    
    s = max - min;
    if (min >= max)
    {
        *range = 0;
        return (0);
    }
    *range = (int*)malloc(sizeof(int) * s);
    i = 0;
    while (min < max)
    {
        range[0][i] = min;
        i++;
        min++;
    }
    return (s);
}

int main()
{
    int* res = NULL;
    int i;
    int size;
    
    size = ft_ultimate_range(&res, 5, 10);
    printf("is_null? %d\n", res == NULL);
    printf("size is %i\n", size);
    for (i = 0; i < 5; i++)
        printf("%d,", res[i]);
    printf("\n");
    
    res = NULL;
    size = ft_ultimate_range(&res, -20, -17);
    printf("is_null? %d\n", res == NULL);
    printf("size is %i\n", size);
    for (i = 0; i < 3; i++)
        printf("%d,", res[i]);
    printf("\n");
    
    res = (int*)1;
    size = ft_ultimate_range(&res, 10, 5);
    printf("is_null? %d\n", res == NULL);
    printf("size is %i\n", size);
}
