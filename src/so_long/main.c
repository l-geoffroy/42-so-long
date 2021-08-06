#include "mlx.h"
#include "solong.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

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
	parse_map(&game, argv[1]);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_c * 64,
			game.map_r * 64, "so_long");
	load_textures(&game);
	draw_map(&game);
	mlx_key_hook(game.win_ptr, keyhook, &game);
	mlx_hook(game.win_ptr, 33, 1L << 5, exit_game, &game);
	mlx_loop(game.mlx_ptr);
	exit_game(&game);
	return (0);
}
