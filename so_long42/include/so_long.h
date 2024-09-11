/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:14:13 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/10 20:58:21 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/libftprintf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_coord
{
	int	x;
	int	y;
}t_coord;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	player;
	t_img	wall;
	t_img	empty;
	t_img	collectible;
	t_img	exit;
	t_img	enemy;
	t_img	closed_door;
	int		player_x;
	int		player_y;
	t_enemy	*enemies;
	int		enemy_count;
	int		collected_count;
	int		total_collectibles;
	int		total_exits;
	int		total_players;
	int		counter;
}			t_game;

void	game_intitialization(t_game *game);
void	check_and_init_map(int argc, char **argv, t_game *game);
int		count_players(const char *line, int width);
int		count_exits(const char *line, int width);
int		count_collectibles(const char *line, int width);
void	free_map(t_map *map);
void	free_textures(t_game *game);
int		handle_close(void *param);
void	load_texture(t_game *game, t_img *texture, const char *path);
void	load_textures(t_game *game);
void	player_position(t_game *game);
void	check_init_enemies(t_game *game, int x, int y, t_enemy **new_enemies);
void	enemy_position(t_game *game);
bool	validate_file_extension(const char *filename);
int		validate_map(t_game *game);
int		valid_map_lines(t_game *game);
int		valid_elements(t_game *game);
int		valid_borders(t_game *game);
int		handle_key(int keycode, void *param);
int		collision_check(t_game *game, int new_x, int new_y);
int		prepare_render(t_game *game, int new_x, int new_y);
int		read_map_file(int fd, t_game *game, char **new_grid);
void	render_tile(t_game *game, void *img, int x, int y);
void	render_map_help(t_game *game, int y);
void	render_map(t_game *game);
int		load_map(const char *file_path, t_game *game);
int		map_is_solvable(t_game *game);
bool	check_reachable(t_game *game, int **visited, char p);
bool	is_valid_position(int x, int y, t_game *game, char p);
void	flood_fill(t_game *game, t_coord coord, int **visited, char p);
void	free_array(int **array, int len);
bool	is_solvable(t_game *game, char p);
void	intialize_game_struct(t_game *game);

#endif