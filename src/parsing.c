#include "so_long.h"

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
	int i;
	char **map;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("Error");
	i = 0;
	while (map[i])
		map[i++] = get_next_line(fd);
	return (map);
}

void	ft_parse_input(char *file)
{
	int fd;
	char	**map;

	if (!file || !ft_check_extension(file, ".ber"))
		ft_error("Error");
	map = ft_get_map(file);
}