/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 11:09:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/11 16:13:10 by ddu-toit         ###   ########.fr       */
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

void			fill_cylinders(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_cyl)
	{
		if (*line != '#')
		{
			temp = line;
			temp = set_temp(temp, 'x');
			CYLINDERS[i].shape.pos.x = ft_atoi(++temp);
			temp = set_temp(line, 'y');
			CYLINDERS[i].shape.pos.y = ft_atoi(++temp);
			temp = set_temp(++temp, 'z');
			CYLINDERS[i].shape.pos.z = ft_atoi(++temp);
			CYLINDERS[i].center = CYLINDERS[i].shape.pos;
			temp = set_temp(++temp, 'r');
			CYLINDERS[i].radius = ft_atoi(++temp);
			temp = set_temp(++temp, 'm');
			CYLINDERS[i].shape.material = ft_atoi(++temp);
			printf("cyl x = %f, y = %f, z = %f r = %f m = %d\n", CYLINDERS[i].center.x, CYLINDERS[i].center.y, CYLINDERS[i].center.z,
						CYLINDERS[i].radius, CYLINDERS[i].shape.material);
			i++;
		}
		free(line);
	}
}
