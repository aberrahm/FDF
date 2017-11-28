/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:03:50 by aberrahm          #+#    #+#             */
/*   Updated: 2017/11/26 22:49:37 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int       recup_map(char *line, t_all img1)
{

    int     i;
    char    **tab;

    i = 0;
    tab = ft_strsplit(line, ' ');
    while (tab[img1.coord.x] != '\0')
    {
        img1.coord.z = atoi(tab[img1.coord.x]);
        img1.coord.x++;
        ft_putnbr(img1.coord.x);
		//tab = ft_createtab(img1.coord.y, img1.coord.x);
    }
    ft_putchar('\n');
	return (img1.coord.z);
    //recuperer le tableau de put in tab
    //recuperer l'int de la fonction qui va etre utilise dans le main
}

