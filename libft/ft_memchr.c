/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:04:17 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:04:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			len;

	len = 0;
	str = (unsigned char*)s;
	while (len < n)
	{
		if (str[len] == (unsigned char)c)
			return ((char*)(&str[len]));
		len += 1;
	}
	return (NULL);
}
