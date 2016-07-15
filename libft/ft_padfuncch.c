/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padfuncch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 08:20:29 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:18:54 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(char chr, t_flags flags)
{
	int count;

	count = 0;
	if (flags.space == 1 && flags.negative != 1)
	{
		count += ft_putchar(' ');
		flags.padding--;
	}
	count += ft_putchar(chr);
	while (flags.padding > 0)
	{
		count += ft_putchar(flags.pad);
		flags.padding--;
	}
	return (count);
}

static int	ft_ispos(char chr, t_flags flags)
{
	int count;

	count = 0;
	if (flags.space == 1 && flags.negative != 1)
	{
		count += ft_putchar(' ');
		flags.padding--;
	}
	while (flags.padding > 0)
	{
		count += ft_putchar(flags.pad);
		flags.padding--;
	}
	count += ft_putchar(chr);
	return (count);
}

int			ft_padchar(char chr, t_flags flags)
{
	flags.padding -= 1;
	if (flags.minus == 1)
		return (ft_isneg(chr, flags));
	else
		return (ft_ispos(chr, flags));
}
