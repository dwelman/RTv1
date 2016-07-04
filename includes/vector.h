/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:31:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 13:17:41 by ddu-toit         ###   ########.fr       */
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
	int			mat_id;
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

float			vector_dot(t_vector *v1, t_vector *v2);

t_vector		new_vector(float x, float y, float z);

t_vector		vector_sub(t_vector *v1, t_vector *v2);

t_vector        vector_add(t_vector *v1, t_vector *v2);

t_vector        vector_scale(float c, t_vector *v);

#endif
