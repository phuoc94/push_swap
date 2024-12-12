/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:21:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/08 15:29:54 by phuocngu         ###   ########.fr       */
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

static size_t	wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_all(char **ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
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
		cwordlen = wordlen(&s[i], c);
		strs[current_word] = malloc((cwordlen + 1) * sizeof(char));
		if (!strs[current_word])
		{
			free_all(strs, current_word);
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
