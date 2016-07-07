/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 13:46:59 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/06 16:41:17 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	intersect_ray_tri(t_ray *r, t_triangle *tri, double *res, t_vector *n)
{
	float		d;
	float		inv_d;
	double		u;
	double		v;
	double		tmp;
	t_vector	e1;
	t_vector	e2;
	t_vector	s1;
	t_vector	s2;
	t_vector	s3;

	e1 = vector_sub(&tri->v2, &tri->v1);//direction vectors?
	e2 = vector_sub(&tri->v3, &tri->v1);
	s1 = vector_cross(&r->dir, &e2); //cross product
	d = vector_dot(&e1, &s1); //determinant
	if (d > -0.000001 && d < 0.000001)
		return (0);//ray perpendicular
	inv_d = 1 / d;
	s2 = vector_sub(&r->start, &tri->v1);
	u = vector_dot(&s2, &s1) * inv_d;
	if (u < 0 || u > 1)
		return (0);
	s3 = vector_cross(&s2, &e1);
	v = vector_dot(&r->dir, &s3) * inv_d;
	if (v < 0 || (u + v) > 1)
		return (0);
	tmp = vector_dot(&e2, &s3) * inv_d;
	if (tmp < 0.000001)
		return (0);
	*res = tmp - 0.005;
	*n = vector_cross(&e2, &e1);
	return (1);
}
