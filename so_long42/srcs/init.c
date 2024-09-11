/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:20:53 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/07 23:24:09 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_texture(t_game *game, t_img *texture, const char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, (char *)path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_printf("Failed to load texture: %s\n", path);
		handle_close(game);
	}
}	

void	load_textures(t_game *game)
{
	load_texture(game, &game->closed_door, "./assets/images/exit_close_01.xpm");
	load_texture(game, &game->enemy, "./assets/images/enemy_00.xpm");
	load_texture(game, &game->player, "./assets/images/idle_00.xpm");
	load_texture(game, &game->wall, "./assets/images/block.xpm");
	load_texture(game, &game->empty, "./assets/images/midBlocks_02.xpm");
	load_texture(game, &game->collectible, "./assets/images/star_00.xpm");
	load_texture(game, &game->exit, "./assets/images/exit_open_01.xpm");
}

void	player_position(t_game *game)
{
	int	y;
	int	x;

	game->player_x = -1;
	game->player_y = -1;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	check_init_enemies(t_game *game, int x, int y, t_enemy **new_enemies)
{
	int		i;

	if (game->map.grid[y][x] == 'I')
	{
		game->enemy_count++;
		*new_enemies = ft_calloc(game->enemy_count, sizeof(t_enemy));
		if (!(*new_enemies))
			handle_close(game);
		if (game->enemies)
		{
			i = 0;
			while (i < game->enemy_count - 1)
			{
				(*new_enemies)[i] = game->enemies[i];
				i++;
			}
			free(game->enemies);
		}
		(*new_enemies)[game->enemy_count - 1].x = x;
		(*new_enemies)[game->enemy_count - 1].y = y;
		game->enemies = *new_enemies;
	}
}

void	enemy_position(t_game *game)
{
	int		y;
	int		x;
	t_enemy	*new_enemies;

	game->enemy_count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			check_init_enemies(game, x, y, &new_enemies);
			x++;
		}
		y++;
	}
}
