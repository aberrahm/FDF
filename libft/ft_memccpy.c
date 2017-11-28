/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:50:54 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 07:26:57 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			p;
	unsigned char	i;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	i = (unsigned char)c;
	p = 0;
	while (p < n)
	{
		dest1[p] = src1[p];
		if (src1[p] == i)
			return (&dest[p + 1]);
		p++;
	}
	return (NULL);
}
