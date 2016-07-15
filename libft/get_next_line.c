/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:46:49 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:22:27 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(const int fd, char **file)
{
	char		*buff;
	char		*nstr;
	int			size;

	if (!(buff = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	size = read(fd, buff, BUFF_SIZE);
	if (size > 0)
	{
		buff[size] = '\0';
		nstr = ft_strjoin(*file, buff);
		if (!(nstr))
			return (-1);
		free(*file);
		*file = nstr;
	}
	if (buff)
		free(buff);
	return (size);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*endl_index;
	int			ret;

	if (!str && !(str = (char*)malloc(sizeof(char))))
		return (-1);
	endl_index = ft_strchr(str, '\n');
	while (endl_index == NULL)
	{
		if ((ret = ft_read(fd, &str)) == 0)
		{
			if ((endl_index = ft_strchr(str, '\0')) == str)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(str, '\n');
	}
	if (!(*line = ft_strsub(str, 0, endl_index - str)))
		return (-1);
	endl_index = ft_strdup(endl_index + 1);
	free(str);
	str = endl_index;
	return (1);
}
