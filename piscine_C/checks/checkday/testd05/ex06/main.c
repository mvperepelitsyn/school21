#include <stdio.h>
#include <string.h>
int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 != '\0')
        return (*s1);
    if (*s2 != '\0')
        return (-*s2);
    return (0);
}

int main()
{
    char p[100] = "A";
    char c[100] = "A";
    
   printf("%d", ft_strcmp(p, c));
    
    return (0);
}
