/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:24:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/08 18:10:12 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** Calculate ray - primitive intesection.
*/

void			get_intersections(t_env *env, t_ray ray, float *t)
{
	int			i;
	t_vector	n;

	i = 0;
	OBJ.cur_sphere = -1;
	while (i < OBJ.num_spheres)
	{
		if (intersect_ray_sphere(&ray, &OBJ.spheres[i], t))
			OBJ.cur_sphere = i;
		i++;
	}
	i = 0;
	OBJ.cur_tri = -1;
	while (i < OBJ.num_tri)
	{
		if (intersect_ray_tri(&ray, &env->obj.triangles[i], t, &n))
		{
			OBJ.cur_tri = i;
			OBJ.cur_sphere = -1;
		}
		i++;
	}
}

/*
** Reflect ray around normal.
*/

static t_vector		reflect_ray(t_env *env, t_ray *ray)
{
	float		reflect;
	t_vector	tmp;
	t_vector	new_dir;

	ray->start = OBJ.new_start;
	reflect = 2.0f * vector_dot(&ray->dir, &OBJ.normal);
	tmp = vector_scale(reflect, &OBJ.normal);
	ray->dir = vector_sub(&ray->dir, &tmp);
	return (new_dir);
}

/*
** Shoot ray and calculate color value based on reflection, shadows
** and materials.
*/

static t_col		shoot_ray(t_ray ray, int level_max, t_env *env)
{
	float		coef;
	float		t;
	t_vector	scaled;

	coef = 1.0;
	set_col(&OBJ.col, 0, 0, 0);
	while (coef > 0.0f && level_max--)
	{
		t = 20000.0f;
		env->obj.cur_sphere = -1;
		get_intersections(env, ray, &t);
		if (OBJ.cur_sphere == -1)
			break ;
		scaled = vector_scale(t, &ray.dir);
		OBJ.new_start = vector_add(&ray.start, &scaled);
		OBJ.normal = vector_sub(&OBJ.new_start, &SP_POS(OBJ.cur_sphere));
		OBJ.normal = TR_POS(OBJ.cur_tri);
		if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
			break ;
		OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
		OBJ.cur_mat = env->obj.mats[SPHERES[OBJ.cur_sphere].shape.material];
		OBJ.cur_mat = env->obj.mats[TRI[OBJ.cur_tri].shape.material];
		calc_lighting(env, coef);
		coef *= OBJ.cur_mat.reflection;
		reflect_ray(env, &ray);
	}
	return (OBJ.col);
}

/*
** Save color value to image.
*/

static void			save_to_img(t_env *env, t_col col, int x, int y)
{
	t_col temp;

	if (col.r * 255.0f < 255.0f)
		temp.r = col.r * 255.0f;
	else
		temp.r = 255.0f;
	if (col.g * 255.0f < 255.0f)
		temp.g = col.g * 255.0f;
	else
		temp.g = 255.0f;
	if (col.b * 255.0f < 255.0f)
		temp.b = col.b * 255.0f;
	else
		temp.b = 255.0f;
	env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.r;
	env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.g;
	env->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp.b;
}

/*
** Iterate through each pixel, shoot ray into scene for each and save returned
** colour value to image.
*/

void				raytrace(t_env *env)
{
	int		x;
	int		y;
	t_ray	ray;
	t_col	col;

	y = 0;
	while (y <= WIN_Y)
	{
		x = 0;
		while (x <= WIN_X)
		{
			ray.start = new_vector(x, y, -2000);
			ray.dir = new_vector(0, 0, 1);
			col = shoot_ray(ray, 5, env);
			save_to_img(env, col, x, y);
			x++;
		}
		y++;
	}
}
