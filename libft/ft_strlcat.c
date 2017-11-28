/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 02:30:02 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/30 02:39:17 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dest1;
	size_t		src1;
	size_t		p;
	size_t		len;

	dest1 = ft_strlen(dest);
	src1 = ft_strlen((char *)src);
	p = 0;
	len = 0;
	while (dest[p] != '\0' && p < size)
		p++;
	len = p;
	while (src[p - len] != '\0' && p + 1 < size)
	{
		dest[p] = src[p - len];
		p++;
	}
	if (len < size)
		dest[p] = '\0';
	return (len + src1);
}
