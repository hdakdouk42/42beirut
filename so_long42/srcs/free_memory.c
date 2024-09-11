/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:37:22 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/09 21:44:17 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}	
		free(map->grid);
	}
}

void	free_textures(t_game *game)
{
	if (game->closed_door.img)
		mlx_destroy_image(game->mlx, game->closed_door.img);
	if (game->enemy.img)
		mlx_destroy_image(game->mlx, game->enemy.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->empty.img)
		mlx_destroy_image(game->mlx, game->empty.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
}

void	free_array(int **array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_textures(game);
	free_map(&game->map);
	if (game->enemies)
		free(game->enemies);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
