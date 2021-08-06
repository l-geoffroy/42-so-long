#include "get_next_line.h"
#include "solong.h"

int	is_player(char	*map_file)
{
	int		fd;
	char	*gnl;
	int		i;
	int		player;

	player = 0;
	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		i = 0;
		while (gnl[i])
		{
			if (gnl[i] == 'P')
				player++;
			i++;
		}
		gnl = get_next_line(fd);
	}
	if (player != 1)
		return (1);
	return (0);
}

int	is_inv_char(char *map_file)
{
	int		fd;
	char	*gnl;
	int		i;
	int		player;

	player = 0;
	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		i = 0;
		while (gnl[i])
		{
			if ((gnl[i] != '1') && (gnl[i] != '0') && (gnl[i] != 'P') && (gnl[i] != 'E') && (gnl[i] != 'C') && (gnl[i] != '\n'))
				return (1);
			i++;
		}
		gnl = get_next_line(fd);
	}
	return (0);
}