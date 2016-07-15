/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:12:45 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:12:47 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	size_t	length;

	i = 0;
	j = 0;
	length = 0;
	while (s1[i] != '\0')
		i += 1;
	while (s2[j] != '\0' && length < n)
	{
		s1[i] = s2[j];
		i += 1;
		j += 1;
		length += 1;
	}
	s1[i] = '\0';
	return (s1);
}
