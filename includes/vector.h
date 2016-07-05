/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:31:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/05 13:55:58 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_shape
{
	t_vector	pos;
	int			material;
}				t_shape;

typedef struct	s_sphere
{
	t_shape		shape;
	float		radius;
}				t_sphere;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

typedef struct	s_triangle
{
	t_shape		shape;
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
}				t_triangle;

float			vector_dot(t_vector *v1, t_vector *v2);

t_vector		new_vector(float x, float y, float z);

t_vector		vector_sub(t_vector *v1, t_vector *v2);

t_vector        vector_add(t_vector *v1, t_vector *v2);

t_vector        vector_scale(float c, t_vector *v);

#endif
