/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:44:25 by aberrahm          #+#    #+#             */
/*   Updated: 2017/11/26 22:49:39 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	int		test;
	char	*line;
	t_all	img1;
	int		i;

	img1.coord.y = 0;
	if (ac > 1 && av)
	{
		fd = open(av[1], O_RDONLY);
		while (fd > 0 && (i = get_next_line(fd, &line) != 0))
		{
			test = recup_map(line, img1);
		//	ft_putnbr(img1.coord.x);
		//	ft_putnbr(test);
		//	ft_putnbr(img1.coord.z);
		}
		if (fd <= 0)
		{
			ft_putstr("error : invalid file\n");
			return (-1);
		}
		create_img(&img1);
	}
	return (0);
}
