/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:04:05 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:04:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	x;
	size_t			i;

	i = 0;
	x = (unsigned char)c;
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	while (i < n)
	{
		if ((str1[i] = str2[i]) == x)
			return ((void *)&(dst[i + 1]));
		i++;
	}
	return (NULL);
}
