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
    char p[256] = "asdf";

    printf("%s", ft_strcpy(p, "qwerty\n"));
    printf("%s", ft_strcpy(p, "z"));
    // printf("%s", ft_strcpy(p, "hell0\n"));
    
    return (0);
}
