#include "so_long_bonus.h"
// #include <X11/keysym.h>

int	ft_handle_close(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return (0);
}

void    ft_handle_game(char **map)
{
    t_data      data;
    t_map       map_info;

    data.counter = 0;
    map_info = ft_get_map_size(map);
    data.mlx_ptr = mlx_init();
    if (!(data.mlx_ptr))
        ft_error("Error");
    data.win_ptr = mlx_new_window(data.mlx_ptr, map_info.columns * 60, map_info.rows * 60, "so_long");
    if (!(data.win_ptr))
        ft_error("Error");
    ft_get_images(&data);
    ft_handle_images(map, &data);
    data.map = map;
    mlx_hook(data.win_ptr, 2, 1L << 0, &ft_handle_movements, &data);
    mlx_hook(data.win_ptr, 17, 1L << 0, &ft_handle_close, &data);
    mlx_loop_hook(data.mlx_ptr, &ft_handle_animations, &data);
    mlx_loop(data.mlx_ptr);
}
