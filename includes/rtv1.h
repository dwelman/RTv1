/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:09:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/13 06:58:15 by ddu-toit         ###   ########.fr       */
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
# define OBJ env->obj
# define SPHERES env->obj.spheres
# define CYLINDERS env->obj.cylinders
# define TRI env->obj.triangles
# define SP_POS(X) SPHERES[X].shape.pos
# define TR_POS(X) TRI[X].shape.pos
# define CYL_POS(X) CYLINDERS[X].shape.pos
# define ABSV(X) sqrt(vector_dot(&X, &X))
# define SQR(X) (X * X)

enum
{
	SPHERE = 1,
	TRIANGLE
};

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
	t_cylinder	*cylinders;
	int			num_cyl;
	int			cur_cyl;
	t_material	cur_mat;
	t_vector	normal;
	t_vector	new_start;
	t_col		col;
	float		ref_dist;
	int			active_shape;
	int			o;
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

typedef struct	s_ray_tri
{
	float		d;
	float		inv_d;
	double		u;
	double		v;
	double		tmp;
	t_vector	e1;
	t_vector	e2;
	t_vector	s1;
	t_vector	s2;
	t_vector	s3;
}				t_ray_tri;

void			print_vector(char *des, t_vector v);

void			mlx_image_put_pixel(void *mlx, t_img *i, t_vector p,
		t_col *c);

void			set_tri_pos(t_triangle *tri);

int				key_hook(int keycode, t_env *env);

int				close_window(t_env *env);

void			sphere_raytrace(t_env *env);

/*
** File Input
*/

void			fill_materials(t_env *env, int fd);

void			fill_lights(t_env *env, int fd);

void			fill_spheres(t_env *env, int fd);

void			fill_triangles(t_env *env, int fd);

void			fill_cylinders(t_env *env, int fd);

void			get_input(t_env *env, char *file);

/*
** Primitive Intersection & raytracing
*/

void  			calc_lighting(t_env *env, float coef);

void			raytrace(t_env *env);

int				intersect_ray_sphere(t_ray *ray, t_sphere *sphere, float *t);

int				intersect_ray_cylinder(t_ray *ray, t_cylinder *cyl, float *t);

int				intersect_ray_tri(t_ray *r, t_triangle *tri, float *res, t_vector *n);

/*
** Light & shadows
*/

int				sh_spheres(t_env *env, t_ray *light_ray, float t);

int				sh_tri(t_env *env, t_ray *light_ray, float t);

int				sh_cylinder(t_env *env, t_ray *light_ray, float t);

#endif
