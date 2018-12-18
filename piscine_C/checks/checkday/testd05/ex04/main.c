#include <stdio.h>
#include <string.h>
char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int x;
    
    x = 0;
    while ((src[x] != '\0') && (n > 0))
    {
        dest[x] = src[x];
        x++;
        n--;
    }
    if (n == 0)
        return (dest);
    dest[x] = '\0';
    return (dest);
}

int main()
{
    char p[256] = "MwbxBW";

    printf("%s\n", strncpy(p, "DvojIFFfHGAbJXzUjgPsyNGJJQsxIbYbpbZfpLFX", 18));
    printf("%s\n", strncpy(p, "qwerty", 4));
    printf("%s\n", strncpy(p, "z", 1));
     printf("%s\n", strncpy(p, "z", 1));
    
    return (0);
}
