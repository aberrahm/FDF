/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:21:08 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 06:22:46 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_putnbr_in_tab(int n, int cpy, int signe)
{
	char	*stock;

	if (!(stock = (char *)malloc(sizeof(char) * (cpy + 1))))
		return (NULL);
	if (n == 0)
	{
		stock[0] = '0';
		stock[1] = '\0';
	}
	else
		stock[cpy] = '\0';
	cpy--;
	while (n != 0)
	{
		stock[cpy] = n % 10 + '0';
		n = n / 10;
		cpy--;
	}
	if (signe == 1)
		stock[0] = '-';
	return (stock);
}

char			*ft_itoa(int n)
{
	int			i;
	int			signe;
	int			cpy;

	i = 0;
	signe = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		signe = 1;
		n = -n;
	}
	cpy = n;
	while (cpy != 0)
	{
		cpy = cpy / 10;
		i++;
	}
	cpy = (n == 0 ? 1 : i + signe);
	return (ft_putnbr_in_tab(n, cpy, signe));
}
