/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:24:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/15 11:37:37 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** Calculate ray - primitive intesection.
*/

static void		gi_sphere(t_env *env, t_ray ray, float *t, float *ref_dist)
{
	int			i;
	float		t1;
	t_vector	scaled;
	t_vector	ns;

	t1 = *t;
	i = 0;
	OBJ.cur_sphere = -1;
	while (i < OBJ.num_spheres)
	{
		if (intersect_ray_sphere(&ray, &OBJ.spheres[i], &t1))
		{
			scaled = vector_scale(t1, &ray.dir);
			ns = vector_add(&ray.start, &scaled);
			SPHERES[i].shape.dist = vector_dist(&ns, &ray.start);
			if (SPHERES[i].shape.dist < *ref_dist)
			{
				*t = t1;
				*ref_dist = SPHERES[i].shape.dist;
				OBJ.cur_sphere = i;
			}
		}
		i++;
	}
}

static void		gi_tri(t_env *env, t_ray ray, float *t, float *ref_dist)
{
	int			i;
	t_vector	n;
	t_vector	nt;
	float		t2;
	t_vector	scaled;

	t2 = *t;
	i = -1;
	OBJ.cur_tri = -1;
	while (++i < OBJ.num_tri)
		if (intersect_ray_tri(&ray, &OBJ.triangles[i], &t2, &n))
		{
			scaled = vector_scale(t2, &ray.dir);
			nt = vector_add(&ray.start, &scaled);
			TRI[i].shape.dist = vector_dist(&nt, &ray.start);
			if (TRI[i].shape.dist < *ref_dist)
			{
				*t = t2;
				*ref_dist = TRI[i].shape.dist;
				OBJ.cur_tri = i;
				TRI[i].normal = n;
				OBJ.cur_sphere = -1;
			}
		}
}

static void		gi_cyl(t_env *env, t_ray ray, float *t, float *ref_dist)
{
	int			i;
	float		t3;
	t_vector	scaled;
	t_vector	nc;

	i = -1;
	t3 = *t;
	OBJ.cur_cyl = -1;
	while (++i < OBJ.num_cyl)
		if (intersect_ray_cylinder(&ray, &CYLINDERS[i], &t3))
		{
			scaled = vector_scale(t3, &ray.dir);
			nc = vector_add(&ray.start, &scaled);
			CYLINDERS[i].shape.dist = vector_dist(&nc, &ray.start);
			if (CYLINDERS[i].shape.dist < *ref_dist)
			{
				*t = t3;
				*ref_dist = CYLINDERS[i].shape.dist;
				OBJ.cur_cyl = i;
				OBJ.cur_sphere = -1;
				OBJ.cur_tri = -1;
			}
		}
}

static void		gi_cone(t_env *env, t_ray ray, float *t, float *ref_dist)
{
	int			i;
	float		t4;
	t_vector	scaled;
	t_vector	nc;

	i = -1;
	t4 = *t;
	OBJ.cur_cone = -1;
	while (++i < OBJ.num_cone)
		if (intersect_ray_cone(&ray, &CONES[i], &t4))
		{
			scaled = vector_scale(t4, &ray.dir);
			nc = vector_add(&ray.start, &scaled);
			CONES[i].shape.dist = vector_dist(&nc, &ray.start);
			if (CONES[i].shape.dist < *ref_dist)
			{
				*t = t4;
				*ref_dist = CONES[i].shape.dist;
				OBJ.cur_cone = i;
				OBJ.cur_sphere = -1;
				OBJ.cur_tri = -1;
				OBJ.cur_cyl = -1;
			}
		}
}

/*
** Get shape intersections with ray - sets values for closest one.
*/

void			get_intersections(t_env *env, t_ray ray, float *t)
{
	float	ref_dist;

	ref_dist = 3.402823e+38;
	gi_sphere(env, ray, t, &ref_dist);
	gi_tri(env, ray, t, &ref_dist);
	gi_cyl(env, ray, t, &ref_dist);
	gi_cone(env, ray, t, &ref_dist);
}
