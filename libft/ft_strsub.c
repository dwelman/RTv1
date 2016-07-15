/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:15:45 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:35:14 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	if ((sub_str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sub_str[i] = s[start];
		start += 1;
		i += 1;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
