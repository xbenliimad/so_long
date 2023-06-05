/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:46:51 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/05 22:08:12 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <string.h>
#include <errno.h>
// # include <mlx.h>

typedef struct s_map
{
    int rows;
    int columns;
    int starting_pos;
    int collectible;
    int map_exit;
}   t_map;

// Parsing
char	**ft_parse_input(char *file);

// Checker
void    ft_handle_checker(char **map);
t_map   ft_get_map_size(char **map);

// utils
void	ft_error(char *message);
void    ft_free_map(char **map);

// Cutom
char	*ft_custom_strjoin(char **s1, char *s2);



#endif