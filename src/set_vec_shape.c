/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:24:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/15 11:23:53 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** Mostly norm functions to set new_start an normal for shapes.
*/

void	set_val_sphere(t_env *env, float t, t_ray ray)
{
	t_vector	scaled;

	scaled = vector_scale(t, &ray.dir);
	OBJ.new_start = vector_add(&ray.start, &scaled);
	OBJ.normal = vector_sub(&OBJ.new_start, &SP_POS(OBJ.cur_sphere));
	if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
	{
		env->br = 1;
		return ;
	}
	OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
	OBJ.cur_mat = env->obj.mats[SPHERES[OBJ.cur_sphere].shape.material];
}

void	set_val_tri(t_env *env, float t, t_ray ray)
{
	t_vector	scaled;

	scaled = vector_scale(t, &ray.dir);
	OBJ.new_start = vector_add(&ray.start, &scaled);
	OBJ.normal = TRI[OBJ.cur_tri].normal;
	if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
	{
		env->br = 1;
		return ;
	}
	OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
	OBJ.cur_mat = env->obj.mats[TRI[OBJ.cur_tri].shape.material];
}

void	set_val_cyl(t_env *env, float t, t_ray ray)
{
	t_vector	scaled;

	scaled = vector_scale(t, &ray.dir);
	OBJ.new_start = vector_add(&ray.start, &scaled);
	OBJ.normal.x = OBJ.new_start.x - CYLINDERS[OBJ.cur_cyl].center.x;
	OBJ.normal.z = OBJ.new_start.z - CYLINDERS[OBJ.cur_cyl].center.z;
	if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
	{
		env->br = 1;
		return ;
	}
	OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
	OBJ.cur_mat = env->obj.mats[CYLINDERS[OBJ.cur_cyl].shape.material];
}

void	set_val_cone(t_env *env, float t, t_ray ray)
{
	t_vector	scaled;

	scaled = vector_scale(t, &ray.dir);
	OBJ.new_start = vector_add(&ray.start, &scaled);
	OBJ.normal = vector_sub(&OBJ.new_start, &CN_POS(OBJ.cur_cone));
	if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
	{
		env->br = 1;
		return ;
	}
	OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
	OBJ.cur_mat = env->obj.mats[CONES[OBJ.cur_cone].shape.material];
}
