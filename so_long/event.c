/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:06:29 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 17:06:29 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_movement_input(int keycode, int *new_x,
	int *new_y, t_game *game)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		(*new_y)--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		(*new_y)++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		(*new_x)--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		(*new_x)++;
	else
		return (0);
	return (1);
}

static int	process_next_tile(t_game *game, int new_x, int new_y)
{
	char	next;

	next = game->map[new_y][new_x];
	if (next == '1')
		return (0);
	if (next == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (next == 'E')
	{
		if (game->collected == game->collectibles_count)
		{
			ft_printf("!!You Win!!");
			exit_game(game);
		}
	}
	return (1);
}

int	handle_key(int keycode, void *param)
{
	int		new_x;
	int		new_y;
	t_game	*game;

	game = (t_game *)param;
	if (!handle_movement_input(keycode, &new_x, &new_y, game))
		return (0);
	if (!process_next_tile(game, new_x, new_y))
		return (0);
	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
	draw_game(game);
	return (0);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_game(game);
	return (0);
}
