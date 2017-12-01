/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:03:50 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/01 22:12:08 by aberrahm         ###   ########.fr       */
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


t_xy	ft_iso1(t_xy posfdf)
{
	int		a;

	a = posfdf.x;
	posfdf.x = (posfdf.x + posfdf.y) * 4;
	posfdf.y = ((posfdf.y - a) * 4) - posfdf.z * 2;
	posfdf.x += 300;
	posfdf.y += 825;
	return (posfdf);
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
				create_line(pos, ft_iso1(start), ft_iso1(end), 0x00cccc);
			}
			if (map->next && map->next->content 
					&& ((int*)map->next->content)[0] > start.x)
			{
				end.x = start.x;
				end.y = start.y + 1;
				start.z = ((int*)map->content)[start.x + 1];
				end.z = ((int*)map->content)[end.x + 1];
				create_line(pos, ft_iso1(start), ft_iso1(end), 0xcccc00);
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
