/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:54:05 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/27 17:14:04 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_handle_score(int counter, t_data *data)
{
	char	*moves;

	moves = ft_itoa(counter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 25, 0x00FFFFFF, moves);
	free(moves);
}

void	ft_get_images(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_wall.xpm", &data->w, &data->h);
	data->img_space = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_space.xpm", &data->w, &data->h);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_player_right.xpm", &data->w, &data->h);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_collectible.xpm", &data->w, &data->h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_exit.xpm", &data->w, &data->h);
	data->img_enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_enemy_active.xpm", &data->w, &data->h);
	if (!data->img_wall || !data->img_space || !data->img_player
		|| !data->img_collectible || !data->img_exit)
		ft_error("Error");
}

int	ft_handle_animations(t_data *data)
{
	static int	counter;

	counter++;
	if (counter == 50)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_enemy);
		data->img_enemy = mlx_xpm_file_to_image(data->mlx_ptr,
				"./textures/img_enemy_inactive.xpm", &data->w, &data->h);
	}
	else if (counter == 100)
	{
		counter = 0;
		mlx_destroy_image(data->mlx_ptr, data->img_enemy);
		data->img_enemy = mlx_xpm_file_to_image(data->mlx_ptr,
				"./textures/img_enemy_active.xpm", &data->w, &data->h);
	}
	ft_handle_images(data->map, data);
	return (0);
}

void	ft_put_images(t_data *data, char component, int i, int j)
{
	if (component == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_wall, j
			* 60, i * 60);
	else if (component == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_space, j
			* 60, i * 60);
	else if (component == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player,
			j * 60, i * 60);
	else if (component == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_collectible, j * 60, i * 60);
	else if (component == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit, j
			* 60, i * 60);
	else if (component == 'V')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_enemy, j
			* 60, i * 60);
	else
		ft_error("Error in mlx_put_img.");
}

void	ft_handle_images(char **map, t_data *data)
{
	int	i;
	int	j;

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
	ft_handle_score(data->counter, data);
}
