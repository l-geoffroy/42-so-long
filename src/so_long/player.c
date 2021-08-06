#include "solong.h"
#include "libft.h"
#include "mlx.h"

void move_player_right(t_game *game)
{
	game->move_dir = 0;
	if (check_collision(game, game->player_x, game->player_y + 1) == 1)
	{
		update_ground(game);
		game->player_y = game->player_y + 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x, game->player_y + 1) == 2)
	{
		game->map[game->player_x][game->player_y + 1] = '0';
		game->player_collect++;
		update_ground(game);
		game->player_y = game->player_y + 1;
		ft_putstr(game->map[2]);
		update_player(game);
	}
	else if (check_collision(game, game->player_x, game->player_y + 1) == 3)
	{
		if (game->nb_collect == game->player_collect)
		{
			exit_game(game);
		}
	}
}

void move_player_left(t_game *game)
{
	game->move_dir = 1;
	if (check_collision(game, game->player_x, game->player_y - 1) == 1)
	{
		update_ground(game);
		game->player_y = game->player_y - 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x, game->player_y - 1) == 2)
	{
		game->map[game->player_x][game->player_y - 1] = '0';
		game->player_collect++;
		update_ground(game);
		game->player_y = game->player_y - 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x, game->player_y - 1) == 3)
	{
		if (game->nb_collect == game->player_collect)
		{
			exit_game(game);
		}
	}
}

void move_player_top(t_game *game)
{
	game->move_dir = 2;
	if (check_collision(game, game->player_x - 1, game->player_y) == 1)
	{
		update_ground(game);
		game->player_x = game->player_x - 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x - 1, game->player_y) == 2)
	{
		game->map[game->player_x - 1][game->player_y] = '0';
		game->player_collect++;
		update_ground(game);
		game->player_x = game->player_x - 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x - 1, game->player_y) == 3)
	{
		if (game->nb_collect == game->player_collect)
		{
			exit_game(game);
		}
	}
}

void move_player_bot(t_game *game)
{
	game->move_dir = 3;
	if (check_collision(game, game->player_x + 1, game->player_y) == 1)
	{
		update_ground(game);
		game->player_x = game->player_x + 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x + 1, game->player_y) == 2)
	{
		game->map[game->player_x + 1][game->player_y] = '0';
		game->player_collect++;
		update_ground(game);
		game->player_x = game->player_x + 1;
		update_player(game);
	}
	else if (check_collision(game, game->player_x + 1, game->player_y) == 3)
	{
		if (game->nb_collect == game->player_collect)
		{
			exit_game(game);
		}
	}
}