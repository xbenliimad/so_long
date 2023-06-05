/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:48:12 by ibenli            #+#    #+#             */
/*   Updated: 2023/06/05 21:00:15 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char *av[])
{
    char    **map;
    
    map = NULL;
    if (ac != 2)
        return (1);
    map = ft_parse_input(av[1]);
    if(map)
        printf("There is a map\n");
    return (0);
}