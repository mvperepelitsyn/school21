#include <stdio.h>
#include <string.h>
int    ft_str_is_printable(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 32 || str[i] == 127)
            return (0);
        i++;
    }
    return (1);
}

int main()
{
	char p[256] = "\n!@#$^&*()_+-=[]{}:;,./<>?";
    printf("%d", ft_str_is_printable(p));
    return (0);
}
