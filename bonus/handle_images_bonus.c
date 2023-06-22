#include "so_long_bonus.h"

void    ft_get_images(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/img_wall.xpm", &data->w, &data->h);
	data->img_space = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/img_space.xpm", &data->w, &data->h);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/img_player_right.xpm", &data->w, &data->h);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/img_collectible.xpm", &data->w, &data->h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/img_exit.xpm", &data->w, &data->h);
}


void    ft_put_images(t_data *data, char component, int i, int j)
{
    if (component == '1')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->img_wall, j * 60, i * 60);
    else if (component == '0')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->img_space, j * 60, i * 60);
    else if (component == 'P')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->img_player, j * 60, i * 60);
    else if (component == 'C')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->img_collectible, j * 60, i * 60);
    else if (component == 'E')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->img_exit, j * 60, i * 60);
    else
        ft_error("Error");
}

void ft_handle_images(char **map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            ft_put_images(data, map[i][j], i, j);
            j++;
        }
        i++;
    }
}