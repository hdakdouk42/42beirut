/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:40:37 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/11 17:03:27 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	validate_file_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		return (false);
	}
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	validate_map(t_game *game)
{
	if (!valid_map_lines(game))
		return (0);
	if (!valid_elements(game))
		return (0);
	if (!valid_borders(game))
		return (0);
	if (game->total_collectibles < 1 || game->total_exits != 1
		|| game->total_players != 1)
	{
		ft_printf("Error: The map does't match the requirments\n");
		return (0);
	}
	return (1);
}

int	valid_map_lines(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	if (game->map.height < 3)
	{
		ft_printf("Error: The map is invalid.\n");
		return (0);
	}
	while (i < game->map.height)
	{
		len = ft_strlen(game->map.grid[i]) - 1;
		if (i == game->map.height - 1)
			len += 1;
		if (len != game->map.width)
		{
			ft_printf("Error: All lines must have the same length.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] != '1' && game->map.grid[i][j] != '0'
				&& game->map.grid[i][j] != 'P' && game->map.grid[i][j] != 'C'
				&& game->map.grid[i][j] != 'I' && game->map.grid[i][j] != 'E'
				&& game->map.grid[i][j] != '\n')
			{
				ft_printf("Error: The map must have \"1 0 C P I E\".\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i][0] != '1'
			|| game->map.grid[i][game->map.width - 1] != '1')
		{
			ft_printf("Error: The map borders must be walls ('1').\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map.width)
	{
		if (game->map.grid[0][i] != '1'
			|| game->map.grid[game->map.height - 1][i] != '1')
		{
			ft_printf("Error: The map borders must be walls ('1').\n");
			return (0);
		}
		i++;
	}
	return (1);
}
