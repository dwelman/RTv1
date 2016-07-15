/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:13:25 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:13:26 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((dst[i] != '\0' && src[i] != '\0') && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len && dst[i] != '\0')
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
