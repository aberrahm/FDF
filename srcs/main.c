/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:44:25 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/04 01:03:27 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_all	ft_norme(char *line, int *tab, t_list *tmp, int fd)
{
	t_all	img1;

	ft_memset(&img1, 0, sizeof(t_all));
	while (get_next_line(fd, &line) > 0)
	{
		tab = recup_map(line);
		if (!img1.startlst)
		{
			img1.startlst = ft_lstnew((void const*)tab,
					(tab[0] + 1) * sizeof(int));
			tmp = img1.startlst;
		}
		else
		{
			tmp->next = ft_lstnew((void const*)tab,
					(tab[0] + 1) * sizeof(int));
			tmp = tmp->next;
		}
		img1.size_map.y++;
		if (img1.size_map.x < tab[0])
			img1.size_map.x = tab[0];
		ft_memdel((void*)&tab);
	}
	return (img1);
}

int				main(int ac, char **av)
{
	int		fd;
	t_all	img1;

	if (ac > 1 && av[1])
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("error : invalid file\n");
			return (-1);
		}
		img1 = ft_norme(NULL, NULL, NULL, fd);
		create_img(&img1);
		ft_trace_map(img1.startlst, &img1);
		call_ft(img1);
	}
	return (0);
}
