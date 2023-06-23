/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:46:51 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/23 03:01:28 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <string.h>
# include <errno.h>
// # include <mlx.h>
# include "../mlx_linux/mlx.h"

typedef struct s_player
{
	int x;
	int y;
}   t_player;

typedef struct s_map
{
	int rows;
	int columns;
	int starting_pos;
	int collectible;
	int map_exit;
}   t_map;

typedef	struct s_data
{
	int			w;
	int			h;
	int			counter;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_collectible;
	void		*img_player;
	void		*img_wall;
	void		*img_exit;
	void		*img_space;
}	t_data;

// Parsing
char	**ft_parse_input(char *file);

// Checker
void    ft_handle_checker(char **map);
t_map   ft_get_map_size(char **map);

// Hanlding the game
void    ft_handle_game(char **map);
int    ft_handle_movements(int keycode, t_data *data);

// utils
void		ft_error(char *message);
void    	ft_free_map(char **map);
char        **ft_dup_map(char **map);
t_player    ft_get_player_pos(char **map);
t_map    ft_check_map_composition(char **map, int state);
int	ft_count_collectibles(char **map);
void	ft_free_struct(t_data *data);

// Images
void ft_handle_images(char **map, t_data *data);
void    ft_get_images(t_data *data);

// ft_flood_fill
void    ft_flood_fille(char **map);

// Cutom
char	*ft_custom_strjoin(char **s1, char *s2);

#endif