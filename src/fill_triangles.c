/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:40:39 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/07 08:50:52 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	v_read_err(char *temp)
{
	if (temp == NULL)
	{
		ft_putstr_fd("File input error - can't read vector\n", 2);
		exit(-1);
	}
}

static void	set_vector(t_vector *v, char *temp)
{
	temp = ft_strchr(temp, 'x');
	v_read_err(temp);
	v->x = 1.0f * ft_atoi(++temp);
	temp = ft_strchr(temp, 'y');
	v_read_err(temp);
	v->y = 1.0f * ft_atoi(++temp);
	temp = ft_strchr(temp, 'z');
	v_read_err(temp);
	v->z = 1.0f * ft_atoi(++temp);
}

void		fill_triangles(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) && i < env->obj.num_tri)
	{
		if (*line != '#')
		{
			temp = ft_strchr(line, '(');
			v_read_err(temp);
			set_vector(&env->obj.triangles[i].v1, temp);
			temp = ft_strchr(++temp, '(');
			set_vector(&env->obj.triangles[i].v2, temp);
			temp = ft_strchr(++temp, '(');
			v_read_err(temp);
			set_vector(&env->obj.triangles[i].v3, temp);
		}
		free(line);
	}
}
