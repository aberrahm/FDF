/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 05:02:15 by aberrahm          #+#    #+#             */
/*   Updated: 2017/11/26 10:53:16 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_createtab(int cl, int lg)
{
	char	**dest;

	if (!(dest = (char **)malloc(sizeof(char *) * (lg + 1))))
		return (NULL);
	while (lg >= 0)
	{
		if (!(dest[lg] = (char *)malloc(sizeof(char) * (cl + 1))))
			return (NULL);
		ft_memset(dest[lg], '\0', cl + 1);
		lg--;
	}
	return (dest);
}
