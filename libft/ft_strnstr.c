/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 04:13:31 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 07:28:32 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*big1;
	size_t		p;
	size_t		i;
	size_t		g;

	p = 0;
	big1 = (char *)big;
	if (little[p] == '\0')
		return (big1);
	while (big1[p] != '\0' && p < len)
	{
		i = 0;
		g = p;
		while (big1[p++] == little[i] && i < len && little[i])
		{
			i++;
			if (little[i] == '\0' && p - 1 < len)
				return (&big1[g]);
			else if (i > len)
				return (NULL);
		}
		p = g + 1;
	}
	return (NULL);
}
