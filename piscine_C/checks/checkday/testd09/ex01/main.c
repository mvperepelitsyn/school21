#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *dest, char *src)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (src[x] != '\0')
    {
        dest[y] = src[x];
        x++;
        y++;
    }
    dest[y] = '\0';
    return (dest);
}
char *find_time(int hour)
{
    char time[5];
    
    if (hour > 12 && hour < 24)
        ft_strcpy( time, "P.M.");
    else
        ft_strcpy( time, "A.M.");
    return(time);
}

void ft_takes_place(int hour)
{
    char time[5];
    char time2[5];
    int h;
    
    ft_strcpy(time, find_time(hour));
    h = hour + 1;
    ft_strcpy(time2, find_time(h));
    if (hour < 0 || hour > 23)
        return ;
    else
    {
        printf("THE FOLLOWING TAKES PLACE BETWEEN ");
        if (hour > 12)
        {
            printf("%d.00 %s AND %d.00 %s\n", hour - 12, time, h - 12, time2);
        }
        printf("%d.00 %s AND %d.00 %s\n", hour, time, h, time2);
    }
}
int		main()
{
    ft_takes_place(12);
}
