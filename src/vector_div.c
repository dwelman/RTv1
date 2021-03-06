/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 19:03:09 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/15 19:11:58 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	vector_div(t_vector *v1, t_vector *v2)
{
	t_vector	ret;

	ret.x = v1->x / v2->x;
	ret.y = v1->y / v2->y;
	ret.z = v1->z / v2->z;
	return (ret);
}
