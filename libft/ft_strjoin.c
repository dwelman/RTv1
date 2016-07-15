/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:11:27 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 13:11:29 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_new = (char*)malloc(sizeof(char) * len);
	if (str_new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str_new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		str_new[i + j] = s2[j];
	str_new[i + j] = '\0';
	return (str_new);
}
