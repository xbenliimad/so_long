/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:48:12 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/27 17:21:44 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	char	**map;

	map = NULL;
	if (ac != 2)
		return (1);
	map = ft_parse_input(av[1]);
	ft_handle_game(map);
	ft_free_map(map);
	return (0);
}
