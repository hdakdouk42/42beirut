/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:58:30 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/10 20:22:51 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*last_occ;

	last_occ = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_occ = s;
		s++;
	}
	if (c == '\0')
		return (s);
	return (last_occ);
}
