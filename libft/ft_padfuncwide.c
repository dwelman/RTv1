/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padfuncwide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:01:28 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:16:31 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(wchar_t *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.is_string == 1 && flags.precision > 0)
		while (*str != '\0' && flags.precision > 0)
		{
			count++;
			ft_putchar((char)*str);
			str++;
			flags.precision--;
		}
	else
	{
		count += ft_strlenwide(str);
		ft_putstrwide(str);
	}
	while (flags.padding > 0)
	{
		count++;
		ft_putchar(flags.pad);
		flags.padding--;
	}
	return (count);
}

static int	ft_ispos(wchar_t *str, t_flags flags)
{
	int	count;

	count = 0;
	while (flags.padding > 0)
	{
		count++;
		ft_putchar(' ');
		flags.padding--;
	}
	if (flags.is_string == 1 && flags.precision > 0)
		while (*str != '\0' && flags.precision > 0)
		{
			count++;
			ft_putchar((char)*str);
			str++;
			flags.precision--;
		}
	else
	{
		count += ft_strlenwide(str);
		ft_putstrwide(str);
	}
	return (count);
}

int			ft_padstrwide(wchar_t *str, t_flags flags)
{
	if ((int)ft_strlenwide(str) >= flags.precision && flags.padding > 0)
		flags.padding = flags.padding - flags.precision;
	else
		flags.padding -= ft_strlenwide(str);
	if (flags.minus == 1)
		return (ft_isneg(str, flags));
	else
		return (ft_ispos(str, flags));
}
