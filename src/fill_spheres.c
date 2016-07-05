/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 11:09:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/05 11:53:10 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	fill_spheres(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_spheres)
	{
		env->obj.spheres[i].shape.pos.x = ft_atoi(line);
		temp = ft_strchr(line, '*');
		env->obj.spheres[i].shape.pos.y = ft_atoi(++temp);
		temp = ft_strchr(++temp, '*');
		env->obj.spheres[i].shape.pos.z = ft_atoi(++temp);
		temp = ft_strchr(++temp, '*');
		env->obj.spheres[i].radius = ft_atoi(++temp);
		temp = ft_strchr(++temp, '*');
		env->obj.spheres[i].shape.material = ft_atoi(++temp);
		i++;
	}
}
