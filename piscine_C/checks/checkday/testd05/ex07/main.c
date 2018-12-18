#include <stdio.h>
#include <string.h>
int    ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;
    
    i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i == n)
        return (0);
    if (s1[i] != '\0')
        return (s1[i]);
    if (s2[i] != '\0')
        return (-s2[i]);
    return (0);
}
int main()
{
    char p[100] = "asdsad";
    char c[100] = "asad";
    
   printf("%d", ft_strncmp(p, c, 3));
    
    return (0);
}
