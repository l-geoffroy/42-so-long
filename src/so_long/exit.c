#include "solong.h"
#include "libft.h"
#include "mlx.h"

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall_0.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_1.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_2.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_3.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_4.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_5.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_6.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_7.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_8.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_9.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_10.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->ground.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->collectible.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->exit.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->player.mlx_img);
}

int		exit_game(t_game *game)
{
	free_img(game);
	free(game->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}