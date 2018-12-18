#include <stdio.h>
#include <string.h>
char    *ft_strcat(char *dest, char *src)
{
    int i;
    int k;
    
    i = 0;
    k = 0;
    while (dest[i]!='\0')
        i++;
    printf("%d\n",i);
    while (src[k])
    {
        dest[i + k] = src[k];
        k++;
    }
    dest[i + k] = '\0';
    return (dest);
}
int main()
{
    char p[15] = "Hello";
    char c[] = "darkness";
    printf("%s", ft_strcat(p,c));
    return (0);
}
