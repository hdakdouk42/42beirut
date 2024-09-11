/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:46:41 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/10 21:12:56 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_intitialization(t_game *game)
{
	load_textures(game);
	player_position(game);
	enemy_position(game);
}

int	map_is_solvable(t_game *game)
{
	if (!is_solvable(game, 'C'))
	{
		ft_printf("Error: The player can't take all collictibles\n");
		return (0);
	}
	game->collected_count = 0;
	if (!is_solvable(game, 'E'))
	{
		ft_printf("Error: The player can't reach the exit\n");
		return (0);
	}
	return (1);
}

int	load_map(const char *file_path, t_game *game)
{
	int		fd;
	char	**grid;

	grid = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	intialize_game_struct(game);
	if (!read_map_file(fd, game, grid))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

void	check_and_init_map(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./bin/so_long <map_file>.ber\n");
		exit(1);
	}
	if (validate_file_extension(argv[1]) == false)
	{
		ft_printf("Error: Invalid file extension.\n");
		exit(1);
	}
	if (!load_map(argv[1], game))
	{
		ft_printf("Error: Failed to load the map!\n");
		exit(1);
	}
	if (!validate_map(game))
	{
		free_map(&game->map);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_and_init_map(argc, argv, &game);
	game.mlx = mlx_init();
	game_intitialization(&game);
	if (!map_is_solvable(&game))
	{
		ft_printf("Error: The game's map not solvable\n");
		handle_close(&game);
	}
	game.collected_count = 0;
	game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE,
			game.map.height * TILE_SIZE, "so_long");
	render_map(&game);
	mlx_hook(game.win, 17, 0L, handle_close, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_loop(game.mlx);
	handle_close(&game);
	return (0);
}
