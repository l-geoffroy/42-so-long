#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_game {
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_c;
	int		map_r;
	int		player_x;
	int		player_y;
	int		sprite_scale;
	int		move_count;
	int		nb_collect;
	int		player_collect;
	int		last_t_x;
	int		last_t_y;
	int		frames;
	int		p_anim;
	int		p_state;
	int		move_dir;
	int		move_frames;
	t_img	wall_0;
	t_img	wall_1;
	t_img	wall_2;
	t_img	wall_3;
	t_img	wall_4;
	t_img	wall_5;
	t_img	wall_6;
	t_img	wall_7;
	t_img	wall_8;
	t_img	wall_9;
	t_img	wall_10;
	t_img	wall_11;
	t_img	ground;
	t_img	player;
	t_img	player_1;
	t_img	player_2;
	t_img	player_3;
	t_img	collectible;
	t_img	exit;
}				t_game;

int		check_map(char *map_file);
int		is_square(char *map_file);
int		is_player(char	*map_file);
int		is_inv_char(char *map_file);
void	parse_map(t_game *game, char *map_file);
void	draw_map(t_game *game);
void	update_player(t_game *game);
void	update_ground(t_game *game);
int		check_collision(t_game *game, int future_x, int future_y);

int		exit_game(t_game *game);

int		keyhook(int keycode, t_game *game);

void	animate_player(t_game *game);
void	move_player_right(t_game *game);
void	move_player_left(t_game *game);
void 	move_player_top(t_game *game);
void	move_player_bot(t_game *game);

int		player_anim(t_game *game);

#endif