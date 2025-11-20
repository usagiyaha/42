/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:34:35 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 18:34:35 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map.ber>\n");
		return (1);
	}
	check_map_extension(argv);
	load_map(argv, &game);
	validate_map_shape(&game);
	check_map_elements(&game);
	check_valid_path(&game);
	init_game(&game);
	draw_game(&game);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, handle_close, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
