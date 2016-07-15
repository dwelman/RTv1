/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:11:41 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:12:00 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	n;
	size_t	len;

	temp_dest = (char *)dst;
	temp_src = (char *)src;
	n = size;
	while (*temp_dest != '\0' && n-- != 0)
		temp_dest++;
	len = temp_dest - dst;
	n = size - n;
	if (n == 0)
		return (len + ft_strlen(temp_src));
	while (*temp_src != '\0')
	{
		if (n != 1)
		{
			*temp_dest++ = *temp_src;
			n--;
		}
		temp_src++;
	}
	*temp_dest = '\0';
	return (len + (temp_src - src));
}
