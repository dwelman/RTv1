/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:50:22 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:15:33 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_uoxcont(char *cr, va_list args, t_flags flags, int count)
{
	if (*cr == 'o')
		count += ft_padstr(ft_convert(va_arg(args, UI), 8, 0), flags);
	else if (*cr == 'O')
		count += ft_padstr(ft_convert(va_arg(args, LUI), 8, 1), flags);
	else if (*cr == 'x')
		count += ft_padstr(ft_convert(va_arg(args, UI), 16, 0), flags);
	else if (*cr == 'X')
	{
		flags.use_hashx = 2;
		count += ft_padstr(ft_convert(va_arg(args, LUI), 16, 1), flags);
	}
	return (count);
}

int			ft_uox(char *cr, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (*cr == 'u')
	{
		flags.is_num = 1;
		if (flags.z == 1)
			count += ft_padstr(ft_convert_u(va_arg(args, ST), 10, 0), flags);
		else if (flags.j == 1)
			count += ft_padstr(ft_convert(va_arg(args, UIM), 10, 0), flags);
		else if (flags.is_long > 1)
			count += ft_padstr(ft_convert(va_arg(args, UL), 10, 0), flags);
		if (flags.is_long > 0)
			count += ft_padstr(ft_convert(va_arg(args, ULL), 10, 0), flags);
		else
			count += ft_padstr(ft_convert(va_arg(args, UI), 10, 0), flags);
	}
	else if (*cr == 'U')
	{
		flags.is_num = 1;
		count += ft_padstr(ft_convert(va_arg(args, LUI), 10, 0), flags);
	}
	count += ft_uoxcont(cr, args, flags, count);
	return (count);
}

static int	ft_dicont(char *cr, va_list args, t_flags flags, int count)
{
	int	i;

	i = 0;
	flags.is_num = 1;
	if (*cr == 'd' || *cr == 'i' || *cr == 'D')
	{
		i = va_arg(args, int);
		if (i < 0)
		{
			i *= -1;
			flags.negative = 1;
		}
		count += ft_padstr(ft_convert(i, 10, 0), flags);
	}
	else if ((*cr == 'd' || *cr == 'i') && flags.is_long > 0)
	{
		i = va_arg(args, long);
		if (i < 0)
		{
			i *= -1;
			flags.negative = 1;
		}
		count += ft_padstr(ft_convert(i, 10, 0), flags);
	}
	return (count);
}

int			ft_di(char *cr, va_list args, t_flags flags)
{
	int				count;
	int				lli;
	unsigned long	ul;

	count = 0;
	if ((*cr == 'd' || *cr == 'i' || *cr == 'D') && flags.is_long > 1)
	{
		lli = va_arg(args, long long);
		flags.is_num = 1;
		if (lli < 0)
		{
			lli *= -1;
			flags.negative = 1;
		}
		count += ft_padstr(ft_convert(lli, 10, 0), flags);
	}
	else if (*cr == 'D')
	{
		ul = va_arg(args, unsigned long);
		flags.is_num = 1;
		count += ft_padstr(ft_convert(ul, 10, 0), flags);
	}
	count += ft_dicont(cr, args, flags, count);
	return (count);
}
