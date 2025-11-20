/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:12:12 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 17:12:12 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->coin_img)
		mlx_destroy_image(game->mlx_ptr, game->coin_img);
	if (game->exit_open_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_open_img);
	if (game->exit_close_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_close_img);
}

void	exit_with_error(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	exit_with_error_free(const char *msg, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (game->map)
		free_map(game->map, game->height);
	free_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(1);
}

void	exit_game(t_game *game)
{
	free_map(game->map, game->height);
	free_images(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_printf("Goodbye! Total steps: %d\n", game->steps);
	exit(0);
}
