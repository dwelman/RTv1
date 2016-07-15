/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:09:45 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:09:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		*(dst + count) = src[count];
		count += 1;
	}
	*(dst + count) = '\0';
	return (dst);
}
