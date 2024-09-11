/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvability.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:51:19 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/09 21:29:10 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_reachable(t_game *game, int **visited, char p)
{
	int		i;
	int		j;
	bool	reachable;

	i = -1;
	reachable = true;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] == p && !visited[i][j])
			{
				reachable = false;
				break ;
			}
		}
		if (!reachable)
			break ;
	}
	return (reachable);
}

bool	is_valid_position(int x, int y, t_game *game, char p)
{
	if (p == 'C')
	{
		return (x >= 0 && x < game->map.width && y >= 0
			&& y < game->map.height && game->map.grid[y][x] != '1'
			&& game->map.grid[y][x] != 'E' && game->map.grid[y][x] != 'I');
	}
	else if (p == 'E')
	{
		return (x >= 0 && x < game->map.width && y >= 0
			&& y < game->map.height && game->map.grid[y][x] != '1'
			&& game->map.grid[y][x] != 'I');
	}
	return (1);
}

void	flood_fill(t_game *game, t_coord coord, int **visited, char p)
{
	int		i;
	int		directions[4][2];
	t_coord	new_coord;

	directions[0][0] = 1;
	directions[0][1] = 0;
	directions[1][0] = 0;
	directions[1][1] = 1;
	directions[2][0] = -1;
	directions[2][1] = 0;
	directions[3][0] = 0;
	directions[3][1] = -1;
	if (!is_valid_position(coord.x, coord.y, game, p)
		|| visited[coord.y][coord.x])
		return ;
	visited[coord.y][coord.x] = 1;
	i = 0;
	while (i < 4)
	{
		new_coord.x = coord.x + directions[i][0];
		new_coord.y = coord.y + directions[i][1];
		flood_fill(game, new_coord, visited, p);
		i++;
	}
}

bool	is_solvable(t_game *game, char p)
{
	int		**visited;
	int		i;
	bool	all_collectibles_reachable;
	t_coord	start_coord;

	all_collectibles_reachable = true;
	visited = malloc(sizeof(int *) * game->map.height);
	i = 0;
	while (i < game->map.height)
	{
		visited[i] = malloc(sizeof(int) * game->map.width);
		ft_memset(visited[i], 0, sizeof(int) * game->map.width);
		i++;
	}
	start_coord.x = game->player_x;
	start_coord.y = game->player_y;
	flood_fill(game, start_coord, visited, p);
	all_collectibles_reachable = check_reachable(game, visited, p);
	free_array(visited, game->map.height);
	return (all_collectibles_reachable);
}
