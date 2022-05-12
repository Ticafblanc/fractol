
#include <so_long.h>

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->line)
		free(map_str[i++]);
	free(map_str);
	i = 0;
	while (i <= map->line)
		free(map->backup_map[i++]);
	free(map->backup_map);
}

int	recovery(t_map *map)
{
	int		i;
	int		line;

	i = 0;
	while (i <= map->line)
		free(map->map[i++]);
	free(map->map);
	line = map->line;
	map->map = malloc(sizeof(char *) * line + 1);
	if (!map->map)
		return (0);
	i = 0;
	while (i < line)
	{
		map->map[i] = ft_strdup(map->backup_map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->check.collect = map->item_bup;
	return (1);
}

int	put_error_arg(int error)
{
	if (error == 1)
		ft_putstr_fd("the map need at least 1 collect item", STDERR_FILENO);
	else if (error == 2)
		rft_putstr_fd("the map need at least 1 exit", STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("the map must have just 1 player", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("the map must not have closed walls", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("the card should only have a rectangular shape", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("Wrong extension of the map", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("Wrong path of the map", STDERR_FILENO);
	else
		ft_putstr_fd("just one map !!", STDERR_FILENO);
	return (EINVAL);
}

