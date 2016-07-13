/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:24:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/13 15:52:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** Calculate ray - primitive intesection.
*/
/*
void			get_intersections(t_env *env, t_ray ray, float *t)
{
	int			i;
	float		t1 = *t;
	float		t2 = *t;
	float		t3 = *t;
	t_vector	n;
	t_vector	scaled;
	t_vector	ns;
	t_vector	nc;

	i = 0;
	OBJ.cur_sphere = -1;
	float ref_dist = 3.402823e+38;
	while (i < OBJ.num_spheres)
	{
		if (intersect_ray_sphere(&ray, &OBJ.spheres[i], &t1))
		{
			scaled = vector_scale(t1, &ray.dir);
			ns = vector_add(&ray.start, &scaled);
			SPHERES[i].shape.dist = vector_dist(&ns, &ray.start);
			if (SPHERES[i].shape.dist < ref_dist)
			{
				*t = t1;
				ref_dist = SPHERES[i].shape.dist;
				OBJ.cur_sphere = i;
			}
		}
		i++;
	}
	i = 0;
	OBJ.cur_tri = -1;
	while (i < OBJ.num_tri)
	{
		if (intersect_ray_tri(&ray, &OBJ.triangles[i], &t2, &n))
		{
			scaled = vector_scale(t2, &ray.dir);
			ns = vector_add(&ray.start, &scaled);
			TRI[i].shape.dist = vector_dist(&ns, &ray.start);
			if (TRI[i].shape.dist < ref_dist)
			{
				*t = t2;
				ref_dist = TRI[i].shape.dist;
				OBJ.cur_tri = i;
				TRI[i].normal = n;
				OBJ.cur_sphere = -1;
			}
		}
		i++;
	}
	i = 0;
	OBJ.cur_cyl = -1;
	while (i < OBJ.num_cyl)
	{
		if (intersect_ray_cylinder(&ray, &CYLINDERS[i], &t3))
		{
			scaled = vector_scale(t3, &ray.dir);
			nc = vector_add(&ray.start, &scaled);
			CYLINDERS[i].shape.dist = vector_dist(&nc, &ray.start);
			if (nc.x == 393 && nc.y == 275)
			{
				printf("cross INTERSECT CYL AT %f %f %f\n", nc.x, nc.y, nc.z);
				printf("DIST %f\n", CYLINDERS[i].shape.dist);
				printf("ref %f\n", ref_dist);
			}
			if (CYLINDERS[i].shape.dist < ref_dist)
			{
				*t = t3;
				ref_dist = CYLINDERS[i].shape.dist;
				OBJ.cur_cyl = i;
				OBJ.cur_sphere = -1;
				OBJ.cur_tri = -1;
			}
		}
		i++;
	}

}
*/

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
		get_intersections(env, ray, &t);
		if (OBJ.cur_sphere != -1)
		{
			scaled = vector_scale(t, &ray.dir);
			OBJ.new_start = vector_add(&ray.start, &scaled);
			OBJ.normal = vector_sub(&OBJ.new_start, &SP_POS(OBJ.cur_sphere));
			if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
				break ;
			OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
			OBJ.cur_mat = env->obj.mats[SPHERES[OBJ.cur_sphere].shape.material];
		}
		else if (OBJ.cur_tri != -1)
		{
			scaled = vector_scale(t, &ray.dir);
			OBJ.new_start = vector_add(&ray.start, &scaled);
			OBJ.normal = TRI[OBJ.cur_tri].normal;
			if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
				break ;
			OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
			OBJ.cur_mat = env->obj.mats[TRI[OBJ.cur_tri].shape.material];
		}
		else if (OBJ.cur_cyl != -1)
		{
			OBJ.active_shape = CYLINDER;
			scaled = vector_scale(t, &ray.dir);
			OBJ.new_start = vector_add(&ray.start, &scaled);
			if (OBJ.new_start.x == 200 && OBJ.new_start.y == 185)
				print_vector("1ns = ", OBJ.new_start);
			if (OBJ.new_start.x == 200 && OBJ.new_start.y == 434)
				print_vector("2ns = ", OBJ.new_start);
	//		OBJ.normal = vector_sub(&OBJ.new_start, &CYL_POS(OBJ.cur_cyl));
			OBJ.normal.x = OBJ.new_start.x - CYLINDERS[OBJ.cur_cyl].center.x;
			OBJ.normal.z = OBJ.new_start.z - CYLINDERS[OBJ.cur_cyl].center.z;
//			OBJ.normal.y = CYLINDERS[OBJ.cur_cyl].center.y - CYLINDERS[OBJ.cur_cyl].radius;
			if (vector_dot(&OBJ.normal, &OBJ.normal) == 0)
				break ;
			OBJ.normal = vector_scale(1.0f / ABSV(OBJ.normal), &OBJ.normal);
			OBJ.cur_mat = env->obj.mats[CYLINDERS[OBJ.cur_cyl].shape.material];
		}
		else
			break;
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
	env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.r;
	env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.g;
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
			ray.start = new_vector(x, y, -5000);
			ray.dir = new_vector(0, 0, 1);
			col = shoot_ray(ray, 10, env);
			save_to_img(env, col, x, y);
			x++;
		}
		y++;
	}
}
