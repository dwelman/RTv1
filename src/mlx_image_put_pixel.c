/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_put_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:44:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 14:46:50 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	mlx_image_put_pixel(void *mlx, t_img *i, t_vector p, t_col *c)
{
	if (i->e)
	{
		i->data[(int)(p.y * i->s + p.x * i->bpp / 8)] = mlx_get_color_value(mlx, c->r);
		i->data[(int)(p.y * i->s + p.x * i->bpp / 8 + 1)] =
		mlx_get_color_value(mlx, c->g);
		i->data[(int)(p.y * i->s + p.x * i->bpp / 8 + 2)] =
		mlx_get_color_value(mlx, c->b);
	}
	else
	{
		i->data[(int)(p.y * i->s + i->bpp / 8 * p.x)] = mlx_get_color_value(mlx, c->b);
		i->data[(int)(p.y * i->s + i->bpp / 8 * p.x + 1)] =
		mlx_get_color_value(mlx, c->g);
		i->data[(int)(p.y * i->s + i->bpp / 8 * p.x + 2)] =
		mlx_get_color_value(mlx, c->r);
	}
}
