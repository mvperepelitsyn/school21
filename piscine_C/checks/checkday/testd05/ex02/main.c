#include <stdio.h>
#include <string.h>
int    ft_atoi(char *str)
{
    int i;
    int numb;
    int sign;
    
    i = 0;
    numb = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'\
           || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            sign = sign * (-1);
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        numb = (numb * 10) + str[i] - 48;
        i++;
    }
    numb = numb * sign;
    return (numb);
}

int main()
{
    char *Str = "a256a99999";
    int c = 0;
    c = ft_atoi(Str);
    printf("%d", c);
    
    return (0);
}
