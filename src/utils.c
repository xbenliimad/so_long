#include "so_long.h"

void    ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

void    ft_free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

t_map   ft_get_map_size(char **map)
{
	t_map map_info;

	map_info.rows = 0;
	while(map[map_info.rows])
		map_info.rows++;
	map_info.columns = 0;
	while(map[0][map_info.columns])
		map_info.columns++;
	return (map_info);
}

t_player    ft_get_player_pos(char **map)
{
	int         i;
	int         j;
	t_player    player_pos;

	player_pos.x = 0;
	player_pos.y = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_pos.x = i;
				player_pos.y = j;
				return (player_pos);
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

char    **ft_dup_map(char **map)
{
	int     i;
	t_map   map_size;
	char    **duped_map;

	map_size = ft_get_map_size(map);
	duped_map = ft_calloc(map_size.rows + 1, sizeof(char *));
	if (!duped_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		duped_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (duped_map);
}

int	ft_count_collectibles(char **map)
{
	int i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_free_struct(t_data *data)
{
	free(data->img_collectible);
	free(data->img_exit);
	free(data->img_player);
	free(data->img_space);
	free(data->img_wall);
	free(data->mlx_ptr);
	free(data->win_ptr);
	ft_free_map(data->map);
}