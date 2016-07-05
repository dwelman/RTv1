/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 09:29:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/05 12:33:45 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

char	*set_temp(int fd)
{
	char	*line;
	char	*temp;

	get_next_line(fd, &line);
	temp = ft_strchr(line, ':');
	temp++;
	return(temp);
}

void	set_arrays(t_env *env, int fd)
{	
	env->obj.num_mats = ft_atoi(set_temp(fd));
	env->obj.num_lights = ft_atoi(set_temp(fd));
	env->obj.num_spheres = ft_atoi(set_temp(fd));
	env->obj.mats = (t_material *)malloc(sizeof(t_material) *
			env->obj.num_mats);
	env->obj.lights = (t_light *)malloc(sizeof(t_light) * env->obj.num_lights);
	env->obj.spheres = (t_sphere *)malloc(sizeof(t_sphere)
			* env->obj.num_spheres);
}

void	fill_lights(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_lights)
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
}

void	fill_materials(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_mats)
	{
		env->obj.mats[i].diffuse.r = ft_atoi(line);
		if (env->obj.mats[i].diffuse.r != 0)
			env->obj.mats[i].diffuse.r /= 255.0f;
		printf("%f\n", env->obj.mats[i].diffuse.r);
		temp = ft_strchr(line, '*');
		env->obj.mats[i].diffuse.g = ft_atoi(++temp);
		if (env->obj.mats[i].diffuse.g != 0)
			env->obj.mats[i].diffuse.g /= 255.0f;
		printf("%f\n", env->obj.mats[i].diffuse.g);
		temp = ft_strchr(++temp, '*');
		env->obj.mats[i].diffuse.b = ft_atoi(++temp);
		if (env->obj.mats[i].diffuse.b != 0)
			env->obj.mats[i].diffuse.b /= 255.0f;
		printf("%f\n", env->obj.mats[i].diffuse.b);
		temp = ft_strchr(++temp, '*');
		env->obj.mats[i].reflection = ft_atoi(++temp);
		if (env->obj.mats[i].reflection != 0)
			env->obj.mats[i].reflection /= 10.0f;
		printf("%f\n", env->obj.mats[i].reflection);
		i++;
	}
}

/*
** Reads input from a scene file
*/

void	get_input(t_env *env, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Error reading file\n");
		exit(0);
	}
	set_arrays(env, fd);
	fill_materials(env, fd);
	fill_lights(env, fd);
	fill_spheres(env, fd);
}
