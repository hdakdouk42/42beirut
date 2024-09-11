/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:48:17 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/08 16:46:30 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
		handle_close(game);
	else if (keycode == 65361 || keycode == 97)
		new_x -= 1;
	else if (keycode == 65362 || keycode == 119)
		new_y -= 1;
	else if (keycode == 65363 || keycode == 100)
		new_x += 1;
	else if (keycode == 65364 || keycode == 115)
		new_y += 1;
	if (new_x >= 0 && new_x < game->map.width
		&& new_y >= 0 && new_y < game->map.height)
		prepare_render(game, new_x, new_y);
	return (0);
}

int	collision_check(t_game *game, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].x == new_x && game->enemies[i].y == new_y)
		{
			ft_printf("Game Over! You encountered an enemy!\n");
			handle_close(game);
		}
		i++;
	}
	if (game->map.grid[new_y][new_x] != '1')
	{
		game->player_x = new_x;
		game->player_y = new_y;
		game->counter++;
		ft_printf("moved to: (%d, %d) - movement count: %d\n",
			game->player_x, game->player_y, game->counter);
		render_map(game);
	}
	return (1);
}

int	prepare_render(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->collected_count++;
		game->map.grid[new_y][new_x] = '0';
		ft_printf("Collectible found! Total collected: %d / %d\n",
			game->collected_count, game->total_collectibles);
	}
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->collected_count == game->total_collectibles)
		{
			game->counter++;
			ft_printf("moved to: (%d, %d) - movement count: %d\n",
				new_x, new_y, game->counter);
			ft_printf("Congratulations - You Won!!\n");
			handle_close(game);
		}
		else
		{
			ft_printf("Collect all collectibles before exiting!\n");
			return (0);
		}
	}
	collision_check(game, new_x, new_y);
	return (1);
}
