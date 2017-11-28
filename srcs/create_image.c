/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:23:41 by aberrahm          #+#    #+#             */
/*   Updated: 2017/07/08 10:51:51 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_img(t_all *img)
{
	img->size_win_x = 1900;
	img->size_win_y = 1300;
	img->width = 1900;
	img->height = 1300;
	img->mlx_ptr = mlx_init();
	img->img_ptr = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->size_win_x,
			img->size_win_y, "fdf");
	img->img_win = mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
			img->img_ptr, 0, 0);
}

void	my_pixel_put(t_all *data, int x, int y, uint32_t color)
{
	uint32_t	*pixel;

	if (x < 0 || x >= 1900 || y < 0 || y >= 1300)
		return ;
	pixel = (uint32_t*)(data->data + x * data->bpp / 8 + y * data->sizeline);
	*pixel = color;
}
