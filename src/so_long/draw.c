#include "solong.h"
#include "mlx.h"
#include "libft.h"
#include <unistd.h>

int	check_collision(t_game *game, int future_x, int future_y)
{
	printf("f_x=%d f_y=%d  :  %c\n", future_x, future_y, game->map[future_x][future_y]);
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
	printf("player pos : y=%d x=%d\n", game->player_y, game->player_x);
	printf("player collected : %d / %d\n", game->player_collect, game->nb_collect);
	game->p_anim = 1;
	game->p_state = 1;
	game->move_frames = 0;
	game->move_count++;
	printf("Move: %d\n", game->move_count);
}

void	put_wall(t_game *game, int curr_x, int curr_y)
{
	ft_putnbr(game->map_c);
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
		printf("+ 1= %c  \t  -1 =%c\n", game->map[curr_x][curr_y + 1], game->map[curr_x][curr_y - 1]);
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
	int	img_width;
	int	img_height;
	int	x;	
	int	y;
	int	nb_img;

	x = 0;
	nb_img = 0;
	game->p_state = 0;
	game->move_frames = 0;
	game->wall_0.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-0.xpm", &img_width, &img_height);
	game->wall_1.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-1.xpm", &img_width, &img_height);
	game->wall_2.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-2.xpm", &img_width, &img_height);
	game->wall_3.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-3.xpm", &img_width, &img_height);
	game->wall_4.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-4.xpm", &img_width, &img_height);
	game->wall_5.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-5.xpm", &img_width, &img_height);
	game->wall_6.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-6.xpm", &img_width, &img_height);
	game->wall_7.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-7.xpm", &img_width, &img_height);
	game->wall_8.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-8.xpm", &img_width, &img_height);
	game->wall_9.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-9.xpm", &img_width, &img_height);
	game->wall_10.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-10.xpm", &img_width, &img_height);
	game->wall_11.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-wall-11.xpm", &img_width, &img_height);
	game->ground.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-ground-1.xpm", &img_width, &img_height);
	game->player.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-player-0.xpm", &img_width, &img_height);
	game->player_1.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-player-1.xpm", &img_width, &img_height);
	game->player_2.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-player-2.xpm", &img_width, &img_height);
	game->player_3.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-player-3.xpm", &img_width, &img_height);
	game->collectible.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-collectible-1.xpm", &img_width, &img_height);
	game->exit.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-exit.xpm", &img_width, &img_height);
	game->sprite_scale = img_width;
	printf("map_c %d   -  map_r %d\n", game->map_c, game->map_r);
	while (x <= game->map_r - 1)
	{
		y = 0;
		while (y <= game->map_c - 1)
		{
			if (game->map[x][y] == '1')
				put_wall(game, x, y);
			else if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground.mlx_img, y * img_width, x * img_height);
			else if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible.mlx_img, y * img_width, x * img_height);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit.mlx_img, y * img_width, x * img_height);
			else if (game->map[x][y] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ground.mlx_img, y * img_width, x * img_height);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.mlx_img, y * img_width, x * img_height);
				game->player_x = x;
				game ->player_y = y;
			}
			y++;
		}
		x++;
	}
	(void)img_height;
	(void)img_width;
}