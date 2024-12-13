/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:21:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/13 19:54:21 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(s);
	words = 0;
	i = 0;
	while (i < str_len)
	{
		while (s[i] == c)
			i++;
		if (i < str_len && s[i] != c)
		{
			words++;
			while (i < str_len && s[i] != c)
				i++;
		}
	}
	return (words);
}

void	free_ft_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	split(char **strs, const char *s, char c, size_t n)
{
	size_t	i;
	size_t	current_word;
	size_t	cwordlen;

	current_word = 0;
	i = 0;
	while (current_word < n)
	{
		while (s[i] == c)
			i++;
		cwordlen = ft_strclen(&s[i], c);
		strs[current_word] = malloc((cwordlen + 1) * sizeof(char));
		if (!strs[current_word])
		{
			free_ft_split(strs);
			return (0);
		}
		ft_strlcpy(strs[current_word], &s[i], cwordlen + 1);
		i = i + cwordlen;
		current_word++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	strslen;

	strslen = count_words(s, c);
	strs = malloc((strslen + 1) * (sizeof(char *)));
	if (!strs)
		return (NULL);
	strs[strslen] = 0;
	if (!(split(strs, s, c, strslen)))
		return (NULL);
	return (strs);
}
