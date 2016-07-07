/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_raytrace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 08:51:47 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/07 07:00:46 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	sphere_raytrace(t_env *env)
{
	int		x;
	int		y;
	t_ray	ray;
	t_col	col;
	int		level;
	float	coef;
	t_triangle	tri;

	tri.v1.x = 70;
	tri.v1.y = 70;
	tri.v1.z = -1;
	tri.v2.x = 70;
	tri.v2.y = 200;
	tri.v2.z = -1;
	tri.v3.x = 200;
	tri.v3.y = 135;
	tri.v3.z = -1;
	tri.shape.material = 1;

/*	double   t = 20000.0f;
	t_vector 	n;
	y = 0;
	ray.dir.x = 0;
    ray.dir.y = 0;
    ray.dir.z = 1; 
    ray.start.z = -10;
	while (y <= 50)
	{
		x = 0;
		ft_printf("%d\t", y);
		while (x <= 50)
		{
    		ray.start.y = y;
			ray.start.x = x;
			if (intersect_ray_tri(&ray, &tri, &t, &n))
			{
				ft_printf("++");
			//	ft_printf("x = %d y = %d\n", x , y);
			}
			else
				ft_printf("--");
			x++;
		}
		ft_printf("\n");
		y++;
	}
*/

	y = 0;
    while (y <= WIN_Y)
    {
        x = 0;
        while (x <= WIN_X)
        {
            col.r = 0;
            col.g = 0;
            col.b = 0;
            level = 0;
            coef = 1.0;

            ray.start.x = x;
            ray.start.y = y;
            ray.start.z = -2000;
            ray.dir.x = 0;
            ray.dir.y = 0;
            ray.dir.z = 1;
            while (coef > 0.0f && level < 15)
            {
                float   t = 20000.0f;
                int     current_sphere = -1;
                int     i;
				double		res;
				t_vector	n;

                i = 0;
				if (intersect_ray_tri(&ray, &tri, &res, &n))
				{
            		env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)255;
            		env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)255;
            		env->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)255;
				}
                while (i < env->obj.num_spheres)
                {
					if (intersect_ray_sphere(&ray, &env->obj.spheres[i], &t))
                            current_sphere = i;
                    i++;
                }
                if (current_sphere == -1)
                    break ;
                t_vector    scaled = vector_scale(t, &ray.dir);
                t_vector    new_start = vector_add(&ray.start, &scaled);
                t_vector    normal = vector_sub(&new_start, &env->obj.spheres[current_sphere].shape.pos);
                float       temp = vector_dot(&normal, &normal);

                if (temp == 0)
                    break ;
                temp = 1.0f / sqrt(temp);
                normal = vector_scale(temp, &normal);
                t_material  current_mat = env->obj.mats[env->obj.spheres[current_sphere].shape.material];
                int j;

                j = 0;
                while (j < env->obj.num_lights)
                {
                    t_light current_light = env->obj.lights[j];
                    t_vector    dist = vector_sub(&current_light.pos, &new_start);
                    if (vector_dot(&normal, &dist) < 0.1f)
					{
						j++;
                        continue ;
					}
                    float   t = sqrtf(vector_dot(&dist, &dist));
                    if (t <= 0.0f)
					{
						j++;
						continue ;
					}
                    t_ray   light_ray;
                    light_ray.start = new_start;
                    light_ray.dir = vector_scale((1 / t), &dist);

					int		in_shadow;
					int		k;

					k = 0;
					in_shadow = 0;
					while (k < env->obj.num_spheres)
					{
						if (intersect_ray_sphere(&light_ray, &env->obj.spheres[k], &t))
						{
							in_shadow = 1;
							break;
						}
						k++;
					}
					if (in_shadow == 0)
					{
                    	float   lambert = vector_dot(&light_ray.dir, &normal) * coef;
                    	col.r += lambert* current_light.intensity.r * current_mat.diffuse.r;
                    	col.g += lambert* current_light.intensity.g * current_mat.diffuse.g;
                    	col.b += lambert* current_light.intensity.b * current_mat.diffuse.b;
					}
					j++;
                }
                coef *= current_mat.reflection;
				//printf("coef = %f\n", coef);
                ray.start = new_start;
                float   reflect = 2.0f * vector_dot(&ray.dir, &normal);
                t_vector    tmp = vector_scale(reflect, &normal);
                ray.dir = vector_sub(&ray.dir, &tmp);
                level++;
            }
            t_col temp;
            t_vector v;
            v.x =  x;
            v.y = y;
            if (col.r * 255.0f < 255.0f)
                temp.r = col.r * 255.0f;
            else
                temp.r = 255.0f;
            if (col.g * 255.0f < 255.0f)
                temp.g = col.g * 255.0f;
			else
                temp.g = 255.0f;
            if (col.b * 255.0f < 255.0f)
                temp.b = col.b * 255.0f;
            else
                temp.b = 255.0f;
			env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.r;
			env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.g;
			env->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp.b;
            x++;
        }
//		ft_printf("\n");
        y++;
    }
}
