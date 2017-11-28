/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:11:03 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 07:02:31 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		p;
	int		i;
	int		g;
	char	*big1;

	big1 = (char *)big;
	p = 0;
	if (little[p] == '\0')
		return (big1);
	while (big1[p] != '\0')
	{
		i = 0;
		g = p;
		while (big1[p] == little[i])
		{
			if (little[i++])
				p++;
			if (little[i] == '\0')
			{
				return (&big1[g]);
			}
		}
		p = g + 1;
	}
	return (NULL);
}
