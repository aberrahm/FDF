/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:08:42 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/04 03:12:13 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key_hook(int keycode, t_all *pos)
{
	if (keycode == K_ESC)
	{
		ft_putstr("fdf closed\n");
		exit(0);
	}
	else if (keycode == K_LEFT || keycode == K_RIGHT
			|| keycode == K_RISE || keycode == K_DOWN)
	{
		if (keycode == K_LEFT)
			pos->translate.x -= 10;
		else if (keycode == K_RIGHT)
			pos->translate.x += 10;
		else if (keycode == K_RISE)
			pos->translate.y -= 10;
		else if (keycode == K_DOWN)
			pos->translate.y += 10;
		ft_memset((void*)pos->data, 0, pos->width * pos->height * sizeof(int));
		ft_trace_map(pos->startlst, pos);
		mlx_put_image_to_window(pos->mlx_ptr,
				pos->win_ptr, pos->img_ptr, 0, 0);
	}
	return (0);
}

int		ft_key_exit(int keycode, t_all *pos)
{
	exit(keycode);
	return ((int)pos);
}

void	call_ft(t_all img1)
{
	mlx_put_image_to_window(img1.mlx_ptr, img1.win_ptr, img1.img_ptr, 0, 0);
	mlx_hook(img1.win_ptr, 2, 1L << 8, ft_key_hook, (void*)&img1);
	mlx_hook(img1.win_ptr, 17, 1L << 17, ft_key_exit, (void*)&img1);
	mlx_loop(img1.mlx_ptr);
}
