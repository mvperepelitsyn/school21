#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int        ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strcpy(char *dest, char *src)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (src[x] != '\0')
    {
        dest[y] = src[x];
        x++;
        y++;
    }
    dest[y] = '\0';
    return (dest);
}

char    *ft_strdup(char *src)
{
    char *dup;
    
    dup = (char*)malloc(sizeof(*dup) * (strlen(src) + 1));
    dup = ft_strcpy(dup, src);
    return (dup);
}

int main()
{
    char p[40] = "What the hell is wrong with you?";
    char *d;
    
    d = ft_strdup(p);
    printf("%s", d);
    
    return (0);
}

