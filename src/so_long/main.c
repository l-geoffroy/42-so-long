#include "mlx.h"
#include "solong.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_game game;

	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL || argc != 2)
		return (0);
	if (check_map(argv[1]))
	{
		free(game.mlx_ptr);
		return (0);
	}
	game.player_collect = 0;
	game.nb_collect = 0;
	game.frames = 0;
	game.move_dir = 4;
	parse_map(&game, argv[1]);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_c * 64, game.map_r * 64, "so_long");
	draw_map(&game);
	mlx_key_hook(game.win_ptr, keyhook, &game);
	mlx_loop_hook(game.mlx_ptr, player_anim, &game);
	mlx_hook(game.win_ptr, 33, 1L << 5, exit_game, &game);
	mlx_loop(game.mlx_ptr);
	exit_game(&game);
	(void)argc;
	(void)argv;
	return (0);
}