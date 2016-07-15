/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_trace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:02:18 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/15 19:31:01 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	intersect_ray_line(t_ray *ray, t_vector *v, t_vector *p)
{
	t_vector	dp;
	t_vector	dv;
	t_vector	ret;

	dp = vector_sub(&ray->start, p);
	dv = vector_sub(v, &ray->dir);
	ret = vector_div(&dp, &dv);
	return (ret);
}

/*
** Determine whether ray intersects with cone by substiting ray equation
** in cone equation
*/

int	intersect_ray_cone(t_ray *ray, t_cone *cone, float *t)
{
	t_ray_sphere rs;

	rs.dist = vector_sub(&cone->center, &ray->start);
	rs.a = SQR(ray->dir.x) + SQR(ray->dir.z) - SQR(ray->dir.y);
	rs.b = (2 * ray->dir.x * rs.dist.x) + (2 * ray->dir.z * rs.dist.z)
		- (2 * ray->dir.y * rs.dist.y);
	rs.c = SQR(rs.dist.x) + SQR(rs.dist.z) - SQR(rs.dist.y);
	rs.discr = SQR(rs.b) - (4 * rs.a * rs.c);
	if (rs.discr < 0)
		return (0);
	else
	{
		rs.t0 = (rs.b - sqrt(rs.discr)) / (2 * rs.a);
		rs.t1 = (rs.b + sqrt(rs.discr)) / (2 * rs.a);
		if (rs.t0 > rs.t1 && rs.t1 > 0)
			rs.t0 = rs.t1;
		if ((rs.t0 > 0.001) && (rs.t0 < *t))
		{
			*t = rs.t0;
			return (1);
		}
		else
			return (0);
	}
}

/*
** Determine whether ray intersects with cylinder by substiting ray equation
** in cylinder equation
*/


int	intersect_ray_cylinder(t_ray *ray, t_cylinder *cyl, float *t)
{
	t_ray_sphere rs;
	t_vector 	a;
	t_vector	b;
	t_vector	del_p;

	a = vector_scale(vector_dot(&V, &VA), &VA);
	a = vector_sub(&V, &a);
	rs.a = VEC_SQR(&a);
	del_p = vector_sub(&P, &PA);
	b = vector_scale(vector_dot(&del_p, &VA), &VA);
	b = vector_sub(&del_p, &b);
	rs.b = 2.0f * vector_dot(&a, &b);
	rs.c = VEC_SQR(&b) - SQR(cyl->radius);
	rs.discr = SQR(rs.b) - (4 * rs.a * rs.c);
//	printf("a = %f b = %f c = %f", rs.a, rs.b, rs.c);
//	printf("disc = %f\n", rs.discr);
	if (rs.discr < 0)
		return (0);
	else
	{
		rs.t0 = (-1.0f * rs.b - sqrt(rs.discr)) / (2 * rs.a);
		rs.t1 = (-1.0f * rs.b + sqrt(rs.discr)) / (2 * rs.a);
	//	printf("t0 = %f t2 = %f", rs.t0, rs.t1);
		if (rs.t0 > rs.t1 && rs.t1 > 0)
			rs.t0 = rs.t1;
		if ((rs.t0 > 0.001) && (rs.t0 < *t))
		{
			*t = rs.t0;
			return (1);
		}
		else
			return (0);
	}
}

/*int	intersect_ray_cylinder(t_ray *ray, t_cylinder *cyl, float *t)
{
	t_ray_sphere rs;

	rs.dist = vector_sub(&cyl->center, &ray->start);
	rs.a = SQR(ray->dir.x) + SQR(ray->dir.z);
	rs.b = (2 * ray->dir.x * rs.dist.x) + (2 * ray->dir.z * rs.dist.z);
	rs.c = SQR(rs.dist.x) + SQR(rs.dist.z) - SQR(cyl->radius);
	rs.discr = SQR(rs.b) - (4 * rs.a * rs.c);
	if (rs.discr < 0)
		return (0);
	else
	{
		rs.t0 = (rs.b - sqrt(rs.discr)) / (2 * rs.a);
		rs.t1 = (rs.b + sqrt(rs.discr)) / (2 * rs.a);
		if (rs.t0 > rs.t1 && rs.t1 > 0)
			rs.t0 = rs.t1;
		if ((rs.t0 > 0.001) && (rs.t0 < *t))
		{
			*t = rs.t0;
			return (1);
		}
		else
			return (0);
	}
}*/

/*
** Determine whether ray intersects with sphere by substiting ray equation
** in sphere equation
*/

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

/*
** Uses triangle - plane intersection algorith to determine if a ray hits
** the plane.
*/

int	intersect_ray_tri(t_ray *ray, t_triangle *tri, float *res, t_vector *n)
{
	t_ray_tri	r;

	r.e1 = vector_sub(&tri->v2, &tri->v1);
	r.e2 = vector_sub(&tri->v3, &tri->v1);
	r.s1 = vector_cross(&ray->dir, &r.e2);
	r.d = vector_dot(&r.e1, &r.s1);
	if (r.d > -0.000001 && r.d < 0.000001)
		return (0);
	r.inv_d = 1 / r.d;
	r.s2 = vector_sub(&ray->start, &tri->v1);
	r.u = vector_dot(&r.s2, &r.s1) * r.inv_d;
	if (r.u < 0 || r.u > 1)
		return (0);
	r.s3 = vector_cross(&r.s2, &r.e1);
	r.v = vector_dot(&ray->dir, &r.s3) * r.inv_d;
	if (r.v < 0 || (r.u + r.v) > 1)
		return (0);
	r.tmp = vector_dot(&r.e2, &r.s3) * r.inv_d;
	if (r.tmp < 0.000001)
		return (0);
	*res = r.tmp - 0.05;
	*n = vector_cross(&r.e2, &r.e1);
	return (1);
}
