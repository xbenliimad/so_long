#include "so_long_bonus.h"

static int ft_check_extension(char *file, char *suffix)
{
	int file_len;
	int suffix_len;

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
	int fd;
	char **map;
	char *tmp;
	char  *str;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("Error");
	tmp = get_next_line(fd);
	str = NULL;
	while (tmp)
	{
		str = ft_custom_strjoin(&str, tmp);
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
		ft_error("Error");
	map = ft_get_map(file);
	if (!map)
		ft_error("Error");
	ft_handle_checker(map);
	return (map);
}