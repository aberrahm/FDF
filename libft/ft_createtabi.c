/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtabi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 02:14:15 by aberrahm          #+#    #+#             */
/*   Updated: 2017/11/26 10:52:58 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_createtabi(int cl, int lg)
{
	int		**dest;

	if (!(dest = (int **)malloc(sizeof(int *) * (lg + 1))))
		return (NULL);
	while (lg >= 0)
	{
		if (!(dest[lg] = (int *)malloc(sizeof(int) * (cl + 1))))
			return (NULL);
		ft_memset(dest[lg], '\0', cl + 1);
		lg--;
	}
	return (dest);
}
