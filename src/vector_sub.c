/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:26:31 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/04 09:59:13 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** Subtract two vectors and return the resulting vector
*/

t_vector	vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector	ret;

	ret = new_vector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (ret);
}
