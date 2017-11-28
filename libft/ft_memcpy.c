/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:39:33 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/28 01:23:34 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			p;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	p = 0;
	while (p < n)
	{
		dest1[p] = src1[p];
		p++;
	}
	return (dest);
}
