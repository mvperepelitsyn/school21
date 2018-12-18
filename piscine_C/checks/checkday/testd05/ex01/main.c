#include <stdio.h>
#include <string.h>
char    *ft_strcpy(char *dest, char *src)
{
    int x;
    
    x = 0;
    while (src[x] != '\0')
    {
        dest[x] = src[x];
        x++;
    }
    dest[x] = '\0';
    return (dest);
}

int main()
{
    char p[5] = "Hello";

    ft_strcpy( p, "ld");
    printf("%s", p);
    
    return (0);
}
