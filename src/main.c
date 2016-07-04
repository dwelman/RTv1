/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:32:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 15:22:40 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <libc.h>

int	intersect_ray_sphere(t_ray *ray, t_sphere *sphere, float *t)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	t_vector	dist;
	int			retval;

	retval = 0;
	a = vector_dot(&ray->dir, &ray->dir);
	dist = vector_sub(&ray->start, &sphere->shape.pos);
	b = 2 * vector_dot(&ray->dir, &dist);
	c = vector_dot(&dist, &dist) - (sphere->radius * sphere->radius);
	discr = b * b - (4 * a * c);
	if (discr < 0)
		retval = 0;
	else
	{
		float	sqrtdiscr = sqrtf(discr);
		float	t0 = (-b + sqrtdiscr) / 2;
		float	t1 = (-b - sqrtdiscr) / 2;

		if (t0 > t1)
			t0 = t1;

		if ((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			retval = 1;
		}
		else
			retval = 0;
	}
	return (retval);
}

int	main(void)
{
	t_env		env;
	t_ray		ray;
	int			x;
	int			y;
//	int			hit;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "rtv1");
	env.img.img = mlx_new_image(env.mlx, WIN_X, WIN_Y);
	env.img.data = mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.s, &env.img.e);

	t_material	materials[3];
	materials[0].diffuse.r = 1;
	materials[0].diffuse.g = 0;
	materials[0].diffuse.b = 0;
	materials[0].reflection = 0.2;
	
	materials[1].diffuse.r = 0;
	materials[1].diffuse.g = 1;
	materials[1].diffuse.b = 0;
	materials[1].reflection = 0.5;
	
	materials[2].diffuse.r = 0;
	materials[2].diffuse.g = 0;
	materials[2].diffuse.b = 1;
	materials[2].reflection = 1;

	t_sphere	spheres[3];
	spheres[0].shape.pos.x = 200;
	spheres[0].shape.pos.y = 300;
	spheres[0].shape.pos.z = 0;
	spheres[0].radius = 100;
	spheres[0].shape.material = 0;

	spheres[1].shape.pos.x = 400;
	spheres[1].shape.pos.y = 400;
	spheres[1].shape.pos.z = 0;
	spheres[1].radius = 100;
	spheres[1].shape.material = 1;
	
	spheres[2].shape.pos.x = 500;
	spheres[2].shape.pos.y = 140;
	spheres[2].shape.pos.z = 0;
	spheres[2].radius = 100;
	spheres[2].shape.material = 2;

	t_light	lights[3];
	lights[0].pos.x = 0;
	lights[0].pos.y = 240;
	lights[0].pos.z = -100;
	lights[0].intensity.r = 1;
	lights[0].intensity.g = 1;
	lights[0].intensity.b = 1;
	
	lights[1].pos.x = 3200;
	lights[1].pos.y = 3000;
	lights[1].pos.z = -1000;
	lights[1].intensity.r = 0.6;
	lights[1].intensity.g = 0.7;
	lights[1].intensity.b = 1;
	
	lights[2].pos.x = 600;
	lights[2].pos.y = 0;
	lights[2].pos.z = -100;
	lights[2].intensity.r = 0.3;
	lights[2].intensity.g = 0.5;
	lights[2].intensity.b = 1;

	
	y = 0;
	while (y <= WIN_Y)
	{
		ft_printf("Here\n");	
		x = 0;
		while (x <= WIN_X)
		{
			float	r = 0;
			float	g = 0;
			float	b = 0;
			int		level = 0;
			float	coef = 1.0;

			ray.dir.x = 0;
			ray.dir.y = 0;
			ray.dir.z = 1;

			ray.start.x = x;
			ray.start.y = y;
			ray.start.z = -2000;

			ray.dir.x = 0;
			ray.dir.y = 0;
			ray.dir.z = 1;
			while (coef > 0.0f && level < 15)
			{
				ft_printf("while\n");
				float	t = 20000.0f;
				int		current_sphere = -1;
				int		i;

				i = 0;
				while (i < 3)
				{
					if (intersect_ray_sphere(&ray, &spheres[i], &t))
							current_sphere = i;
					i++;
				}
				if (current_sphere == -1)
					break ;
				t_vector	scaled = vector_scale(t, &ray.dir);
				t_vector	new_start = vector_add(&ray.start, &scaled);
				t_vector	normal = vector_sub(&new_start, &spheres[current_sphere].shape.pos);
				float		temp = vector_dot(&normal, &normal);
				
				if (temp == 0)
					break ;
				temp = 1.0f / sqrt(temp);
				normal = vector_scale(temp, &normal);
				t_material	current_mat = materials[spheres[current_sphere].shape.material];
				int	j;

				j = -1;
				while (j++ < 3)
				{
					ft_printf("j");
					t_light	current_light = lights[j];
					t_vector	dist = vector_sub(&current_light.pos, &new_start);
					if (vector_dot(&normal, &dist) < 0.1f)
						continue ;
					float	t = sqrtf(vector_dot(&dist, &dist));
					if (t <= 0.0f)
					{
						continue ;
					}
					t_ray	light_ray;
					light_ray.start = new_start;
					light_ray.dir = vector_scale((1 / t), &dist);

					float	lambert = vector_dot(&light_ray.dir, &normal) * coef;
					r += lambert* current_light.intensity.r * current_mat.diffuse.r;
					g += lambert* current_light.intensity.g * current_mat.diffuse.g;
					b += lambert* current_light.intensity.b * current_mat.diffuse.b;
//					j++;
				}
				coef *= current_mat.reflection;
				ray.start = new_start;
				float	reflect = 2.0f * vector_dot(&ray.dir, &normal);
				t_vector	tmp = vector_scale(reflect, &normal);
				ray.dir = vector_sub(&ray.dir, &tmp);
				level++;
			}
			t_col temp;
			t_vector v;
			v.x =  x;
			v.y = y;
			if (r * 255.0f < 255.0f)
				temp.r = r * 255.0f;
			else
				temp.r = 255.0f;
			if (g * 255.0f < 255.0f)
				temp.g = g * 255.0f;
			else
				temp.g = 255.0f;
			if (b * 255.0f < 255.0f)
				temp.b = b * 255.0f;
			else
				temp.b = 255.0f;
			printf("x = %f y = %f\n", v.x, v.y);
		//	mlx_pixel_put(env.mlx, env.win, v.x, v.y, 42);
		//	mlx_image_put_pixel(env.mlx, env.img.img, v ,&temp);
			env.img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.r;
			env.img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.g;
			env.img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp.b;
			/*hit = intersect_ray_sphere(&ray, &sphere);
			if (hit)
				ft_printf("++");
			else
				ft_printf("--");*/
			x++;
		}
		ft_printf("OUT\n");
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0 , 0);
	mlx_loop(env.mlx);
}
