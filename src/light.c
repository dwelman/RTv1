/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:19:55 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/11 08:45:28 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		check_in_shadow(t_env *env, float t, t_vector dist, t_ray *light_ray)
{
	int		in_shadow;
	int		k;
	t_vector	n;

	light_ray->start = OBJ.new_start;
	light_ray->dir = vector_scale((1 / t), &dist);
	k = 0;
	in_shadow = 0;
	while (k < env->obj.num_spheres)
	{
		if (intersect_ray_sphere(light_ray, &OBJ.spheres[k], &t))
		{
			in_shadow = 1;
			break;
		}
		k++;
	}
	k = 0;
	while (k < env->obj.num_tri)
	{
		if (intersect_ray_tri(light_ray, &TRI[k], &t, &n))
		{
			in_shadow = 1;
			break;
		}
		k++;
	}
	return (in_shadow);
}

void	lambert_diffuse(t_env *env, float coef, t_ray light_ray, int j)
{
	double	lam;

	lam = vector_dot(&light_ray.dir, &OBJ.normal) * coef;
	OBJ.col.r += lam * OBJ.lights[j].intensity.r * OBJ.cur_mat.diffuse.r;
	OBJ.col.g += lam * OBJ.lights[j].intensity.g * OBJ.cur_mat.diffuse.g;
	OBJ.col.b += lam * OBJ.lights[j].intensity.b * OBJ.cur_mat.diffuse.b;
}

void	calc_lighting(t_env *env, float coef)
{
	int			j;
	t_vector	dist;
	t_ray		light_ray;
	float		t;

	
	j = 0;
	while (j < OBJ.num_lights)
	{
		dist = vector_sub(&OBJ.lights[j].pos, &OBJ.new_start);
		if (vector_dot(&OBJ.normal, &dist) <= 0.0f)
		{
			j++;
			continue ;
		}
		t = sqrtf(vector_dot(&dist, &dist));
		if (t <= 0.0f)
		{
			j++;
			continue ;
		}
		if (check_in_shadow(env, t, dist, &light_ray) == 0)
			lambert_diffuse(env, coef, light_ray, j);
		j++;
	}
}
