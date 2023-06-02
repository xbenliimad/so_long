/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:46:51 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/02 20:42:48 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <string.h>
#include <errno.h>
# include <mlx.h>

// Parsing
void	ft_parse_input(char *file);


// utils
void	ft_error(char *message);

#endif