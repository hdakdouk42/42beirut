/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:05:24 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/07/13 21:44:22 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clean_list(t_list1 **list)
{
	t_list1	*last_node;
	t_list1	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list1));
	if (clean_node == NULL || buf == NULL)
		return ;
	last_node = ft_find_lastnode(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[j++] = last_node->str_buf[i];
	buf[j] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	ft_dalloc(list, clean_node, buf);
}

char	*ft_getline(t_list1 *list)
{
	char	*next_line;
	int		strlen;

	if (list == NULL)
		return (NULL);
	strlen = ft_linelen(list);
	next_line = malloc(strlen + 1);
	if (next_line == NULL)
		return (NULL);
	ft_copy_str(list, next_line);
	return (next_line);
}

void	ft_append_list(t_list1 **list, char *buf)
{
	t_list1	*new_node;
	t_list1	*last_node;

	last_node = ft_find_lastnode(*list);
	new_node = malloc(sizeof(t_list1));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	ft_create_list(t_list1 **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!ft_check_newline (*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append_list(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list1	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_getline(list);
	ft_clean_list(&list);
	return (next_line);
}
