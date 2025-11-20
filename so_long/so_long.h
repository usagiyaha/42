/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:39:50 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 18:39:50 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*header*/
# include "./lib/libft/libft.h"
# include "./lib/mlx/mlx.h"

/*library*/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*define*/
# define TILE_SIZE 32
# define MAX_HEIGHT 1000

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

/*texture path*/
# define PLAYER_PATH "textures/player.xpm"
# define WALL_PATH "textures/wall.xpm"
# define EXIT_OPEN_PATH "textures/exit_open.xpm"
# define EXIT_CLOSE_PATH "textures/exit_close.xpm"
# define COIN_PATH "textures/coin.xpm"
# define FLOOR_PATH "textures/floor.xpm"

/*struct*/
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		height;
	int		width;
	int		collectibles_count;
	int		exit_count;
	int		player_count;
	int		player_y;
	int		player_x;
	int		collected;
	int		steps;
	void	*player_img;
	void	*floor_img;
	void	*wall_img;
	void	*coin_img;
	void	*exit_open_img;
	void	*exit_close_img;
}	t_game;

typedef struct s_flood
{
	int	found_c;
	int	found_e;
	int	height;
	int	width;
}	t_flood;

// map.c
void	check_map_extension(char **argv);
void	load_map(char **argv, t_game *game);
void	validate_map_shape(t_game *game);
void	check_map_elements(t_game *game);
// void	flood_fill(char **map, int y, int x, int *found_c, int *found_e);
void	check_valid_path(t_game *game);

//map_helper.c
void	validate_map(t_game *game);
void	flood_fill(char **map, int y, int x, t_flood *flood);
void	find_player_position(t_game *game);
int		copy_map(char **dst, char **src, int height);

//init_game.c
void	init_game(t_game *game);
// static void	draw_tile(t_game *game, int x, int y);
void	draw_game(t_game *game);

//helper.c
void	free_map(char **map, int height);
void	free_images(t_game *game);
void	exit_with_error(const char *msg);
void	exit_with_error_free(const char *msg, t_game *game);
void	exit_game(t_game *game);

//event.c
// static int	handle_movement_input(int keycode, 
// int *new_x, int *new_y, t_game *game);
// static int	process_next_tile(t_game *game, 
// int new_x, int new_y);
int		handle_key(int keycode, void *param);
int		handle_close(void *param);
#endif
