/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:31:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 08:37:01 by daviwel          ###   ########.fr       */
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

#endif
