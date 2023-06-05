#include "so_long.h"

void    ft_error(char *message)
{
    ft_printf("%s\n", message);
    exit(1);
}

void    ft_free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
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
