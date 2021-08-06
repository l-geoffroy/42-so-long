#include "solong.h"
#include "mlx.h"
#include "libft.h"
#include <unistd.h>

int	check_collision(t_game *game, int future_x, int future_y)
{
	if (game->map[future_x][future_y] == 'C')
		return (2);
	else if (game->map[future_x][future_y] == '1')
		return (0);
	else if (game->map[future_x][future_y] == '0')
		return (1);
	else if (game->map[future_x][future_y] == 'E')
		return (3);
	return (1);
}

void	update_ground(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground.mlx_img, game->player_y * game->sprite_scale, game->player_x * game->sprite_scale);
}

void	update_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.mlx_img, game->player_y * game->sprite_scale, game->player_x * game->sprite_scale);
	game->move_count++;
	printf("Move: %d\n", game->move_count);
}

void	put_wall(t_game *game, int curr_x, int curr_y)
{
	if (curr_x < game->map_r - 1)
	{
		if (curr_y < game->map_c - 1 && curr_y != 0)
		{
			if (game->map[curr_x + 1][curr_y] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_8.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
				return ;
			}
		}
	}
	if (curr_y == game->map_c - 1 && curr_x != 0 && curr_x != game->map_r -1)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_4.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
			return ;
		}
	if (curr_x == 0 && curr_y == game->map_c - 1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_4.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
		return ;
	}
	if (curr_x == game->map_r - 1)
	{
		if (curr_y == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_9.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
			return ;
		}
		else if (curr_y == game->map_c - 1)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_10.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
				return ;
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_5.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
		return ;
	}
	else if (curr_y + 1 < game->map_c)
	{
		if (game->map[curr_x + 1][curr_y] == '1')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_3.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
			return ;
		}
		if (game->map[curr_x][curr_y + 1] == '1' && game->map[curr_x][curr_y - 1] == '1' && (game->last_t_y + 7 < curr_y || curr_x != game->last_t_x))
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_1.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
			game->last_t_x = curr_x;
			game->last_t_y = curr_y;
			return ;
		}
		else
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_2.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
			return ;
		}
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_2.mlx_img, curr_y * game->sprite_scale, curr_x * game->sprite_scale);
		return ;
	}
}

void	draw_map(t_game *game)
{
	int	x;	
	int	y;
	int	nb_img;

	x = 0;
	nb_img = 0;
	while (x <= game->map_r - 1)
	{
		y = 0;
		while (y <= game->map_c - 1)
		{
			if (game->map[x][y] == '1')
				put_wall(game, x, y);
			else if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground.mlx_img, y * game->sprite_scale, x * game->sprite_scale);
			else if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible.mlx_img, y * game->sprite_scale, x * game->sprite_scale);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit.mlx_img, y * game->sprite_scale, x * game->sprite_scale);
			else if (game->map[x][y] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground.mlx_img, y * game->sprite_scale, x * game->sprite_scale);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.mlx_img, y * game->sprite_scale, x * game->sprite_scale);
				game->player_x = x;
				game ->player_y = y;
			}
			y++;
		}
		x++;
	}
}