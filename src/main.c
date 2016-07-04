/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:32:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 10:58:30 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	intersect_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	t_vector	dist;

	a = vector_dot(&ray->dir, &ray->dir);
	dist = vector_sub(&ray->start, &sphere->shape.pos);
	b = 2 * vector_dot(&ray->dir, &dist);
	c = vector_dot(&dist, &dist) - (sphere->radius * sphere->radius);
	discr = b * b - (4 * a * c);
	if (discr < 0)
		return (0);
	else
		return (1);
}

int	main(void)
{
	/*t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "RTv1");*/
	t_sphere	sphere;
	t_ray		ray;
	int			x;
	int			y;
	int			hit;

	sphere.shape.pos.x = 20;
	sphere.shape.pos.y = 20;
	sphere.shape.pos.z = 20;
	sphere.radius = 10;
	ray.dir.x = 0;
	ray.dir.y = 0;
	ray.dir.z = 1;

	ray.start.z = 0;
	y = 0;
	while (y < 40)
	{
		ray.start.y = y;
		x = 0;
		while (x < 40)
		{
			ray.start.x = x;
			hit = intersect_ray_sphere(&ray, &sphere);
			if (hit)
				ft_printf("++");
			else
				ft_printf("--");
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
