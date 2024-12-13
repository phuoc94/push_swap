/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:28 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/13 15:24:30 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_to_digit(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

static size_t	ft_skip_whitespace(const char *nptr)
{
	size_t	i;

	i = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	return (i);
}

static int	ft_parse_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (sign);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	size_t	i;
	int		sign;
	long	result;
	int		digit;

	if (base < 2 || base > 36)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	i = ft_skip_whitespace(nptr);
	nptr += i;
	sign = ft_parse_sign(&nptr);
	result = 0;
	digit = ft_char_to_digit(*nptr);
	while ((digit >= 0) && (digit < base))
	{
		result = result * base + digit;
		nptr++;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}
