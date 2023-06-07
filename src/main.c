/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:48:12 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/07 15:18:00 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char *av[])
{
    char    **map;
    void    *mlx;
    void    *mlx_win;
    t_map   map_info;
    
    map = NULL;
    if (ac != 2)
        return (1);
    map = ft_parse_input(av[1]);
    if(map)
        printf("Map is valid.\n");
    map_info = ft_get_map_size(map);
    mlx = mlx_init();
    mlx_win =  mlx_new_window(mlx, map_info.columns * 60, map_info.rows * 60, "so_long");
    mlx_loop(mlx);
    ft_free_map(map);
    return (0);
}