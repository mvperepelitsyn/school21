#include <stdio.h>
#include <string.h>
char    *ft_strncat(char *dest, char *src, int nb)
{
    int i;
    int k;
    
    i = 0;
    k = 0;
    while (dest[i])
        i++;
    while (k < nb && src[k])
    {
        dest[i + k] = src[k];
        k++;
    }
    dest[i + k] = '\0';
    return (dest);
}
int main()
{
    char p[40] = "Hello\t";
    char c[40] = "darkness";
    printf("%s", ft_strncat(p,c, 10));
    return (0);
}
