/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 04:09:03 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 06:28:34 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t		size;
	size_t		c;

	if (!s)
		return ;
	size = ft_strlen(s);
	c = 0;
	while (c < size)
	{
		s[c] = '\0';
		c++;
	}
}
