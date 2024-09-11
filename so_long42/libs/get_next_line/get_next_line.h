/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:07:05 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/07/06 23:50:49 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list1
{
	char			*str_buf;
	struct s_list1	*next;
}t_list1;

char		*get_next_line(int fd);
t_list1		*ft_find_lastnode(t_list1 *list);
void		ft_dalloc(t_list1 **list, t_list1 *clean_node, char *buf);
void		ft_clean_list(t_list1 **list);
void		ft_copy_str(t_list1 *list, char *next_line);
int			ft_linelen(t_list1 *list);
char		*ft_getline(t_list1 *list);
void		ft_append_list(t_list1 **list, char *buf);
int			ft_check_newline(t_list1 *list);
void		ft_create_list(t_list1 **list, int fd);

#endif
