/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:44:25 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/01 21:53:47 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		*tab;
	t_all	img1;
	t_list	*start;
	t_list	*tmp;

	start = NULL;
	if (ac > 1 && av[1])
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("error : invalid file\n");
			return (-1);
		}
		while (get_next_line(fd, &line) > 0)
		{
			tab = recup_map(line);
			if (!start)
			{
				start = ft_lstnew((void const*)tab, (tab[0] + 1) * sizeof(int));
				tmp = start;
			}
			else
			{
				tmp->next = ft_lstnew((void const*)tab, (tab[0] + 1) * sizeof(int));
				tmp = tmp->next;
			}
			//ft_memdel((void*)tab);
		}
		create_img(&img1);
		ft_putendl("pouet");
		ft_trace_map(start, &img1);
		ft_putendl("pouet");
		call_ft(img1);
	}
	return (0);
}
