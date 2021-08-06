#include "solong.h"
#include "get_next_line.h"

void	ft_putstr(char *s)
{
	if (s)
		write (1, s, ft_strlen(s));
}

int	is_square(char *map_file)
{
	int		fd;
	char	*gnl;
	int		last_l_size;

	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		ft_putstr(gnl);
		if (gnl[ft_strlen(gnl) - 1] == '\n')
			last_l_size = ft_strlen(gnl) - 1;
		else
			last_l_size = ft_strlen(gnl);
		gnl = get_next_line(fd);
		if (gnl && gnl[ft_strlen(gnl) - 1] == '\n')
		{
			if (last_l_size != ft_strlen(gnl) - 1)
				return (1);
		}
		else if (gnl)
		{
			if (last_l_size != ft_strlen(gnl))
				return (1);
		}
	}
	return (0);
}

int		is_zero(char *map_file)
{
	int		fd;
	char	*gnl;
	int		i;
	int		zero;

	zero = 0;
	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		i = 0;
		if (gnl[ft_strlen(gnl) - 1] == '\n')
		{
			while (gnl[i])
			{
				if (gnl[i] == '0')
					zero++; 
				i++;
			}
		}
		gnl = get_next_line(fd);
	}
	if (!zero)
		return (1);
	return (0);
}

int		is_close(char *map_file)
{
	int		fd;
	char	*gnl;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl[i])
	{
		if (gnl[i] != '1' && gnl[i] != '\n')
			return (1);
		i++;
	}
	while (gnl)
	{
		if (gnl[0] != '1' || gnl[ft_strlen(gnl) - 2] != '1')
		{
			return (1);
		}
		if (gnl[ft_strlen(gnl) - 1] != '\n')
		{
			i = 0;
			while (gnl[i])
			{
				if (gnl[i] != '1')
					return (1);
				i++;
			}
		}
		gnl = get_next_line(fd);
	}
	return (0);
}

int	check_map(char *map_file)
{
	/*if (is_square(map_file))
	{
		printf("\nMap is not rectangular.\n");
		return (1);
	}*/
	if (is_close(map_file))
	{
		printf("\nMap is not closed.\n");
		return (1);
	}
	if (is_zero(map_file))
	{
		printf("\nNot enough space in map.\n");
		return (1);
	}
	if (is_inv_char(map_file))
	{
		ft_putstr("\nInvalid char in map.\n");
		return (1);
	}
	if (is_player(map_file))
	{
		ft_putstr("\nPlayer position not set in map.\n");
		return (1);
	}
	return (0);
}