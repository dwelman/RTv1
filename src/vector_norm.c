/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:03:07 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/15 13:11:47 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	vector_norm(t_vector *v)
{
	float	m;

	m = sqrt(SQR(v->x) + SQR(v->y) + SQR(v->z));
	v->x /= m;
	v->y /= m;
	v->z /= m;
	return (*v);
}