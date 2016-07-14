/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 11:09:03 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/14 15:11:06 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static char		*set_temp(char *ptr, char c)
{
	char	*temp;

	temp = ft_strchr(ptr, c);
	if (temp == NULL)
	{
		ft_putstr_fd("File input error - Problem reading cylinder data\n", 2);
		exit(-1);
	}
	return (temp);
}

void			fill_cone(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < OBJ.num_cone)
	{
		if (*line != '#')
		{
			temp = line;
			temp = set_temp(temp, 'x');
			CONES[i].shape.pos.x = ft_atoi(++temp);
			temp = set_temp(line, 'y');
			CONES[i].shape.pos.y = ft_atoi(++temp);
			temp = set_temp(++temp, 'z');
			CONES[i].shape.pos.z = ft_atoi(++temp);
			CONES[i].center = CONES[i].shape.pos;
			temp = set_temp(++temp, 'r');
			CONES[i].radius = ft_atoi(++temp);
			temp = set_temp(++temp, 'm');
			CONES[i].shape.material = ft_atoi(++temp);
			i++;
		}
		free(line);
	}
}
