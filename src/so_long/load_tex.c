#include "solong.h"
#include "mlx.h"

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

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
	game->ground.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-ground-1.xpm", &img_width, &img_height);
	game->player.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-player-0.xpm", &img_width, &img_height);
	game->collectible.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-collectible-1.xpm", &img_width, &img_height);
	game->exit.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/64-exit.xpm", &img_width, &img_height);
	game->sprite_scale = img_width;
	(void)img_height;
	(void)img_width;
}