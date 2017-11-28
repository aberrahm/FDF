/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:48:58 by aberrahm          #+#    #+#             */
/*   Updated: 2017/01/07 16:58:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest == src)
		return (dest);
	if ((dest < src) || (dest > (void*)((unsigned long)src + len)))
		return (ft_memcpy(dest, src, len));
	while (len--)
		((unsigned char*)(dest))[len] = ((const unsigned char *)(src))[len];
	return (dest);
}
