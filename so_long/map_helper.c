/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:51:07 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 18:34:18 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Validate map essential elements
void	validate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				game->player_count++;
			else if (game->map[y][x] == 'E')
				game->exit_count++;
			else if (game->map[y][x] == 'C')
				game->collectibles_count++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				exit_with_error_free("Map contains invalid character", game);
			if ((y == 0 || y == game->height - 1 || x == 0
					|| x == game->width - 1) && game->map[y][x] != '1')
				exit_with_error_free("Map must be closed with walls", game);
			x++;
		}
		y++;
	}
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int y, int x, t_flood *flood)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		flood->found_c++;
	if (map[y][x] == 'E')
		flood->found_e++;
	map[y][x] = 'X';
	if (y > 0)
		flood_fill(map, y - 1, x, flood);
	if (y < flood->height - 1)
		flood_fill(map, y + 1, x, flood);
	if (x > 0)
		flood_fill(map, y, x - 1, flood);
	if (x < flood->width - 1)
		flood_fill(map, y, x + 1, flood);
}

int	copy_map(char **dst, char **src, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		dst[y] = ft_strdup(src[y]);
		if (!dst[y])
			return (1);
		y++;
	}
	dst[y] = NULL;
	return (0);
}
