#include <stdio.h>
#include <string.h>
int    ft_str_is_lowercase(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return (0);
        i++;
    }
    return (1);
}
int main()
{
    char p[150] = "asdF";
    printf("%d", ft_str_is_lowercase(p));
    return (0);
}
