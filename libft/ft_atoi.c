/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:57:09 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 12:57:20 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int result;
	int	a;

	sign = 1;
	result = 0;
	a = 0;
	while (str[a] == '\n' || str[a] == '\t' || str[a] == ' ')
		a += 1;
	if (str[a] == '-')
	{
		sign = -1;
		a += 1;
	}
	while (str[a] != '\0')
	{
		if (str[a] >= '0' && str[a] <= '9')
			result = (result * 10) + str[a] - 48;
		else
			return (result * sign);
		a += 1;
	}
	return (result * sign);
}
