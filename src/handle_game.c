/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:45:36 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/27 17:15:32 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

void	ft_error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	ft_handle_game(char **map)
{
	t_data	data;
	t_map	map_info;

	map_info = ft_get_map_size(map);
	data.mlx_ptr = mlx_init();
	if (!(data.mlx_ptr))
		ft_error("Couldn't initialize mlx_ptr.");
	data.win_ptr = mlx_new_window(data.mlx_ptr, map_info.columns * 60,
			map_info.rows * 60, "so_long");
	if (!(data.win_ptr))
		ft_error("Couldn't initialize win_ptr.");
	ft_get_images(&data);
	ft_handle_images(map, &data);
	data.map = map;
	mlx_hook(data.win_ptr, 2, 1L << 0, &ft_handle_movements, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, &ft_handle_close, &data);
	mlx_loop(data.mlx_ptr);
}
