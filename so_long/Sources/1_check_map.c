#include <so_long.h>

/* verify if the map is rounded of walls */
void	verify(int valid, t_map *map)
{
	if (map->valid == 1)
		map->valid = valid;
}

/* Check if is a wall */
int	check_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

/* Check if the charactables in the map is valid */
/* Also store how many exit, players and collect items has the map */
/* Store backups start position of player */
int	check_c(char c, t_map *map, int col, int line)
{
	if (c == 'P')
	{
		map->check.player += 1;
		map->player.x = col;
		map->player.y = line - 1;
		map->player_bup.x = col;
		map->player_bup.y = line - 1;
	}
	if (c == 'E')
		map->check.exit += 1;
	if (c == 'C')
		map->check.collect += 1;
	if (c == 'P' || c == '1' || c == 'C' || c == 'E' || c == '0' || c == 'V')
		return (1);
	else
		return (0);
}

/* Verify if the amount of collect, exit and player is valid. */
int	valid_cpe(t_map *map)
{
	if (map->check.collect < 1)
		return (errors("the map need at least 1 collect item"));
	if (map->check.exit < 1)
		return (errors("the map need at least 1 exit"));
	if (map->check.player > 1 || map->check.player < 1)
		return (errors("the map must have just 1 player"));
	return (1);
}

int	check_map(char *argv)
{
	if (check_extension(argv) < 0)
		return (-1);
	
	
}
