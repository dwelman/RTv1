/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 09:29:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/07 10:25:10 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		set_temp(int fd)
{
	char	*line;
	char	*temp;
	int		val;

	get_next_line(fd, &line);
	while (*line == '#')
	{
		free(line);
		get_next_line(fd, &line);
	}
	temp = ft_strchr(line, ':');
	if (temp == NULL)
	{
		ft_putstr_fd("File input error - primitive count not specified\n", 2);
		exit(-1);
	}
	temp++;
	val = ft_atoi(temp);
	free(line);
	return(val);
}

void	set_arrays(t_env *env, int fd)
{	
	env->obj.num_mats = set_temp(fd);
	env->obj.num_lights = set_temp(fd);
	env->obj.num_spheres = set_temp(fd);
	env->obj.num_tri = set_temp(fd);
	env->obj.mats = (t_material *)malloc(sizeof(t_material) *
			env->obj.num_mats);
	env->obj.lights = (t_light *)malloc(sizeof(t_light) * env->obj.num_lights);
	env->obj.spheres = (t_sphere *)malloc(sizeof(t_sphere)
			* env->obj.num_spheres);
	env->obj.triangles = (t_triangle*)malloc(sizeof(t_triangle) * env->obj.num_tri);
}

/*
** Reads input from a scene file
*/

void	get_input(t_env *env, char *file)
{
	int		fd;
	char	*skip;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Error reading file\n");
		exit(0);
	}
	set_arrays(env, fd);
	get_next_line(fd, &skip);
	free(skip);
	fill_materials(env, fd);
	fill_lights(env, fd);
	fill_spheres(env, fd);
	fill_triangles(env, fd);
}
