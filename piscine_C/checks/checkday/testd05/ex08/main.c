#include <stdio.h>
#include <string.h>
char    *ft_strupcase(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 32);
        i++;
    }
    return (str);
}
int main()
{
    char p[100] = "asdf qWeRtY";
    printf("%s", ft_strupcase(p));
    
    return (0);
}
