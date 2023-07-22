/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:49:09 by ibenli            #+#    #+#             */
/*   Updated: 2023/07/22 20:22:12 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_free(char *message, char **tmp, char **str)
{
	if (*tmp)
		free(*tmp);
	if (*str)
		free(*str);
	ft_printf("Error\n%s\n", message);
	exit(1);
}

static int	ft_check_extension(char *file, char *suffix)
{
	int	file_len;
	int	suffix_len;

	file_len = ft_strlen(file);
	suffix_len = ft_strlen(suffix);
	if (file_len <= suffix_len)
		return (0);
	if (!ft_strncmp((file + (file_len - suffix_len)), suffix, 5))
		return (1);
	return (0);
}

static char	**ft_get_map(char *file)
{
	int		fd;
	char	**map;
	char	*tmp;
	char	*str;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("Couldn't open the fd.");
	tmp = get_next_line(fd);
	str = NULL;
	while (tmp)
	{
		str = ft_custom_strjoin(&str, tmp);
		if (tmp && tmp[0] == '\n')
			ft_error_free("Invalid map.", &tmp, &str);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(str, '\n');
	free(tmp);
	free(str);
	return (map);
}

char	**ft_parse_input(char *file)
{
	char	**map;

	if (!file || !ft_check_extension(file, ".ber"))
		ft_error("File extension is not valid.");
	map = ft_get_map(file);
	if (!map)
		ft_error("Couldn't get the map.");
	ft_handle_checker(map);
	return (map);
}
