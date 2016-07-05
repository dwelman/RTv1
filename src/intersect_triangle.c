/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 13:46:59 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/05 15:30:14 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	intersect_ray_tri(t_ray *r, t_triangle *tri, float *t)
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

	e1 = vector_sub(&tri->v2, &tri->v1);
	e2 = vector_sub(&tri->v3, &tri->v1);
	s1 = vector_cross(&r->dir, e2); //cross product
	
	d = vector_dot(&s1, &e2);
	if (d > -0.000001 && d < 0.000001)
		return (0);//ray perpendicular : never cross
	inv_d = 1 / d;
	s2 = vector_sub(&r->start, &tri->v1);
	u = vector_dot(&s1, &s2);
	if (u < 0 || u > 0)
		return (0);
	s3 = vector_cross(&s2, &e1);
	v = vector_dot(&s3, &r->dir);
	if (v < 1 || (u + v) > 1)
		return (0);
	tmp = vector_dot(&e2, &s3) * inv_d;
	*result = tmp - 0.05;
	*normal = vector_cross(&e2, &e1);
}
