/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_trace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 09:04:13 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/05 15:20:07 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	intersect_ray_cylinder(t_ray *ray, t_sphere *sphere, float *t)
{
	t_ray_sphere	rs;

	rs.a = vector_dot(&ray->dir, &ray->dir);
	rs.dist = vector_sub(&ray->start, &sphere->shape.pos);
	rs.b = 2 * vector_dot(&ray->dir, &rs.dist);
	rs.c = vector_dot(&rs.dist, &rs.dist) - 1;
	rs.discr = rs.b * rs.b - (4 * rs.a * rs.c);
	if (rs.discr < 0)
		return (0);
	else
	{
		rs.sqrtdiscr = sqrtf(rs.discr);
		rs.t0 = (-rs.b + rs.sqrtdiscr) / 2 * rs.a;
		rs.t1 = (-rs.b - rs.sqrtdiscr) / 2 * rs.a;
		if (rs.t0 > rs.t1)
		{
			//float	y0 = ray->start.y + rs.t0 * ray->dir.y;
			//float	y1 = ray->start.y + rs.t1 * ray->dir.y;
			rs.t0 = rs.t1;
		}
		if ((rs.t0 > 0.001f) && (rs.t0 < *t))
		{
			*t = rs.t0;
			return (1);
		}
		else
			return (0);
	}
}

int	intersect_ray_sphere(t_ray *ray, t_sphere *sphere, float *t)
{
	t_ray_sphere	rs;

	rs.a = vector_dot(&ray->dir, &ray->dir);
	rs.dist = vector_sub(&ray->start, &sphere->shape.pos);
	rs.b = 2 * vector_dot(&ray->dir, &rs.dist);
	rs.c = vector_dot(&rs.dist, &rs.dist) - (sphere->radius * sphere->radius);
	rs.discr = rs.b * rs.b - (4 * rs.a * rs.c);
	if (rs.discr < 0)
		return (0);
	else
	{
		rs.sqrtdiscr = sqrtf(rs.discr);
		rs.t0 = (-rs.b + rs.sqrtdiscr) / 2;
		rs.t1 = (-rs.b - rs.sqrtdiscr) / 2;
		if (rs.t0 > rs.t1)
			rs.t0 = rs.t1;
		if ((rs.t0 > 0.001f) && (rs.t0 < *t))
		{
			*t = rs.t0;
			return (1);
		}
		else
			return (0);
	}
}
