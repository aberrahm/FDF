/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:09:07 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 06:29:56 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		size;
	size_t		c;

	if (!s || !f)
		return ;
	size = ft_strlen(s);
	c = 0;
	while (c < size)
	{
		f(c, &s[c]);
		c++;
	}
}
