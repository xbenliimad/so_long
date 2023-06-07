#include "so_long.h"

static int ft_check_component(char component)
{
    if (component != 'P' && component != 'C' && component != 'E' && component != '0')
        return (1);
    return (0);
}

static void    ft_dfs(char **map, int i, int j)
{
    t_map   map_info;

    map_info = ft_get_map_size(map);
    if (i < 0 || i >= map_info.rows || j < 0 || j >= map_info.columns || ft_check_component(map[i][j]))
        return ;
    else
    {
        map[i][j] = 'x';
        ft_dfs(map, i + 1, j);
        ft_dfs(map, i - 1, j);
        ft_dfs(map, i, j + 1);
        ft_dfs(map, i, j - 1);
    }
}

void    ft_flood_fille(char **map)
{
    t_player    player_pos;
    t_map       map_comp;
    char        **duped_map;

    duped_map = ft_dup_map(map);
    player_pos = ft_get_player_pos(duped_map);
    ft_dfs(duped_map, player_pos.x, player_pos.y);
    map_comp = ft_check_map_composition(duped_map, 0);
    // int i = 0;
    // while (duped_map[i])
    //     printf("%s\n", duped_map[i++]);
    free(duped_map);
    if (map_comp.collectible != 0 || map_comp.starting_pos != 0 || map_comp.map_exit != 0)
        ft_error("Error");
}