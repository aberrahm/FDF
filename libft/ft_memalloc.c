/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:44:19 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/27 19:05:58 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	po;

	po = 0;
	if (!(ptr = malloc(size)))
		return (NULL);
	while (po < size)
	{
		ptr[po] = 0;
		po++;
	}
	return (ptr);
}
