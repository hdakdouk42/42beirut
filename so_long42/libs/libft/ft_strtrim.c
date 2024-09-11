/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:33:43 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/15 14:52:11 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*trimed_str;

	if (!s1 || !set)
		return (0);
	while (*s1 && is_in_set(*s1, set))
		s1++;
	end = ft_strlen(s1);
	while (end > 0 && is_in_set(s1[end - 1], set))
		end--;
	trimed_str = (char *)malloc(end + 1);
	if (!trimed_str)
		return (0);
	ft_strlcpy(trimed_str, s1, end + 1);
	return (trimed_str);
}
