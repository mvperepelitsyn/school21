#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_strcat(char *dest, char *src)
{
    int i;
    int k;
    
    i = 0;
    k = 0;
    while (dest[i])
        i++;
    while (src[k])
    {
        dest[i + k] = src[k];
        k++;
    }
    dest[i + k] = '\0';
    return (dest);
}

int        ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_concat_params(int argc, char **argv)
{
    int i;
    int lel;
    char *str_p;
    
    i = 1;
    lel = 0;
    while (i < argc)
        lel += (ft_strlen(argv[i++]) + 1);
    str_p = (char*)malloc(sizeof(*str_p) * (lel + 1));
    i = 1;
    while (i < argc)
    {
        ft_strcat(str_p, argv[i]);
        if (i != (argc - 1))
            ft_strcat(str_p, "\n");
        i++;
        
    }
    str_p[lel] = '\0';
    return (str_p);
}
int main()
{
    char* arr[5] = {"0", "1", "2", "3", "4"};
    printf("%s", ft_concat_params(5, arr));
}
