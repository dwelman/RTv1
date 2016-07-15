/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 14:20:14 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:20:57 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flags	ft_initflags(t_flags flags)
{
	flags.plus = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.zero = 0;
	flags.space = 0;
	flags.hash = 0;
	flags.padding = 0;
	flags.offset = 0;
	flags.negative = 0;
	flags.use_hasho = 0;
	flags.use_hashx = 0;
	flags.address = 0;
	flags.precision = -1;
	flags.zeroes = 0;
	flags.is_string = 0;
	flags.is_long = 0;
	flags.is_short = 0;
	flags.pad = ' ';
	flags.z = 0;
	flags.j = 0;
	flags.wide = 0;
	return (flags);
}

static int		ft_checkflags(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd')
		return (1);
	if (c == 'D' || c == 'i' || c == 'o' || c == 'O')
		return (1);
	if (c == 'u' || c == 'U' || c == 'x' || c == 'X')
		return (1);
	if (c == 'c' || c == 'C')
		return (1);
	return (0);
}

static t_flags	ft_auxflags(t_flags flags, char *cr, int i)
{
	if (*(cr + i) == '-')
		flags.minus = 1;
	if (*(cr + i) == '+')
		flags.plus = 1;
	if (*(cr + i) == '#')
		flags.hash = 1;
	if (*(cr + i) == '0')
	{
		flags.zero = 1;
		flags.pad = '0';
	}
	if (*(cr + i) == ' ')
		flags.space = 1;
	if (*(cr + i) == 'l')
		flags.is_long++;
	if (*(cr + i) == 'h')
		flags.is_short++;
	if (*(cr + i) == 'z')
		flags.z = 1;
	if (*(cr + i) == 'j')
		flags.j = 1;
	return (flags);
}

t_flags			ft_auxflags2(t_flags flags, char *cr, int i)
{
	int	k;

	if (ft_isdigit(*(cr + i)) == 1)
	{
		k = 0;
		while (ft_isdigit(*(cr + i + k)) == 1)
			k++;
		flags.padding = ft_atoi(ft_strsub(cr, i, k));
		i += k - 1;
	}
	if (*(cr + i) == '.')
	{
		k = 0;
		i++;
		while (ft_isdigit(*(cr + i + k)) == 1)
			k++;
		flags.precision = ft_atoi(ft_strsub(cr, i, k));
		i += k - 1;
	}
	return (flags);
}

t_flags			ft_getflags(t_flags flags, char *cr)
{
	int	i;

	flags = ft_initflags(flags);
	i = 0;
	while (*(cr + i) && ft_checkflags(*(cr + i)) == 0)
	{
		flags = ft_auxflags(flags, cr, i);
		flags = ft_auxflags2(flags, cr, i);
		i++;
	}
	flags.offset = i;
	return (flags);
}
