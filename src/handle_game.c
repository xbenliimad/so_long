#include "so_long.h"
// #include <X11/keysym.h>

int	handle_close(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return (0);
}

int	handle_input(int keycode, void *data)
{
    (void) data;
    static int  moves_count;

	if (keycode == 0)
        printf("Left\n");
    else if (keycode == 1)
        printf("Down\n");
    else if (keycode == 2)
        printf("Right\n");
    else if (keycode == 13)
        printf("Top\n");
    else if (keycode == 53)
        exit(0);
    moves_count++;
    printf("Number of moves : %d\n", moves_count);
	return (0);
}

void    ft_handle_game(char **map)
{
    t_data  data;
    t_map   map_info;

    map_info = ft_get_map_size(map);
    data.mlx_ptr = mlx_init();
    if (!(data.mlx_ptr))
        ft_error("Error");
    data.win_ptr = mlx_new_window(data.mlx_ptr, map_info.columns * 50, map_info.rows * 50, "so_long");
    if (!(data.win_ptr))
    {
        free(data.win_ptr);
        free(data.mlx_ptr);
        ft_error("Error");
    }
    mlx_hook(data.win_ptr, 17, 0, &handle_close, &data);
    mlx_key_hook(data.win_ptr, &handle_input, &data);
    mlx_loop(data.mlx_ptr); 
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    free(data.mlx_ptr);
}
