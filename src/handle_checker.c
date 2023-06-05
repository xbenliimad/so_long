#include "so_long.h"

static void  ft_mapIsRectangle(char **map)
{
    int i;
    size_t line_size;

    line_size = ft_strlen(map[0]);
    i = 0;
    while (map[++i])
    {
        printf("i = %d\n", i);
        if (ft_strlen(map[i]) != line_size)
            ft_error("Error");
    }
}

static void ft_check_walls(char **map)
{
    int     i;
    int     j;
    t_map   map_size;

    map_size = ft_get_map_size(map);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[0][j] != '1' || map[map_size.rows - 1][j] != '1')
                ft_error("Error");
            j++;
        }
        if (map[i][0] != '1' || map[i][map_size.columns - 1] != '1')
            ft_error("Error");
        i++;
    }
}



void    ft_handle_checker(char **map)
{
    ft_mapIsRectangle(map);
    ft_check_walls(map);
}