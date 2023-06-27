/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movements_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:53:28 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/27 16:53:29 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_handle_up(t_data *data, t_player player_pos, int collectibles)
{
	if ((data->map)[player_pos.x - 1][player_pos.y] == '1')
		return ;
	else if ((data->map)[player_pos.x - 1][player_pos.y] == 'C')
		(data->map)[player_pos.x - 1][player_pos.y] = '0';
	else if ((data->map)[player_pos.x - 1][player_pos.y] == 'V')
		ft_close("WASTED!");
	else if ((data->map)[player_pos.x - 1][player_pos.y] == 'E')
	{
		if (collectibles)
			return ;
		else
			ft_close("CONGRATS!");
	}
	ft_swap(&(data->map)[player_pos.x - 1][player_pos.y],
		&(data->map)[player_pos.x][player_pos.y]);
	(data->counter)++;
}

void	ft_handle_down(t_data *data, t_player player_pos, int collectibles)
{
	if ((data->map)[player_pos.x + 1][player_pos.y] == '1')
		return ;
	else if ((data->map)[player_pos.x + 1][player_pos.y] == 'C')
		(data->map)[player_pos.x + 1][player_pos.y] = '0';
	else if ((data->map)[player_pos.x + 1][player_pos.y] == 'V')
		ft_close("WASTED!");
	else if ((data->map)[player_pos.x + 1][player_pos.y] == 'E')
	{
		if (collectibles)
			return ;
		else
			ft_close("CONGRATS!");
	}
	ft_swap(&(data->map)[player_pos.x + 1][player_pos.y],
		&(data->map)[player_pos.x][player_pos.y]);
	(data->counter)++;
}

void	ft_handle_left(t_data *data, t_player player_pos, int collectibles)
{
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_player_left.xpm", &data->w, &data->h);
	if ((data->map)[player_pos.x][player_pos.y - 1] == '1')
		return ;
	else if ((data->map)[player_pos.x][player_pos.y - 1] == 'C')
		(data->map)[player_pos.x][player_pos.y - 1] = '0';
	else if ((data->map)[player_pos.x][player_pos.y - 1] == 'V')
		ft_close("WASTED!");
	else if ((data->map)[player_pos.x][player_pos.y - 1] == 'E')
	{
		if (collectibles)
			return ;
		else
			ft_close("CONGRATS!");
	}
	ft_swap(&(data->map)[player_pos.x][player_pos.y - 1],
		&(data->map)[player_pos.x][player_pos.y]);
	(data->counter)++;
}

void	ft_handle_right(t_data *data, t_player player_pos, int collectibles)
{
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/img_player_right.xpm", &data->w, &data->h);
	if ((data->map)[player_pos.x][player_pos.y + 1] == '1')
		return ;
	else if ((data->map)[player_pos.x][player_pos.y + 1] == 'C')
		(data->map)[player_pos.x][player_pos.y + 1] = '0';
	else if ((data->map)[player_pos.x][player_pos.y + 1] == 'V')
		ft_close("WASTED!");
	else if ((data->map)[player_pos.x][player_pos.y + 1] == 'E')
	{
		if (collectibles)
			return ;
		else
			ft_close("CONGRATS!");
	}
	ft_swap(&(data->map)[player_pos.x][player_pos.y + 1],
		&(data->map)[player_pos.x][player_pos.y]);
	(data->counter)++;
}

int	ft_handle_movements(int keycode, t_data *data)
{
	t_player	player_pos;
	int			collectibles;

	collectibles = ft_count_collectibles(data->map);
	player_pos = ft_get_player_pos(data->map);
	if ((keycode == 13 || keycode == 126))
		ft_handle_up(data, player_pos, collectibles);
	else if ((keycode == 1 || keycode == 125))
		ft_handle_down(data, player_pos, collectibles);
	else if ((keycode == 0 || keycode == 123))
		ft_handle_left(data, player_pos, collectibles);
	else if ((keycode == 2 || keycode == 124))
		ft_handle_right(data, player_pos, collectibles);
	else if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	ft_handle_images(data->map, data);
	return (0);
}
