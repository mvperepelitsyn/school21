#include <stdio.h>
#include <string.h>
char    *ft_strstr(char *str, char *to_find)
{
    int i;
    int index;
    
    i = 0;
    if (to_find[0] == '\0')
        return (str);
    while (str[i] != '\0')
    {
        index = 0;
        while (str[i + index] == to_find[index])
        {
            if (to_find[index + 1] == '\0')
                return (str + i); // adress of i's element
            index++;
        }
        i++;
    }
    return (0);
}
int main()
{
    printf("%s\n", ft_strstr("asdf qwerty", "wer"));
    printf("%s\n", ft_strstr("asdf qwerty qwerty", "wer"));
    printf("%s\n", ft_strstr("asdf qwerty", "qwerty1"));
    printf("%s\n", strstr("", "wer"));
    printf("%s\n", strstr("asdf qwerty", "zxcv"));
    printf("%s\n", strstr("asdf qwerty", ""));
    
    return (0);
}
