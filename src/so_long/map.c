#include "solong.h"
#include "get_next_line.h"

void	parse_map(t_game *game, char *map_file)
{
	int		fd;
	char	*gnl;
	int		x;
	int		y;
	int		i;
	int		c;
	int		nl;

	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	i = 0;
	c = 0;
	nl = 0;
	while (gnl)
	{
		while (gnl[c] && gnl[c] != '\n')
			c++;
		i++;
		gnl = get_next_line(fd);
	}
	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	game->map_c = ft_strlen(gnl) - 1;
	game->map_r = i;
	game->map = (char **)malloc(sizeof(gnl[0]) * (c + i));
	x = 0;
	while (gnl)
	{
		i = 0;
		y = 0;
		game->map[x] = (char *)malloc(sizeof(gnl[0]) * (ft_strlen(gnl) + 1));
		while (gnl[i])
		{
			if (gnl[i] != '\n')
			{
				if (gnl[i] == 'C')
					game->nb_collect++;
				game->map[x][y] = gnl[i];
				printf("game->map[%d][%d] = %c;\n", x, i, game->map[x][i]);
				y++;
			}
			else
				nl = 1;
			i++;
		}
		if (nl)
			game->map[x][i] = 0;
		else
			game->map[x][i - 1] = 0;
		x++;
		gnl = get_next_line(fd);
	}
}