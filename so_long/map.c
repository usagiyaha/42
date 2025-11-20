/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:25:39 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 17:25:39 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extension(char **argv)
{
	int	map_parameter_len;

	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(argv[1], ".ber", map_parameter_len))
		exit_with_error("Map file should have extension .ber.");
}

void	load_map(char **argv, t_game *game)
{
	int		map_fd;
	char	*line_tmp;
	int		line_len;

	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		exit_with_error("Failed to open the map.");
	game->map = malloc(sizeof(char *) * (MAX_HEIGHT + 1));
	if (!game->map)
		exit_with_error("Failed to allocate map.");
	while (1)
	{
		if (game->height >= MAX_HEIGHT)
			exit_with_error_free("Map is too tall: exceeds MAX_HEIGHT", game);
		line_tmp = get_next_line(map_fd);
		if (line_tmp == NULL)
			break ;
		line_len = (int)ft_strlen(line_tmp);
		if (line_tmp[line_len - 1] == '\n')
			line_tmp[line_len - 1] = '\0';
		game->map[game->height] = line_tmp;
		game->height++;
	}
	game->map[game->height] = NULL;
	close(map_fd);
}

void	validate_map_shape(t_game *game)
{
	int	y;

	y = 0;
	game->width = (int)ft_strlen(game->map[0]);
	while (y < game->height)
	{
		if ((int)ft_strlen(game->map[y]) != game->width)
			exit_with_error_free("Map is not rectangular.", game);
		y++;
	}
}

void	check_map_elements(t_game *game)
{
	validate_map(game);
	if (game->player_count != 1)
		exit_with_error_free("Map must contain exactly one player (P)", game);
	if (game->exit_count != 1)
		exit_with_error_free("Map must contain at least one exit (E)", game);
	if (game->collectibles_count < 1)
		exit_with_error_free("Map must contain at least one coin (C)", game);
}

// 
void	check_valid_path(t_game *game)
{
	char	**visited;
	t_flood	flood;

	flood.found_c = 0;
	flood.found_e = 0;
	flood.height = game->height;
	flood.width = game->width;
	find_player_position(game);
	visited = malloc(sizeof(char *) * (game->height + 1));
	if (!visited)
		exit_with_error_free("Failed to allocate visited map.", game);
	if (copy_map(visited, game->map, game->height) == 1)
	{
		free(visited);
		exit_with_error_free("Failed to copy map.", game);
	}
	else
		flood_fill(visited, game->player_y, game->player_x, &flood);
	if (flood.found_c < game->collectibles_count || flood.found_e == 0)
	{
		free_map(visited, game->height);
		exit_with_error_free("Map has no valid path.", game);
	}
	free_map(visited, game->height);
}
