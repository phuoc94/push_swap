/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:29 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/08 18:43:40 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_minval(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && size == 0)
		return (0);
	dst_len = ft_minval(ft_strlen(dst), size);
	src_len = ft_strlen(src);
	if (size == dst_len)
		return (src_len + size);
	if (src_len < (size - dst_len))
		ft_memcpy((&dst[dst_len]), src, (src_len + 1));
	else
	{
		ft_memcpy((&dst[dst_len]), src, (size - dst_len - 1));
		dst[size - 1] = '\0';
	}
	return (dst_len + src_len);
}
