#include "so_long.h"

static void  ft_mapIsRectangle(char **map)
{
    int i;
    size_t line_size;

    line_size = ft_strlen(map[0]);
    i = 0;
    while (map[++i])
    {
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

t_map    ft_check_map_composition(char **map, int state)
{
    t_map   map_comp;
    int     i;
    int     j;

    i = -1;
    map_comp.collectible = 0;
    map_comp.starting_pos = 0;
    map_comp.map_exit = 0;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'C')
                map_comp.collectible++;
            else if (map[i][j] == 'P')
                map_comp.starting_pos++;
            else if (map[i][j] == 'E')
                map_comp.map_exit++;
            else if (state == 1 && (map[i][j] != '0' && map[i][j] != '1'))
                ft_error("Error");
        }
    }
    return (map_comp);
}

void    ft_handle_checker(char **map)
{
    t_map   map_comp;

    ft_mapIsRectangle(map);
    ft_check_walls(map);
    map_comp = ft_check_map_composition(map, 1);
    if (map_comp.collectible < 1 || map_comp.starting_pos != 1 || map_comp.map_exit != 1)
        ft_error("Error");
    ft_flood_fille(map);
}