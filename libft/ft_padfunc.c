/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 08:06:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:19:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegcont(char *str, t_flags flags, int count)
{
	if (flags.negative == 1)
		count += ft_putchar('-');
	else if (flags.plus == 1 && flags.is_num == 1)
		count += ft_putchar('+');
	if (flags.is_string == 1 && flags.precision > 0)
		while (*str != '\0' && flags.precision > 0)
		{
			count += ft_putchar(*str);
			str++;
			flags.precision--;
		}
	else
		count += ft_putstr(str);
	while (flags.padding > 0)
	{
		count += ft_putchar(flags.pad);
		flags.padding--;
	}
	return (count);
}

static int	ft_isneg(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.address == 1)
		flags.padding -= 6;
	if (flags.zero == 1 && flags.is_num == 1)
		flags.pad = ' ';
	if (flags.address == 1)
		count += ft_putstr("0x7fff");
	if (flags.hash == 1 && flags.use_hasho == 1)
		count += ft_putchar('0');
	else if (flags.hash == 1 && flags.use_hashx == 1)
		count += ft_putstr("0x");
	else if (flags.hash == 1 && flags.use_hashx == 2)
		count += ft_putstr("0X");
	while (flags.zeroes > 0)
	{
		count += ft_putchar('0');
		flags.padding--;
		flags.zeroes--;
	}
	if (flags.space == 1 && flags.negative != 1)
		count += ft_putchar(' ');
	return (ft_isnegcont(str, flags, count));
}

static int	ft_isposcont(char *str, t_flags flags, int count)
{
	if (flags.hash == 1 && flags.use_hasho == 1 && flags.zero == 0)
		count += ft_putchar('0');
	else if (flags.hash == 1 && flags.use_hashx == 1 && flags.zero == 0)
		count += ft_putstr("0x");
	else if (flags.hash == 1 && flags.use_hashx == 2)
		count += ft_putstr("0X");
	while (flags.zeroes > 0)
	{
		count += ft_putchar('0');
		flags.padding--;
		flags.zeroes--;
	}
	if (flags.address == 1)
		count += ft_putstr("0x7fff");
	if (flags.is_string == 1 && flags.precision > 0)
		while (*str != '\0' && flags.precision > 0)
		{
			count += ft_putchar(*str);
			str++;
			flags.precision--;
		}
	else
		count += ft_putstr(str);
	return (count);
}

static int	ft_ispos(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.address == 1)
		flags.padding -= 6;
	if (flags.zero == 1 && flags.is_num == 1)
		flags.pad = ' ';
	if (flags.zeroes > 0)
		flags.padding -= flags.zeroes;
	if (flags.space == 1 && flags.negative != 1)
		count += ft_putchar(' ');
	if (flags.zero == 1 && flags.plus == 1 && flags.is_num == 1)
		count += ft_putchar('+');
	if (flags.zero == 1 && flags.negative == 1 && flags.is_num == 1)
		count += ft_putchar('-');
	while (flags.padding > 0)
	{
		if (flags.zero == 1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		flags.padding--;
	}
	return (ft_isposcont(str, flags, count));
}

int			ft_padstr(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if ((int)ft_strlen(str) >= flags.precision && flags.padding > 0)
		flags.padding = flags.padding - flags.precision;
	else
		flags.padding -= ft_strlen(str);
	if (flags.use_hasho == 1)
		flags.zeroes--;
	if (flags.use_hashx > 0 || flags.use_hasho == 1 || flags.is_num == 1)
		flags.zeroes = flags.precision - ft_strlen(str);
	if (flags.space == 1 && flags.negative != 1)
		flags.padding--;
	if (flags.negative == 1)
		flags.padding--;
	else if (flags.plus == 1 && flags.is_num == 1)
		flags.padding--;
	if (flags.hash == 1 && flags.use_hasho == 1)
		flags.padding--;
	else if (flags.hash == 1 && flags.use_hashx > 0)
		flags.padding -= 2;
	if (flags.minus == 1)
		return (ft_isneg(str, flags));
	else
		return (ft_ispos(str, flags));
}
