/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:31:19 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/04 08:49:10 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

/*
** Creates a new t_vector and returns a pointer to it.
*/

t_vector	*new_vector(float x, float y, float z)
{
	t_vector	*new;

	new = (t_vector*)malloc(sizeof(t_vector));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
