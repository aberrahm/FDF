/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:03:50 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/02 00:37:43 by aberrahm         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int *recup_map(char *line)
{

	int lent;
	char **tab;
	int  *tabz;

	lent = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[lent] != NULL)
	{
		lent++;
	}
	tabz = (int *)ft_memalloc(sizeof(int) * (lent + 1));
	tabz[0] = lent;
	lent = 0;
	while (tab[lent] != NULL)
	{
		tabz[lent + 1] = atoi(tab[lent]);
		lent++;
	}
	lent = 0;
	//while (tab[lent])
	//ft_strdel(&tab[lent++]);
	//ft_memdel((void**)tab);
	//ft_strdel(&line);
	return (tabz);
}


t_xy	ft_resize_map(t_all *pos, t_xy dot)
{
	static t_xy		resize;
	static t_xy		margin;
	static int		done;

	if (done == 0)
	{
		resize.x = pos->size_win_x / (float)(pos->size_map.x + 1);
		resize.y = pos->size_win_y / (float)(pos->size_map.y + 1);
		if (resize.y <= 0 || resize.x <= 0)
		{
			resize.x = 1;
			resize.y = 1;
		}
		if (resize.x > resize.y)
			resize.x = resize.y;
		else
			resize.y = resize.x;
		margin.x = pos->size_win_x - (pos->size_map.x - 1) * resize.x;
		margin.y = pos->size_win_y - (pos->size_map.y - 1) * resize.y;
		done = 1;
	}
	resize.z = dot.x;
	dot.x = dot.x + dot.y;
	dot.y = (dot.y - resize.z) - dot.z;
	dot.x *= resize.x / 2.0;
	dot.y *= resize.y / 2.0;
	dot.x += margin.x / 2.0;
	dot.y += margin.y / 2.0;
	return (dot);
}

void	ft_trace_map(t_list *map, t_all *pos)
{
	t_xy	start;
	t_xy	end;

	start.y = 0;
	while (map)
	{
		start.x = 0;
		while (map->content && ((int*)map->content)[0] > start.x)
		{
			if (((int*)map->content)[0] > start.x + 1)
			{
				end.x = start.x + 1;
				end.y = start.y;
				start.z = ((int*)map->content)[start.x + 1];
				end.z = ((int*)map->content)[end.x + 1];
				//mettre fonction qui va remplacer iso (+propre)
				create_line(pos, ft_resize_map(pos, start),
						ft_resize_map(pos, end), 0x0000cc);
			}
			if (map->next && map->next->content 
					&& ((int*)map->next->content)[0] > start.x)
			{
				end.x = start.x;
				end.y = start.y + 1;
				start.z = ((int*)map->content)[start.x + 1];
				end.z = ((int*)map->next->content)[end.x + 1];
				create_line(pos, ft_resize_map(pos, start),
						ft_resize_map(pos, end), 0xcc0000);
			}
			start.x++;
		}
		start.y++;
		map = map->next;
	}
}

void call_ft(t_all img1)
{
	//ft_trace_map(&img1, tab, img1.recup);
	mlx_put_image_to_window(img1.mlx_ptr, img1.win_ptr, img1.img_ptr, 0, 0);
	mlx_key_hook(img1.win_ptr, ft_key_hook, 0);
	mlx_loop_hook(img1.mlx_ptr, temp_quit, NULL);
	mlx_loop(img1.mlx_ptr);
}
