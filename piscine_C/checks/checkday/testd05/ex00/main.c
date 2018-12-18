#include <stdio.h>
#include <string.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int a;
    
    a = 0;
    while (str[a])
    {
        ft_putchar(str[a]);
        a = a + 1;
    }
}

int main()
{
    ft_putstr("asdf");
    ft_putstr(" qwerty\n");
    ft_putstr("zxcv");
    return (0);
}
