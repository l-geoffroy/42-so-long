#include "solong.h"
#include "mlx.h"

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 123)
		move_player_left(game);
	else if (keycode == 124)
	{
		move_player_right(game);
	}
	else if (keycode == 125)
		move_player_bot(game);
	else if (keycode == 126)
		move_player_top(game);
	else if (keycode == 53)
		exit_game(game);
	return (0);
}