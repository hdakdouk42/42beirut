/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:34:26 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/15 16:35:02 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static	char	*word_dup(const char *start, size_t len)
{
	char	*word;

	word = (char *) malloc (len + 1);
	if (!word)
		return (0);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

char	**do_split(char const *s, char c, char **split, size_t index)
{
	const char	*start;

	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (start != s)
		{
			split[index] = word_dup(start, s - start);
			if (!split[index])
			{
				while (index > 0)
					free(split[--index]);
				free (split);
				return (0);
			}
			index++;
		}
	}
	split[index] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**split;
	size_t	index;

	if (!s)
		return (0);
	words_count = count_words(s, c);
	split = (char **) malloc ((words_count + 1) * sizeof(char *));
	if (!split)
		return (0);
	index = 0;
	do_split(s, c, split, index);
	return (split);
}
