#include "solong.h"
#include "libft.h"
#include "mlx.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall_0.mlx_img);
	//mlx_destroy_image(game->mlx_ptr, game->wall_11.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_10.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->ground.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->collectible.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->exit.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->player.mlx_img);
}

int	exit_game(t_game *game)
{
	printf("Clearing mem.");
	free_img(game);
	free(game->map);
	//free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	//free(game->win_ptr);
	free(game->mlx_ptr);
	//free(game);
	exit(0);
	/*mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// vm linux : mlx_destroy_display(game->mlx_ptr);
	free_img(game->mlx_ptr);
	free_map(game);
	free(game->mlx_ptr);
	exit(0);
	//free(game->mlx_ptr);
	//free(game->win_ptr);
	//free(game->img);*/
	return (0);
}