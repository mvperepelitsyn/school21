#include <stdio.h>
#include <string.h>
int        check(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' \
                                                             && c <= '9'))
        return (1);
    return (0);
}

char    *ft_strcapitalize(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (!check(str[i - 1]))
        {
            if ((str[i] >= 'a') && (str[i] <= 'z'))
                str[i] = (str[i] - 32);
        }
        else if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] = (str[i] + 32);
        i++;
    }
    return (str);
}

int main()
{
    char p[150] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    printf("%s", ft_strcapitalize(p));
    
    return (0);
}
