/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:34:09 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/10 21:17:10 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	read_map_file(int fd, t_game *game, char **new_grid)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		if (game->map.height == 0)
			game->map.width = ft_strlen(line) - 1;
		game->total_collectibles += count_collectibles(line, game->map.width);
		game->total_exits += count_exits(line, game->map.width);
		game->total_players += count_players(line, game->map.width);
		new_grid = ft_calloc(game->map.height + 1, sizeof(char *));
		if (!new_grid)
			handle_close(game);
		i = -1;
		while (++i < game->map.height)
			new_grid[i] = game->map.grid[i];
		if (game->map.grid)
			free(game->map.grid);
		new_grid[game->map.height] = line;
		game->map.grid = new_grid;
		game->map.height++;
		line = get_next_line(fd);
	}
	return (1);
}

void	render_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map_help(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[y][x] == '1')
			render_tile(game, game->wall.img, x, y);
		else if (game->map.grid[y][x] == '0')
			render_tile(game, game->empty.img, x, y);
		else if (game->map.grid[y][x] == 'C')
			render_tile(game, game->collectible.img, x, y);
		else if (game->map.grid[y][x] == 'E')
		{
			if (game->collected_count < game->total_collectibles)
				render_tile(game, game->closed_door.img, x, y);
			else
				render_tile(game, game->exit.img, x, y);
		}
		else if (game->map.grid[y][x] == 'P')
			render_tile(game, game->empty.img, x, y);
		else if (game->map.grid[y][x] == 'I')
			render_tile(game, game->enemy.img, x, y);
		x++;
	}
	y++;
}

void	render_map(t_game *game)
{
	int	y;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->map.height)
	{
		render_map_help(game, y);
		y++;
	}
	render_tile(game, game->player.img, game->player_x, game->player_y);
}

void	intialize_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->enemies = NULL;
	game->enemy_count = 0;
	game->collected_count = 0;
	game->total_collectibles = 0;
	game->total_exits = 0;
	game->total_players = 0;
	game->counter = 0;
}
