#include "bsq.h"

int                find(char *str, char c)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

unsigned short    get_elem(unsigned short **m, int i, int j)
{
    if (i < 0 || j < 0)
        return (0);
    return (m[i][j]);
}

int                fill_cell(unsigned short **arr, int row, int col, char c)
{
    if (c == g_settings.obstacle)
        arr[row][col] = 0;
    else if (c == g_settings.empty)
    {
        arr[row][col] = 1 + min(get_elem(arr, row, col - 1),
                                get_elem(arr, row - 1, col - 1), get_elem(arr, row - 1, col));
       if (arr[row][col] > g_settings.max.size)
        {
            //printf("set = %d %d %d\n", row, col, arr[row][col]);
            set_max(arr[row][col], row, col);
        }
    }
    else
        return (0);
    return (1);
}

char            *ft_strcpy(char *dest, char *src)
{
    int i;
    
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
