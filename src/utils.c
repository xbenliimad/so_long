#include "so_long.h"

void    ft_error(char *message)
{
    ft_printf("%s\n", message);
    exit(1);
}

t_map   ft_get_map_size(char **map)
{
    t_map map_info;

    map_info.rows = 0;
    while(map[map_info.rows])
        map_info.rows++;
    map_info.columns = 0;
    while(map[0][map_info.columns])
        map_info.columns++;
    return (map_info);
}