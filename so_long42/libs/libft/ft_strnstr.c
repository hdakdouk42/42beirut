/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <hdakdouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:20:38 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/08/24 19:10:21 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	else if (little_len > len)
		return (0);
	i = 0;
	while (i <= len - little_len && big[i] != '\0')
	{
		if (big[i] == little[0] && !ft_strncmp(big + i, little, little_len))
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
