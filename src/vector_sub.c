/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:26:31 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/04 08:50:15 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

/*
** Subtract two vectors and return the resulting vector
*/

t_vector	vector_sub(t_vector *v1, vector *v2)
{
	t_vector	ret;

	ret = new_vector(v1->x - v2->x, v1-y - v2->y, v1->z - v2->z);
	return (ret);
}
