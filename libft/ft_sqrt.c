/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 04:49:04 by aberrahm          #+#    #+#             */
/*   Updated: 2017/01/04 23:30:42 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		count;
	int		countbis;
	int		countri;

	count = 1;
	countbis = 1;
	countri = 1;
	while (countri != nb)
	{
		count = count + 2;
		countri = countri + count;
		countbis++;
		if (countri > nb)
			return (0);
	}
	return (countbis);
}
