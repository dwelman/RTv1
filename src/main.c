/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:32:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/14 15:17:35 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <libc.h>

int	temp(t_env *env, int x, int y)
{
	ft_printf("derp");
	void	*ffs;

	printf("Mouse event x = %d y = %d\n",  x, y);
	ffs = env->win;
	return (1);
}

int	main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
	{
		ft_printf("Please include a scene file\n");
		return (0);
	}
	get_input(&env, argv[1]);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "rtv1");
	env.img.img = mlx_new_image(env.mlx, WIN_X, WIN_Y);
	env.img.data = mlx_get_data_addr(env.img.img, &env.img.bpp,
	&env.img.s, &env.img.e);
	raytrace(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, temp, &env);
	mlx_hook(env.win, 17, 0L, &close_window, &env);
	mlx_loop(env.mlx);
	return (0);
}
