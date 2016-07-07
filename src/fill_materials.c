/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 09:29:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/07 09:17:03 by ddu-toit         ###   ########.fr       */
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
void	fill_lights(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_lights)
	{
		if (*line != '#')
		{
			env->obj.lights[i].pos.x = ft_atoi(line);
			temp = ft_strchr(line, '*');
			env->obj.lights[i].pos.y = ft_atoi(++temp);
			temp = ft_strchr(++temp, '*');
			env->obj.lights[i].pos.z = ft_atoi(++temp);
			temp = ft_strchr(++temp, '*');
			env->obj.lights[i].intensity.r = ft_atoi(++temp);
			if (env->obj.lights[i].intensity.r != 0)
				env->obj.lights[i].intensity.r /= 255.0f;
			temp = ft_strchr(++temp, '*');
			env->obj.lights[i].intensity.g = ft_atoi(++temp);
			if (env->obj.lights[i].intensity.g != 0)
				env->obj.lights[i].intensity.g /= 255.0f;
				temp = ft_strchr(++temp, '*');
			env->obj.lights[i].intensity.b = ft_atoi(++temp);
			if (env->obj.lights[i].intensity.b != 0)
				env->obj.lights[i].intensity.b /= 255.0f;
			i++;
		}
		free(line);
	}
}
*/
void	fill_materials(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_mats)
	{
		if (*line != '#')
		{
			env->obj.mats[i].diffuse.r = 1.0f * ft_atoi(line);
			if (env->obj.mats[i].diffuse.r != 0)
				env->obj.mats[i].diffuse.r /= 255;
			temp = ft_strchr(line, '*');
			env->obj.mats[i].diffuse.g = 1.0f * ft_atoi(++temp);
			if (env->obj.mats[i].diffuse.g != 0)
				env->obj.mats[i].diffuse.g /= 255;
			temp = ft_strchr(++temp, '*');
			env->obj.mats[i].diffuse.b = 1.0f * ft_atoi(++temp);
			if (env->obj.mats[i].diffuse.b != 0)
				env->obj.mats[i].diffuse.b /= 255;
			temp = ft_strchr(++temp, '*');
			env->obj.mats[i].reflection = 1.0f * ft_atoi(++temp);
			if (env->obj.mats[i].reflection != 0)
				env->obj.mats[i].reflection /= 10.0f;
			i++;
		}
		free(line);
	}
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
