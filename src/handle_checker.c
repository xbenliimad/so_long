#include "so_long.h"

static void  ft_mapIsRectangle(char **map)
{
    int i;
    size_t line_size;

    line_size = ft_strlen(map[0]);
    i = 0;
    while (map[i])
    {
        printf("i = %d\n", i);
        if (ft_strlen(map[i]) != line_size)
            ft_error("Error");
        i++;
    }
}

// static int  ft_mapIsValid(char **map)
// {

// }

void    ft_handle_checker(char **map)
{
    ft_mapIsRectangle(map);
    printf("saulgood");
}