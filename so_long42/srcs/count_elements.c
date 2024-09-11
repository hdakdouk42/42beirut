/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:58:45 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/09/10 20:59:54 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_players(const char *line, int width)
{
	int	i;
	int	players;

	i = 0;
	players = 0;
	if (width != (int)ft_strlen(line) - 1)
		return (0);
	while (i < width)
	{
		if (line[i] == 'P')
			players++;
		i++;
	}
	return (players);
}

int	count_exits(const char *line, int width)
{
	int	i;
	int	exits;

	i = 0;
	exits = 0;
	if (width != (int)ft_strlen(line) - 1)
		return (0);
	while (i < width)
	{
		if (line[i] == 'E')
			exits++;
		i++;
	}
	return (exits);
}

int	count_collectibles(const char *line, int width)
{
	int	i;
	int	collectibles;

	i = 0;
	collectibles = 0;
	if (width != (int)ft_strlen(line) - 1)
		return (0);
	while (i < width)
	{
		if (line[i] == 'C')
			collectibles++;
		i++;
	}
	return (collectibles);
}
