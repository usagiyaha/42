/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:22:06 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 17:22:06 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	init_game(t_game *game)
{
	int	w;
	int	h;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_with_error_free("Failed to initiate MiniLibx.", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "Oink for Burgers");
	if (!game->win_ptr)
	{
		exit_with_error_free("Failed to create window.", game);
	}
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_PATH,
			&w, &h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_PATH, &w, &h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, WALL_PATH, &w, &h);
	game->coin_img = mlx_xpm_file_to_image(game->mlx_ptr, COIN_PATH, &w, &h);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_OPEN_PATH,
			&w, &h);
	game->exit_close_img = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_CLOSE_PATH,
			&w, &h);
	if (!game->player_img || !game->floor_img || !game->wall_img
		|| !game->coin_img || !game->exit_open_img || !game->exit_close_img)
		exit_with_error_free("Failed to load one or more textures.", game);
}

static void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->coin_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
	{
		if (game->collected < game->collectibles_count)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit_close_img, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit_open_img, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	draw_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}
