/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:09:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/07 09:59:13 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "vector.h"
# include "colours.h"
# include"light.h"
# include "../libft/libft.h"
# define WIN_X 800
# define WIN_Y 600
# define EXIT 53

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			s;
	int			e;
	char		id;
	int			x;
	int			y;
}				t_img;

typedef struct	s_obj
{
	int			num_mats;
	t_material	*mats;
	int			num_lights;
	t_light		*lights;
	int			num_spheres;
	t_sphere	*spheres;
	int			num_tri;
	t_triangle	*triangles;
	int			cur_sphere;
	int			cur_tri;
}				t_obj;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_obj		obj;
}				t_env;

typedef struct	s_ray_sphere
{
	float		a;
	float		b;
	float		c;
	float		sqrtdiscr;
	float		t0;
	float		t1;
	float		discr;
	t_vector	dist;
}				t_ray_sphere;

void			mlx_image_put_pixel(void *mlx, t_img *i, t_vector p,
		t_col *c);

int				key_hook(int keycode, t_env *env);

int				close_window(t_env *env);

void			sphere_raytrace(t_env *env);

int				intersect_ray_sphere(t_ray *ray, t_sphere *sphere, float *t);

/*
** File Input
*/

void			fill_materials(t_env *env, int fd);

void			fill_lights(t_env *env, int fd);

void			fill_spheres(t_env *env, int fd);

void			fill_triangles(t_env *env, int fd);

void			get_input(t_env *env, char *file);

/*
** Primitive Intersection
*/

int				intersect_ray_cylinder(t_ray *ray, t_sphere *sphere, float *t);

int				intersect_ray_tri(t_ray *r, t_triangle *tri, double *res, t_vector *n);

#endif
