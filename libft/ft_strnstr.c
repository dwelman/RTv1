/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:14:05 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:14:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		count_i;
	int		count_j;
	int		count_c;
	size_t	length;

	length = 0;
	count_i = -1;
	if (little[0] == '\0')
		return ((char*)(big));
	while (big[++count_i] != '\0' && length < len)
	{
		count_j = count_i;
		count_c = 0;
		while (big[count_j] == little[count_c])
		{
			count_j += 1;
			count_c += 1;
			if (little[count_c] == '\0')
				return ((char*)(&big[count_i]));
		}
		length += 1;
	}
	return (NULL);
}
