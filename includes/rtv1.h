/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:09:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 11:26:22 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "vector.h"
# include "colour.h"
# include "../libft/libft.h"
# define WIN_X 640
# define WIN_Y 420

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

void	mlx_image_put_pixel(void *mlx, t_img *i, t_coordint p, t_col *c);

#endif
